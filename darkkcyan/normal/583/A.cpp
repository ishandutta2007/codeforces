#include <stdio.h>
#include <string.h>

int main(void) {
	int n; scanf("%d", &n);
	int a[n], b[n];
	memset(a, 0, n * sizeof(int));
	memset(b, 0, n * sizeof(int));
	for (int i = 1; i <= n * n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		if (a[x] || b[y]) continue;
		printf("%d ", i);
		a[x] = b[y] = 1;
	}
	return 0;
}