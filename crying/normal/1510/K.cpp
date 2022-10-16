#include <cstdio>
#include <algorithm>

#define _N 1010

int n, pos;

int p[_N << 1];

void swap1() {
	for (int i = 1; i <= (n << 1); i += 2) {
		std::swap(p[i], p[i + 1]);
	}
}
void swap2() {
	for (int i = 1; i <= n; i++) {
		std::swap(p[i], p[i + n]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= (n << 1); i++) {
		scanf("%d", &p[i]);
	}
	for (int i = 1; i <= (n << 1); i++) {
		if (p[i] == 1) {
			pos = i;
		}
	}
	int ans = 0;
	if (n & 1) {
		while (pos != 1) {
			if (!(pos & 1)) {
				swap1();
				pos--;
			} else {
				swap2();
				pos = pos > n ? pos - n : pos + n;
			}
			ans++;
		}
	} else {
		if (pos != 1 && pos != 2 && pos != n + 1 && pos != n + 2) {
			puts("-1");
			return 0;
		}
		while (pos != 1) {
			if (pos & 1) {
				swap2();
				pos -= n;
			} else {
				swap1();
				pos--;
			}
			ans++;
		}
	}
	for (int i = 1; i <= (n << 1); i++) {
		if (p[i] != i) {
			puts("-1");
			return 0;
		}
	}
	printf("%d\n", std::min((n << 1) - ans, ans));
	return 0;
}