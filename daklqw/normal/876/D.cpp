#include <stdio.h>

int pos, n, x, vis[301000];
int main() {
	scanf("%d", &n); putchar(49);
	pos = n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &x); vis[x] = 1;
		while (vis[pos]) --pos;
		printf(" %d", i - n + pos + 1);
	}
	return 0;
}