#include <bits/stdc++.h>

const int MAXN = 5010;

int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
void gmi(int & x, int y) { x > y ? x = y : 0; }
int n;
int dp[MAXN][2][MAXN], hav[MAXN];
void dfs(int u, int fa = 0) {
	if (!nxt[head[u]]) {
		dp[u][0][0] = 0;
		dp[u][1][1] = 0;
		hav[u] = 1;
		return ;
	}
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)
			dfs(to[i], u);
	dp[u][0][0] = dp[u][1][0] = 0;
	static int f[2][MAXN];
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			memset(f, 0x3f, sizeof f);
			const int v = to[i];
			for (int x = 0; x <= hav[u]; ++x)
				for (int y = 0; y <= hav[v]; ++y) {
					gmi(f[0][x + y], dp[u][0][x] + dp[v][0][y]);
					gmi(f[0][x + y], dp[u][0][x] + dp[v][1][y] + 1);
					gmi(f[1][x + y], dp[u][1][x] + dp[v][0][y] + 1);
					gmi(f[1][x + y], dp[u][1][x] + dp[v][1][y]);
				}
			memcpy(dp[u], f, sizeof f);
			hav[u] += hav[v];
		}
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, b, e; i < n; ++i)
		std::cin >> b >> e, adde(b, e);
	if (n == 2) {
		std::cout << 0 << std::endl;
		return 0;
	}
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; ++i)
		if (nxt[head[i]]) {
			dfs(i);
			const int mid =  hav[i] >> 1;
			int ans = std::min(dp[i][0][mid], dp[i][1][mid]);
			std::cout << ans << '\n';
			break;
		}
	return 0;
}