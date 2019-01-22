#include <SoftwareSerial.h>
 
void setup()
{
  Serial.begin(9600);
}
 
void loop()
{
  String command = "";
  
  //String x = "AT+CWJAP="eircom40887457","a80d07791da4"\r\n";
  
  Serial.write("AT+RST\r\n"); //Reset ESP8266 to default configurations.
  delay(1000);   //Create a delay to ensure reset in fully complete.
  //Serial.write("AT+CWJAP="eircom40887457","a80d07791da4"\r\n");
  
  //Connect to WiFi modem.
  Serial.write("AT+CWJAP=");
  Serial.write('"');
  Serial.write("eircom40887457");
  Serial.write('"');
  Serial.write(',');
  Serial.write('"');
  Serial.write("a80d07791da4");
  Serial.write('"');
  Serial.write("\r\n");
  
  
  delay(2000);
  Serial.write("AT+CWJAP?\r\n");
  
  
  //Connect to website.
  Serial.write("AT+CIPSTART=");
  Serial.write('"');
  Serial.write("TCP");
  Serial.write('"');
  Serial.write(',');
  Serial.write('"');
  Serial.write("tixgy.com");
  Serial.write('"');
  Serial.write(',');
  Serial.write("80,\r\n");
  
  //Specify number of bytes you will send.
  Serial.write("AT+CIPSEND=81\r\n");
  
  //Send GET Request.
  Serial.write("GET /DITrobot.php?param1=56&param2=23 HTTP/1.1\r\nHost: tixgy.com\r\n\r\n");
  
  //delay(2000);
  //Serial.write("AT+CWJAP?\r\n");
  

  while(Serial.available()>0){
    Serial.print((char)Serial.read());
    //command+=(char)Serial.read();
  }
  //Serial.println(command);
  while(1);
}
