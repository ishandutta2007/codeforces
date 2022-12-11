#include <bits/stdc++.h>

const int MAXN = 300010;
int n, A[MAXN], at[MAXN];
int ansx[MAXN * 5], ansy[MAXN * 5], bak;
void mkswp(int x, int y) {
	std::swap(A[x], A[y]);
	std::swap(at[A[x]], at[A[y]]);
	++bak;
	ansx[bak] = x, ansy[bak] = y;
	// if (abs(x - y) < n / 2) fprintf(stderr, "ERR"), exit(1);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d", A + i), at[A[i]] = i;
	for (int i = 1; i <= n / 2; ++i) {
		if (at[i] == i) continue;
		if (at[i] > n / 2) mkswp(at[i], 1), mkswp(1, n);
		else mkswp(at[i], n);
		mkswp(n, i);
		if (at[1] != 1) mkswp(at[1], 1);
	// for (int i = 1; i <= n; ++i) printf("%d ", A[i]); putchar(10);
	}
	for (int i = n / 2 + 1; i <= n; ++i) {
		if (at[i] == i) continue;
		int a = at[i];
		mkswp(at[i], 1);
		mkswp(1, i);
		mkswp(a, 1);
	}
	printf("%d\n", bak);
	for (int i = 1; i <= bak; ++i) printf("%d %d\n", ansx[i], ansy[i]);
	// for (int i = 1; i <= n; ++i) printf("%d ", A[i]);
	return 0;
}