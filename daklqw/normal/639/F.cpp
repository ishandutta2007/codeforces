#include <bits/stdc++.h>

const int MAXN = 300010;
typedef std::vector<int> VI;
int n, m, Q;
struct G {
	int head[MAXN], to[MAXN << 1], nxt[MAXN << 1], tot;
	G() { tot = 1; }
	void addedge(int b, int e) {
		nxt[++tot] = head[b]; to[head[b] = tot] = e;
		nxt[++tot] = head[e]; to[head[e] = tot] = b;
	}
	int dfn[MAXN], ins[MAXN], low[MAXN], bel[MAXN];
	int st[MAXN], top, idx, t0t;
	void _tarjan(int u, int fa = 0) {
		ins[st[++top] = u] = true;
		low[u] = dfn[u] = ++t0t;
		for (int i = head[u]; i; i = nxt[i])
			if ((i >> 1) != (fa >> 1)) {
				if (!dfn[to[i]]) {
					_tarjan(to[i], i);
					low[u] = std::min(low[u], low[to[i]]);
				} else if (ins[to[i]])
					low[u] = std::min(low[u], dfn[to[i]]);
			}
		if (low[u] == dfn[u]) {
			int v; ++idx;
			do ins[v = st[top--]] = false, bel[v] = idx; while (v != u);
		}
	}
	void tarjan() {
		idx = t0t = 0;
		memset(bel, 0, n + 1 << 2);
		memset(dfn, 0, n + 1 << 2);
		for (int i = 1; i <= n; ++i) if (!dfn[i]) _tarjan(i);
	}
	void tarjan(int * be, int * ed) {
		idx = t0t = 0;
		for (int * t = be; t != ed; ++t) bel[*t] = dfn[*t] = 0;
		for (int * t = be; t != ed; ++t) if (!dfn[*t]) _tarjan(*t);
	}
} gs, gt, gd;
int in[MAXN], out[MAXN], ST[20][MAXN << 1], idx;
int getmax(int x, int y) { return in[x] < in[y] ? x : y; }
void dfs(int u, int fa = 0) {
	static int * head = gt.head, * nxt = gt.nxt, * to = gt.to;
	ST[0][++idx] = u; in[u] = idx;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			dfs(to[i], u);
			ST[0][++idx] = u;
		}
	out[u] = idx;
}
int LCA(int x, int y) {
	x = in[x], y = in[y];
	if (x > y) std::swap(x, y);
	const int L = std::__lg(y - x + 1);
	return getmax(ST[L][x], ST[L][y - (1 << L) + 1]);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> Q;
	for (int i = 1, t1, t2; i <= m; ++i)
		std::cin >> t1 >> t2, gs.addedge(t1, t2);
	gs.tarjan();
	for (int i = 1; i <= m; ++i) {
		int x = gs.to[i << 1], y = gs.to[i << 1 | 1];
		if (gs.bel[x] != gs.bel[y])
			gt.addedge(gs.bel[x], gs.bel[y]);
	}
	for (int i = 1; i <= n; ++i) if (!in[i]) dfs(i);
	for (int i = 1; i != 20; ++i)
		for (int j = 1; j + (1 << i) - 1 <= idx; ++j)
			ST[i][j] = getmax(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
	const auto cmp = [] (int a, int b) { return in[a] < in[b]; };
	static int R;
	for (int T = 1; T <= Q; ++T) {
		int p, q; std::cin >> p >> q;
		static int ps[MAXN], li[MAXN << 2], bak; bak = 0;
		static int xs[MAXN], ys[MAXN];
		static auto readp = [] (int & x) {
			std::cin >> x; x = (x + R - 1) % n + 1;
			li[++bak] = x = gs.bel[x];
		};
		for (int i = 1; i <= p; ++i) readp(ps[i]);
		for (int i = 1; i <= q; ++i) readp(xs[i]), readp(ys[i]);
		std::sort(li + 1, li + 1 + bak, cmp);
		bak = std::unique(li + 1, li + 1 + bak) - li - 1;
		for (int i = bak; i > 1; --i) li[++bak] = LCA(li[i], li[i - 1]);
		std::sort(li + 1, li + 1 + bak, cmp);
		bak = std::unique(li + 1, li + 1 + bak) - li - 1;
		static int st[MAXN], top; top = 0;
		for (int i = 1; i <= bak; ++i) {
			while (top && in[li[i]] >= out[st[top]]) --top;
			if (top) gd.addedge(st[top], li[i]);
			st[++top] = li[i];
		}
		for (int i = 1; i <= q; ++i) gd.addedge(xs[i], ys[i]);
		gd.tarjan(li + 1, li + 1 + bak);
		int ans = true;
		for (int i = 2; i <= p; ++i)
			ans &= gd.bel[ps[i]] == gd.bel[ps[1]];
		gd.tot = 1;
		for (int i = 1; i <= bak; ++i) gd.head[li[i]] = 0;
		if (ans) R = (R + T) % n;
		std::cout << (ans ? "YES\n" : "NO\n");
	}
	return 0;
}