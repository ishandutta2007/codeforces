#include <bits/stdc++.h>

const int MAXN = 1 << 12;
int A[MAXN], B[MAXN], now[MAXN], tar[MAXN], n, to[MAXN];
void fit(int i, int j) {
	if (A[i] == (B[i] ^ now[i])) return ;
	int t = to[A[i] ^ now[i]];
	if (t == j) return std::swap(B[i], B[t]), std::swap(to[B[i]], to[B[j]]);
	std::swap(B[i], B[t]);
	std::swap(to[B[i]], to[B[t]]);
	std::swap(A[j], A[t]); // ???
	fit(t, j);
}
int main() {
	scanf("%d", &n); n = 1 << n;
	int t = 0;
	for (int i = 0; i != n; ++i) {
		scanf("%d", tar + i);
		to[i] = A[i] = B[i] = i;
		t ^= tar[i];
	}
	if (t) return puts("Fou"), 0;
	for (int i = 0; i < n - 1; ++i) {
		now[i + 1] ^= now[i] ^ tar[i];
		now[i] = tar[i];
		fit(i, i + 1);
	}
	puts("Shi");
	for (int i = 0; i != n; ++i) printf("%d ", A[i]); putchar(10);
	for (int i = 0; i != n; ++i) printf("%d ", B[i]); putchar(10);
	return 0;
}