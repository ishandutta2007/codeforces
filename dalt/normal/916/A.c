#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int gcd(int a, int b, int coef[]) {
	if (b == 0) {
		coef[0] = 1;
		coef[1] = 0;
		return a;
	}
	int g = gcd(b, a % b, coef);
	int m = coef[1];
	coef[1] = coef[0] - m * (a / b);
	coef[0] = m;
	return g;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("D:\\DataBase\\TESTCASE\\codeforces\\916A.in", "r",
	stdin);
#endif

	int interval, hour, minute;
	scanf("%d %d %d", &interval, &hour, &minute);

	//assume ab:cd is the result
	int n = 100000000;

	//ab:c7, what we need to do is to find a number n,
	//that ab:c7 + n * interval = minute
	//just 7 + n * interval = minute (mod 10)
	//or n * interval + m * 10 = 3 + minute
	int coef[2];
	int g = gcd(interval + 10, 10, coef);
	if ((3 + minute) % g == 0) {
		int c = (3 + minute) / g;
		int ten_g = 10 / g;
		int v = (((c * coef[0]) % ten_g) + ten_g) % ten_g;
		n = MIN(n, v);
	}

	//case 07:cd is the result
	//We cast the time into number with unit minute
	int step = 0;
	while (hour != 7 && hour != 17) {
		step++;
		minute -= interval;
		if (minute < 0) {
			minute += 60;
			hour -= 1;
			if (hour < 0) {
				hour = 23;
			}
		}
	}

	n = MIN(step, n);
	printf("%d\n", n);

	return 0;
}