#include <bits/stdc++.h>

const int MAXN = 300010;
typedef long long LL;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;
void adde(int b, int e, int v) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e; val[tot] = v;
	nxt[++tot] = head[e]; to[head[e] = tot] = b; val[tot] = v;
}
int A[MAXN], fa[MAXN], fae[MAXN];
LL f[MAXN], g[MAXN], sumf[MAXN], sumg[MAXN];
LL up[MAXN], suma[MAXN], sume[MAXN];
int n, Q;
int ST[20][MAXN << 1], bak, in[MAXN];
int gmin(int x, int y) { return in[x] < in[y] ? x : y; }
void dfs1(int u) {
	ST[0][++bak] = u; in[u] = bak;
	suma[u] = A[u], sume[u] = fae[u];
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			fa[to[i]] = u;
			fae[to[i]] = val[i];
			dfs1(to[i]);
			ST[0][++bak] = u;
			g[u] += f[to[i]];
			f[u] += f[to[i]];
		}
	f[u] += A[u] - fae[u] * 2;
	f[u] = std::max(f[u], 0ll);
	sumf[u] = f[u], sumg[u] = g[u];
}
void dfs2(int u, LL upv = 0) {
	suma[u] += suma[fa[u]];
	sume[u] += sume[fa[u]];
	sumf[u] += sumf[fa[u]];
	sumg[u] += sumg[fa[u]];
	up[u] = upv;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa[u]) {
			LL t = upv + g[u] - f[to[i]] + A[u] - val[i] * 2;
			dfs2(to[i], std::max(t, 0ll));
		}
}
int LCA(int x, int y) {
	if ((x = in[x]) > (y = in[y])) std::swap(x, y);
	const int L = std::__lg(y - x + 1);
	return gmin(ST[L][x], ST[L][y - (1 << L) + 1]);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> Q;
	for (int i = 1; i <= n; ++i) std::cin >> A[i];
	for (int i = 1, b, e, v; i < n; ++i)
		std::cin >> b >> e >> v, adde(b, e, v);
	dfs1(1); dfs2(1);
	for (int i = 1; i != 20; ++i)
		for (int j = 1; j + (1 << i) - 1 <= bak; ++j)
			ST[i][j] = gmin(ST[i - 1][j], ST[i - 1][j + (1 << i - 1)]);
	while (Q --> 0) {
		int x, y; std::cin >> x >> y;
		int L = LCA(x, y);
		LL ans = sumg[x] + sumg[y] - sumg[L] - sumg[fa[L]];
		ans -= sumf[x] + sumf[y] - sumf[L] * 2;
		ans += up[L];
		ans += suma[x] + suma[y] - suma[L] - suma[fa[L]];
		ans -= sume[x] + sume[y] - sume[L] * 2;
		std::cout << ans << '\n';
	}
	return 0;
}