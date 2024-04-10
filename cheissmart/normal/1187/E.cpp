#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

vi G[200005];
int dp[200005], s[200005], ans;

void dfs1(int u, int p = -1) {
	s[u] = 1;
	for(int v:G[u]) {
		if(v == p) continue;
		dfs1(v, u);
		s[u] += s[v];
		dp[u] += dp[v];
	}
	dp[u] += s[u];
}

void dfs2(int u, int p = -1) {
	ans = max(ans, dp[u]);
	for(int v:G[u]) {
		if(v == p) continue;
		int dpu = dp[u], dpv = dp[v], su = s[u], sv = s[v];
		dp[u] -= dp[v];
		dp[u] -= s[v];
		s[u] -= s[v];
		s[v] += s[u];
		dp[v] += dp[u];
		dp[v] += s[u];
		dfs2(v, u);
		dp[u] = dpu, dp[v] = dpv, s[u] = su, s[v] = sv;
	}
}

int32_t main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n-1;i++) {
		int u, v;
		cin >> u >> v;
		G[u].PB(v);
		G[v].PB(u);
	}
	dfs1(1);
	dfs2(1);
	cout << ans << endl;
}