/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 */

#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int bad = 0;

int get( int a ) {
	int x = 1;
	while (x * (x - 1) / 2 < a)
		x++;
	return x;
}

int main() {
	int a00, a01, a10, a11, k0, k1;
	cin >> a00 >> a01 >> a10 >> a11;
	if (!(a01 + a10)) {
		if (a00)
			k0 = get(a00), k1 = 0;
		else
			k1 = get(a11), k0 = 0;
	} else {
		k0 = get(a00);
		k1 = get(a11);
	}
	//printf("k0 = %d, k1 = %d, bad = %d\n", k0, k1, bad);
	bad |= (a00 != k0 * (k0 - 1) / 2);
	bad |= (a11 != k1 * (k1 - 1) / 2);
	bad |= (k0 * k1 != a10 + a01);
	if (bad)
		puts("Impossible");
	else {
		while (k1)
			if (a10 >= k0)
				putchar('1'), a10 -= k0, k1--;
			else
				putchar('0'), k0--;
		while (k0)
			putchar('0'), k0--;
	}
}