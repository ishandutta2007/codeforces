#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

int n, m;
int main() {
	scanf("%d%d", &n, &m);
	int len = (n - m) / 2 + 1, cur = 0;
	for (int i = 1; i <= n; ++i) {
		putchar((cur++ == len - 1) + 48);
		if (cur == len) cur = 0;
	}
	return 0;
}