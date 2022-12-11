#include <bits/stdc++.h>

const int MAXN = 110;
const int mod = 1000000007;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }
int pow(int a, int b, int res = 1) {
	for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
	return res;
}
int head[MAXN], nxt[MAXN << 1], to[MAXN << 1], tot;
void addedge(int b, int e) {
	nxt[++tot] = head[b]; to[head[b] = tot] = e;
	nxt[++tot] = head[e]; to[head[e] = tot] = b;
}
int n, K;
typedef std::pair<int, int> pi;
std::map<pi, int> dp[MAXN], g;
void dfs(int u, int fa = 0) {
	dp[u][pi(0, 0)] = 1;
	for (int i = head[u]; i; i = nxt[i])
		if (to[i] != fa) {
			dfs(to[i], u);
			g.clear();
			for (auto j : dp[u])
				for (auto k : dp[to[i]]) {
					auto x = j.first, y = k.first;
					int nl = std::min(x.first, y.first - 1);
					int nr = std::max(x.second, y.second - 1);
					reduce(g[pi(nl, nr)] += mul(j.second, k.second) - mod);
				}
			dp[u] = g;
		}
	g.clear();
	for (auto t : dp[u]) {
		auto x = t.first;
		if (x.first + K >= 0)
			reduce(g[pi(K + 1, K + 1)] += t.second - mod);
		if (x.first + x.second > 0)
			reduce(g[pi(x.second, x.second)] += t.second - mod);
		else reduce(g[x] += t.second - mod);
	}
	dp[u] = g;
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> n >> K;
	for (int i = 1, t1, t2; i < n; ++i)
		std::cin >> t1 >> t2, addedge(t1, t2);
	dfs(1); int ans = 0;
	for (auto t : dp[1])
		if (t.first.first > 0) reduce(ans += t.second - mod);
	std::cout << ans << std::endl;
	return 0;
}