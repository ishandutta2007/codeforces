#include <bits/stdc++.h>

const int MAXN = 100010;
int val[MAXN];
int fa[MAXN], dep[MAXN], up[17][MAXN];
int n, Q;
bool all(int x, int y, int v) {
	return (dep[x] - dep[y]) * v == val[x] - val[y];
}
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int i = 16, t = dep[x] - dep[y]; ~i; --i)
		if (t >> i & 1) x = up[i][x];
	if (x == y) return x;
	for (int i = 16; ~i; --i)
		if (up[i][x] != up[i][y])
			x = up[i][x], y = up[i][y];
	return up[0][x];
}
int bel[MAXN];
int find(int x) { return x == bel[x] ? x : bel[x] = find(bel[x]); }
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i) {
		std::cin >> fa[i] >> val[i];
		if (fa[i] != -1) {
			val[i] += val[fa[i]];
			dep[i] = dep[fa[i]] + 1;
			up[0][i] = fa[i];
			bel[i] = fa[i];
		} else fa[i] = val[i] = 0, bel[i] = i;
	}
	for (int i = 1; i != 17; ++i)
		for (int j = 1; j <= n; ++j)
			up[i][j] = up[i - 1][up[i - 1][j]];
	std::cin >> Q;
	while (Q --> 0) {
		int opt, x, y;
		std::cin >> opt >> x >> y;
		if (find(x) != find(y)) {
			std::cout << "NO\n";
			continue;
		}
		int L = LCA(x, y);
		bool can = all(x, L, 0) && all(y, L, opt - 1) && y != L;
		if (opt == 1) can &= x == L;
		std::cout << (can ? "YES" : "NO") << '\n';
	}
	return 0;
}