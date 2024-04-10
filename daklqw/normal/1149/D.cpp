#include <bits/stdc++.h>

const int MAXN = 80;
int fa[MAXN];
int n, m, A, B;
int xs[410], ys[410], vs[410];
int dp[1 << 17][MAXN];
int li[MAXN], bak, la[MAXN], sz[MAXN];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void gmin(int & x, int y) { x > y ? x = y : 0; }
std::vector<int> ae[MAXN], be[MAXN];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> m >> A >> B;
	for (int i = 1; i <= n; ++i) fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		std::cin >> xs[i] >> ys[i] >> vs[i];
		if (vs[i] == A) {
			fa[find(xs[i])] = find(ys[i]);
			ae[xs[i]].push_back(ys[i]);
			ae[ys[i]].push_back(xs[i]);
		}
	}
	for (int i = 1; i <= n; ++i) ++sz[find(i)];
	for (int i = 1; i <= n; ++i)
		if (i == fa[i] && sz[i] > 3) {
			li[bak] = i;
			for (int j = 1; j <= n; ++j)
				if (find(j) == i) la[j] = 1 << bak;
			++bak;
		}
	for (int i = 1; i <= m; ++i) if (vs[i] == B) {
		if (find(xs[i]) == find(ys[i])) continue;
		be[xs[i]].push_back(ys[i]);
		be[ys[i]].push_back(xs[i]);
	}
	const int U = 1 << bak;
	memset(dp, 0x3f, sizeof dp);
	dp[la[1]][1] = 0;
	for (int i = 0; i != U; ++i) {
		static int vis[MAXN];
		memset(vis, 0, n + 1 << 2);
		for (int j = 1; j <= n; ++j) {
			int at = 0;
			for (int k = 1; k <= n; ++k)
				if (!vis[k] && (!at || dp[i][k] < dp[i][at]))
					at = k;
			vis[at] = true;
			for (auto t : ae[at])
				gmin(dp[i][t], dp[i][at] + A);
			for (auto t : be[at]) if (!(i & la[t]))
				gmin(dp[i | la[t]][t], dp[i][at] + B);
		}
	}
	for (int i = 1; i <= n; ++i) {
		int ans = 0x3f3f3f3f;
		for (int j = 0; j != U; ++j) gmin(ans, dp[j][i]);
		std::cout << ans << ' ';
	}
	return 0;
}