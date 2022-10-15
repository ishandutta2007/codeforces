#include <cstdio>

int a[33], b[33];

int main() {
	int i, j, n, r = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		for (j = 0; j < i; j++) r += (a[i] == b[j]) + (a[j] == b[i]);
	}
	printf("%d", r);
}