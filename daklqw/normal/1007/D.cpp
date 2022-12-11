#include <bits/stdc++.h>

const int MAXN = 100010;
const int MAXM = 10010;
const int MAXP = MAXM * 100 * 3;
const int MAXE = MAXP * 4;
namespace sat {
	int head[MAXP], nxt[MAXE], to[MAXE], tot;
	void adde(int b, int e) {
		if (!b || !e) return ;
		nxt[++tot] = head[b]; to[head[b] = tot] = e;
	}
	int dfn[MAXP], low[MAXP], bel[MAXP], idx, t0t;
	int st[MAXP], top; bool ins[MAXP];
	void tarjan(int u) {
		dfn[u] = low[u] = ++t0t;
		ins[st[++top] = u] = true;
		for (int i = head[u]; i; i = nxt[i])
			if (!dfn[to[i]]) {
				tarjan(to[i]);
				low[u] = std::min(low[u], low[to[i]]);
			} else if (ins[to[i]]) low[u] = std::min(low[u], dfn[to[i]]);
		if (dfn[u] == low[u]) {
			int v; ++idx;
			do ins[v = st[top--]] = false, bel[v] = idx; while (v != u);
		}
	}
	void solve(int n) {
		for (int i = 1; i <= n; ++i) if (!dfn[i]) tarjan(i);
	}
}
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int dep[MAXN], fa[MAXN], sz[MAXN], top[MAXN], son[MAXN], dfn[MAXN];
int t0t;
void dfs(int u) {
	sz[u] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			dep[to[i]] = dep[u] + 1;
			fa[to[i]] = u;
			dfs(to[i]);
			sz[u] += sz[to[i]];
			if (sz[to[i]] > sz[son[u]]) son[u] = to[i];
		}
}
void hld(int u) {
	dfn[u] = ++t0t;
	if (son[u]) top[son[u]] = top[u], hld(son[u]);
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u] && to[i] != son[u])
			top[to[i]] = to[i], hld(to[i]);
}
int n, m, idx, ps[MAXM][2], alt[MAXM << 1];
std::vector<int> hav[MAXN << 2];
void link(int u, int l, int r, int L, int R, int t) {
	if (L <= l && r <= R)
		return (void) hav[u].push_back(t);
	int mid = l + r >> 1;
	if (L <= mid) link(u << 1, l, mid, L, R, t);
	if (mid < R) link(u << 1 | 1, mid + 1, r, L, R, t);
}
void link(int x, int y, int t) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		link(1, 1, n, dfn[top[x]], dfn[x], t), x = fa[top[x]];
	}
	if (dep[x] > dep[y]) std::swap(x, y);
	if (x != y) link(1, 1, n, dfn[x] + 1, dfn[y], t);
}
typedef std::pair<int, int> pi;
pi build(int u, int l, int r) {
	int in = ++idx, out = ++idx;
	if (l != r) {
		int mid = l + r >> 1;
		pi t = build(u << 1, l, mid);
		sat::adde(in, t.first);
		sat::adde(t.second, out);
		t = build(u << 1 | 1, mid + 1, r);
		sat::adde(in, t.first);
		sat::adde(t.second, out);
	}
	const std::vector<int> & li = hav[u];
	const int S = li.size();
	int cur = 0;
	for (int i = 0; i <= S; ++i) {
		while (cur < i) {
			if (i != S && alt[li[cur]] == li[i]) break;
			sat::adde(++idx, in);
			sat::adde(idx, alt[li[cur]]);
			in = idx;
			sat::adde(out, ++idx);
			sat::adde(li[cur], idx);
			out = idx;
			++cur;
		}
		if (i != S) {
			sat::adde(li[i], in);
			sat::adde(out, alt[li[i]]);
		}
	}
	return pi(in, out);
}
int ansl[MAXM];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	dfs(1); top[1] = 1; hld(1);
	std::cin >> m;
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < 2; ++j)
			ps[i][j] = ++idx;
		for (int j = 0; j < 2; ++j)
			alt[ps[i][j]] = ps[i][j ^ 1];
	}
	for (int i = 1; i <= m; ++i) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		link(x1, y1, ps[i][0]);
		link(x2, y2, ps[i][1]);
	}
	build(1, 1, n);
	sat::solve(idx);
	bool can = true;
	for (int i = 1; i <= m; ++i) {
		int x = sat::bel[ps[i][0]], y = sat::bel[ps[i][1]];
		if (x == y) can = false;
		ansl[i] = x < y ? 1 : 2;
	}
	if (!can) return std::cout << "NO" << std::endl, 0;
	std::cout << "YES" << std::endl;
	for (int i = 1; i <= m; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}