#include <bits/stdc++.h>

const int MAXN = 200010;
struct _ {
	int b, e, v, id;
	bool operator < (const _ & b) const { return v < b.v; }
} es[MAXN];
int n, m, ansl[MAXN];
int fa[MAXN], fae[MAXN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;
void adde(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
	fa[find(b)] = e;
}
int dep[MAXN], up[18][MAXN], mi[18][MAXN];
void dfs(int u) {
	for (int i = 1; i != 18; ++i) {
		up[i][u] = up[i - 1][up[i - 1][u]];
		mi[i][u] = std::max(mi[i - 1][u], mi[i - 1][up[i - 1][u]]);
	}
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			dep[to[i]] = dep[u] + 1;
			up[0][to[i]] = fa[to[i]] = u;
			mi[0][to[i]] = es[fae[to[i]] = val[i]].v;
			dfs(to[i]);
		}
}
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int i = 17, t = dep[x] - dep[y]; ~i; --i)
		if (t >> i & 1) x = up[i][x];
	if (x == y) return x;
	for (int i = 17; ~i; --i)
		if (up[i][x] != up[i][y])
			x = up[i][x], y = up[i][y];
	return up[0][x];
}
int jump(int x, int y) {
	int res = 0;
	for (int i = 17, t = dep[x] - dep[y]; ~i; --i)
		if (t >> i & 1)
			res = std::max(res, mi[i][x]), x = up[i][x];
	return res;
}
int solve(int x, int y, int v) {
	if (x == y) return x;
	if (dep[x] < dep[y]) std::swap(x, y);
	int tar = es[fae[x]].id;
	if (ansl[tar] == -1) ansl[tar] = v - 1;
	return fa[x] = solve(fa[x], y, v);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m;
	memset(ansl, -1, m + 1 << 2);
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i)
		std::cin >> es[i].b >> es[i].e >> es[i].v, es[i].id = i;
	std::sort(es + 1, es + 1 + m);
	static int mark[MAXN];
	for (int i = 1; i <= m; ++i)
		if (find(es[i].b) != find(es[i].e))
			adde(es[i].b, es[i].e, i), mark[i] = true;
	memset(fa, 0, n + 1 << 2);
	dfs(1);
	for (int i = 1; i <= m; ++i)
		if (!mark[i]) {
			int x = es[i].b, y = es[i].e;
			int L = LCA(x, y);
			ansl[es[i].id] = std::max(jump(x, L), jump(y, L)) - 1;
			solve(es[i].b, es[i].e, es[i].v);
		}
	for (int i = 1; i <= m; ++i)
		std::cout << ansl[i] << (" \n" [i == m]);
	return 0;
}