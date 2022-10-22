#include <bits/stdc++.h>

#define MAXN (100010)

int n;

int main() {
	scanf("%d", &n);
	int min = INT_MAX, sit = 0;
	for (int i = 1; i <= n; ++i) {
		if (min > i + (n + i - 1) / i) {
			min = i + (n + i - 1) / i;
			sit = i;
		}
	}
	for (int i = n - sit + 1; i >= 1; i -= sit) {
		for (int j = i; j <= i + sit - 1; ++ j) {
			printf("%d ", j);
		}
	}
	for (int i = 1; i <= n % sit; ++i) {
		printf("%d ", i);
	}
	puts("");
	return 0;
}