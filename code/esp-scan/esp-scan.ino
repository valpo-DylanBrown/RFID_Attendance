#include "ESP8266WiFi.h"

byte count = 0;
byte mac[6];

void setup()
{
  Serial.begin(115200);
  Serial.println();

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(2000); // Leaves the user 2 seconds to get the COM window open to view the MAC address

  
  WiFi.macAddress(mac);
  Serial.println("");
  Serial.print("MAC: ");
  Serial.print(mac[0],HEX);
  Serial.print(":");
  Serial.print(mac[1],HEX);
  Serial.print(":");
  Serial.print(mac[2],HEX);
  Serial.print(":");
  Serial.print(mac[3],HEX);
  Serial.print(":");
  Serial.print(mac[4],HEX);
  Serial.print(":");
  Serial.println(mac[5],HEX);

}

void loop()
{  
  if (count == 0) {
    Serial.println("Scan start ... ");
    
    int n = WiFi.scanNetworks();
    Serial.print(n);
    Serial.println(" network(s) found");
    for (int i = 0; i < n; i++)
    {
      Serial.println(WiFi.SSID(i));
    }
    count++;
    Serial.println();
  }
  //delay(5000);
}
