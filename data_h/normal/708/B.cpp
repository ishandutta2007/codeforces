#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int a00, a01, a10, a11;

int get(int n) {
	for (long long i = 1; i * (i - 1) / 2 <= n; i++) {
		if (i * (i - 1) / 2 == n) return i;
	}
	return -1;
}

const int N = 1e6 + 7;

char answer[N];

void test(int a, int b) {
	// a*(a-1) / 2 = a00
	// b*(b-1) / 2 = a11

	if (a == -1) a = get(a00);
	if (a == -1 || 1LL * a * (a - 1) / 2 != a00) return ;

	if (b == -1) b = get(a11);
	if (b == -1 || 1LL * b * (b - 1) / 2 != a11) return ;

	if (0LL + a + b > 1000000) return ;

	if (0LL + a00 + a01 + a10 + a11 != 1LL * (a + b) * (a + b - 1) / 2) return ;
	answer[a + b] = 0;
	int b01 = a01, b10 = a10;
	for (int i = a + b - 1; i >= 0; i--) {
		if (b01 >= a) {
			b01 -= a;
			answer[i] = '1';
			b--;
		} else {
			b10 -= b;
			answer[i] = '0';
			a--;
		}
	}
	puts(answer);
	exit(0);
}

int main() {
	scanf("%d %d %d %d", &a00, &a01, &a10, &a11);
	test(-1, -1);
	test(0, -1);
	test(-1, 0);

	puts("Impossible");
	return 0;
}