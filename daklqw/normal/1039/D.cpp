#include <bits/stdc++.h>

const int MAXN = 100010;
struct _ {
	int to, nxt;
} es[MAXN << 1];
int head[MAXN], tot;
void adde(int b, int e) {
	es[++tot] = (_) {e, head[b]}; head[b] = tot;
	es[++tot] = (_) {b, head[e]}; head[e] = tot;
}
int n;
int fa[MAXN], dfn[MAXN], idx, li[MAXN];
void dfs(int u, int f = 0) {
	li[dfn[u] = ++idx] = u;
	fa[dfn[u]] = dfn[f];
	for (int i = head[u]; i; i = es[i].nxt)
		if (es[i].to != f)
			dfs(es[i].to, u);
}
struct info {
	int fir, sec;
	inline void ins(int v) {
		v >= fir ? (sec = fir, fir = v) : (sec = std::max(sec, v));
	}
} dp[MAXN];
int calc(int K) {
	memset(dp, 0, (n + 1) * sizeof (info));
	int res = 0;
	for (int i = n; i; --i) {
		if (dp[i].fir + dp[i].sec + 1 >= K)
			++res, dp[i].fir = -1;
		dp[fa[i]].ins(dp[i].fir + 1);
	}
	return res;
}
int g[MAXN];
int get(int x) {
	return ~g[x] ? g[x] : g[x] = calc(x);
}
int ansl[MAXN];
void solve(int l, int r) {
	if (get(l) == get(r)) {
		std::fill(ansl + l, ansl + r + 1, get(l));
		return ;
	}
	if (r - l <= 1) {
		ansl[l] = get(l), ansl[r] = get(r);
		return ;
	}
	int mid = l + r >> 1;
	solve(l, mid); solve(mid, r);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	memset(g, -1, sizeof g);
	std::cin >> n;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	dfs(1);
	solve(1, n);
	for (int i = 1; i <= n; ++i)
		std::cout << ansl[i] << '\n';
	return 0;
}