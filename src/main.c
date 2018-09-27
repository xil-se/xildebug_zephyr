#include <zephyr.h>
#include <board.h>
#include <device.h>
#include <gpio.h>
#include <console.h>

#define SLEEP_TIME 	1000

void main(void)
{
	int cnt = 0;
	struct device *dev;

	dev = device_get_binding(LED5_GPIO_CONTROLLER);

	gpio_pin_configure(dev, LED5_GPIO_PIN, GPIO_DIR_OUT);

	console_init();

	printk("Start typing characters to see them echoed back\n");

	while (1) {
		/* Set pin to HIGH/LOW every 1 second */
		//gpio_pin_write(dev, LED5_GPIO_PIN, cnt % 2);
		//cnt++;

		//k_sleep(SLEEP_TIME);

		u8_t c = console_getchar();

		console_putchar(c);
		if (c == '\r') {
			console_putchar('\n');
		}
	}
}
