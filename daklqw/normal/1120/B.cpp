#include <bits/stdc++.h>

const int MAXN = 1e5 + 10;
typedef long long LL;
int D[MAXN], n;
char A[MAXN], B[MAXN];
void adj(int u, int v);
void mdf(int u, int v) {
	while (A[u] != v) {
		int dta = A[u] < v ? 1 : -1;
		A[u] += dta;
		adj(u + 1, dta);
		std::cout << u << ' ' << dta << '\n';
		static int ct = 0;
		if (++ct == 100000) exit(0);
	}
}
void adj(int u, int v) {
	A[u] += v;
	if (A[u] < '0') mdf(u, '0');
	if (A[u] > '9') mdf(u, '9');
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> A + 1 >> B + 1;
	LL sm = 0;
	for (int i = 1; i <= n; ++i)
		sm += std::abs(D[i] = B[i] - (A[i] + D[i - 1]));
	if (D[n]) sm = -1;
	std::cout << sm << '\n';
	sm = std::min<LL>(sm, 100000);
	if (sm > 0)
		for (int i = 1; i < n; ++i) mdf(i, B[i]);
	return 0;
}