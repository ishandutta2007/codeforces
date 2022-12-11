#include <bits/stdc++.h>

const int MAXN = 300010;
typedef long long LL;
typedef std::vector<int> VI;
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void adde(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
VI dp[MAXN]; int deg[MAXN];
std::priority_queue<int, VI, std::greater<int> > q[MAXN];
LL ans, sm[MAXN];
void dfs(int u, int fa = 0) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)
			++deg[u], dfs(to[i], u);
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa)
			for (int j = 0; j < deg[to[i]] && j < deg[u]; ++j)
				q[j].push(dp[to[i]][j]);
	for (int i = 0; i < deg[u]; ++i) {
		while (q[i].size() > i + 1) q[i].pop();
		int t = q[i].size() <= i ? 1 : q[i].top() + 1;
		while (!q[i].empty()) q[i].pop();
		dp[u].push_back(t); sm[u] += t;
	}
}
void dfs2(int u, int fa = 0) {
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			dfs2(to[i], u);
			if (dp[to[i]].size() > dp[u].size()) {
				dp[u].swap(dp[to[i]]);
				std::swap(sm[u], sm[to[i]]);
			}
			const int S = dp[to[i]].size();
			for (int j = 0; j != S; ++j)
				if (dp[to[i]][j] > dp[u][j]) {
					sm[u] -= dp[u][j];
					sm[u] += dp[u][j] = dp[to[i]][j];
				}
		}
	ans += sm[u];
}
int n;
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n;
	for (int i = 1, t1, t2; i < n; ++i)
		std::cin >> t1 >> t2, adde(t1, t2);
	ans = (LL) n * n;
	dfs(1); dfs2(1);
	std::cout << ans << std::endl;
	return 0;
}