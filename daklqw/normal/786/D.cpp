#include <bits/stdc++.h>

const int MAXN = 20010;
int n, Q;
std::vector<std::pair<int, int> > V[MAXN];
int fa[MAXN], sz[MAXN], dep[MAXN], fae[MAXN];
int ff[16][MAXN];
void dfs(int u) {
	sz[u] = 1;
	for (auto t : V[u]) {
		int i = t.second, v = t.first;
		if (v != fa[u]) {
			ff[0][v] = fa[v] = u, fae[v] = i;
			dep[v] = dep[u] + 1;
			dfs(v);
			sz[u] += sz[v];
		}
	}
}
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int t = dep[x] - dep[y]; t; t &= t - 1)
		x = ff[__builtin_ctz(t)][x];
	for (int i = 15; ~i; --i)
		if (ff[i][x] != ff[i][y])
			x = ff[i][x], y = ff[i][y];
	return x == y ? x : ff[0][x];
}
int buf[MAXN], bak;
int stp, Ans;
inline int get(int x, int y) {
	return dep[x] < dep[y] ? sz[y] : n - sz[x];
}
int head[MAXN], nxt[MAXN];
void adde(int b, int e, int v) {
	nxt[e] = head[b], head[b] = e;
}
void calc(int u, int frm) {
	if (stp == bak) return ;
	++stp; ++Ans;
	for (int i = head[u]; i; i = nxt[i])
		if (i != frm && fae[i] <= buf[stp]) {
			if (fae[i] < buf[stp]) Ans += get(u, i);
			else calc(i, u);
		}
	if (fa[u] != frm && fae[u] <= buf[stp]) {
		if (fae[u] < buf[stp]) Ans += get(u, fa[u]);
		else calc(fa[u], u);
	}
	--stp;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 1, b, e; i < n; ++i) {
		static char buf[10];
		std::cin >> b >> e >> buf;
		V[b].emplace_back(e, *buf - 'a');
		V[e].emplace_back(b, *buf - 'a');
	}
	dfs(1); fae[1] = 12243;
	for (int i = 2; i <= n; ++i) adde(fa[i], i, fae[i]);
	for (int i = 1; i != 16; ++i)
		for (int j = 1; j <= n; ++j)
			ff[i][j] = ff[i - 1][ff[i - 1][j]];
	*buf = 12243;
	while (Q --> 0) {
		int x, y;
		std::cin >> x >> y; int X = x;
		int lca = LCA(x, y);
		bak = dep[x] + dep[y] - dep[lca] * 2;
		int L = 1, R = bak;
		while (x != lca) buf[L++] = fae[x], x = fa[x];
		while (y != lca) buf[R--] = fae[y], y = fa[y];
		Ans = -1;
		calc(X, 0);
		std::cout << Ans  << '\n';
	}
	return 0;
}