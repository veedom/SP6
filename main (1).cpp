#include "mbed.h" 
#include "BME280.h"

BME280 sensor(PB_9, PB_8); 
DigitalOut oled1(LED1);
// (I2C_SDA, I2C_SCL, I2C_Address);
// change those pins with respect to your board 
int main() {
oled1 = 0; while(1) {
printf(
"%d degC, %d hPa, %d %%\n", 
(int)sensor.getTemperature(), 
(int)sensor.getPressure(), 
(int)sensor.getHumidity());
if ((int)sensor.getTemperature() > 28)
{
oled1 = !oled1;
ThisThread::sleep_for(500ms);

}
else 
{
    oled1 = !oled1;
    ThisThread::sleep_for(20ms);

}


//wait_us(2000000);
}
}