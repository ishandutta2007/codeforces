#include <bits/stdc++.h>

const int MAXN = 200010;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot = 1;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int dfn[MAXN], low[MAXN], st[MAXN], top, bel[MAXN], idx, t0t;
void tarjan(int u, int lst = 0) {
	st[++top] = u;
	low[u] = dfn[u] = ++t0t;
	for (int i = head[u]; i; i = nxt[i])
		if ((i ^ 1) != lst) {
			if (!dfn[to[i]]) {
				tarjan(to[i], i);
				low[u] = std::min(low[u], low[to[i]]);
			} else low[u] = std::min(low[u], dfn[to[i]]);
		}
	if (low[u] == dfn[u]) {
		int v; ++idx;
		do bel[v = st[top--]] = idx; while (v != u);
	}
}
int fa[MAXN][18], dep[MAXN];
int tree1[MAXN], tree2[MAXN];
int n, m, Q, xs[MAXN], ys[MAXN], rt[MAXN];
typedef std::pair<int, int> PII;
void dfs(int u) {
	for (int i = 1; i < 18; ++i)
		fa[u][i] = fa[fa[u][i - 1]][i - 1];
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u][0]) {
			rt[to[i]] = rt[u];
			fa[to[i]][0] = u;
			dep[to[i]] = dep[u] + 1;
			dfs(to[i]);
		}
}
int LCA(int x, int y) {
	if (dep[x] < dep[y]) std::swap(x, y);
	for (int t = dep[x] - dep[y]; t; t &= t - 1)
		x = fa[x][__builtin_ctz(t)];
	for (int i = 17; ~i; --i)
		if (fa[x][i] != fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return x == y ? x : fa[x][0];
}
void dfs2(int u) {
	dep[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u][0]) {
			dfs2(to[i]);
			tree1[u] += tree1[to[i]];
			tree2[u] += tree2[to[i]];
		}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> Q;
	for (int i = 1; i <= m; ++i) {
		std::cin >> xs[i] >> ys[i];
		addedge(xs[i], ys[i]);
	}
	for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i);
	std::set<PII> es;
	for (int i = 1; i <= m; ++i)
		if (bel[xs[i]] != bel[ys[i]])
			es.insert(PII(bel[xs[i]], bel[ys[i]]));
	tot = 0;
	memset(head, 0, n + 1 << 2);
	for (auto t : es)
		addedge(t.first, t.second);
	n = idx;
	for (int i = 1; i <= n; ++i) if (!dep[i])
		rt[i] = i, dep[i] = 1, dfs(i);
	bool can = true;
	while (Q --> 0) {
		int t1, t2;
		std::cin >> t1 >> t2;
		t1 = bel[t1], t2 = bel[t2];
		if (rt[t1] != rt[t2]) { can = false; break; }
		int L = LCA(t1, t2);
		++tree1[t1]; --tree1[L];
		++tree2[t2]; --tree2[L];
	}
	if (can) {
		memset(dep, 0, n + 1 << 2);
		for (int i = 1; i <= n; ++i) if (!dep[i]) dfs2(i);
		for (int i = 1; i <= n; ++i)
			can &= !(!!tree1[i] && !!tree2[i]);
	}
	std::cout << (can ? "Yes" : "No") << std::endl;
	return 0;
}