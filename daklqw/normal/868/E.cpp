#include <bits/stdc++.h>

const int MAXN = 51;
const int INF = 0x3f3f3f3f;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot = 1;
int deg[MAXN];
void addedge(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
	++deg[b], ++deg[e];
}
int f[MAXN << 1][MAXN][MAXN], m;
int dp(int ed, int x, int y) {
	if (!x && !y) return 0; 
	int & now = f[ed][x][y];
	if (now != -1) return now;
	int g[MAXN]; g[0] = INF;
	for (int i = 1; i <= x; ++i) g[i] = -INF;
	const int v = to[ed], u = to[ed ^ 1];
	if (deg[v] == 1) return now = dp(ed ^ 1, y, 0) + val[ed] * (y > 0);
	for (int i = head[v]; i; i = nxt[i])
		if (to[i] != u) {
			for (int j = x; ~j; --j)
				for (int k = j; k; --k)
					g[j] = std::max(g[j], std::min(g[j - k], dp(i, k, x + y - k) + val[i]));
		}
	return now = g[x];
}
int n, t1, t2, t3, rt, sz[MAXN];
void dfs(int u, int fa = 0) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			dfs(to[i], u);
			sz[u] += sz[to[i]];
		}
}
int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	memset(f, -1, sizeof f);
	std::cin >> n;
	for (int i = 1; i < n; ++i) {
		std::cin >> t1 >> t2 >> t3;
		addedge(t1, t2, t3);
	}
	std::cin >> rt >> m;
	for (int i = 1; i <= m; ++i)
		std::cin >> t1, ++sz[t1];
	dfs(rt);
	int ans = 0x3f3f3f3f;
	for (int i = head[rt]; i; i = nxt[i])
		ans = std::min(ans, dp(i, sz[to[i]], m - sz[to[i]]) + val[i]);
	std::cout << ans << std::endl;
	return 0;
}