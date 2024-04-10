/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012, M = 998244353;
int dp[N][N], a[N];
bool dp2[N][N];
vector <int> in[N];
bool out[N], vis[N];

void dfs(int v) {
	dp[v][0] = a[v];
	if (dp[v][0] >= M) {
		dp2[v][0] = true;
		dp[v][0] -= M;
	}
	vis[v] = true;
	for (int u : in[v]) {
		if (!vis[u]) {
			dfs(u);
		}
		for (int i = 1; i < N; i++) {
			dp[v][i] += (dp[u][i - 1]);
			dp2[v][i] |= dp2[u][i - 1];
			if (dp[v][i] >= M) {
				dp[v][i] -= M;
				dp2[v][i] = true;
			}
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i <= n + 5; i++)
		in[i].clear(), out[i] = true, vis[i] = false;
	for (int i = 0; i <= n + 5; i++) {
		for (int j = 0; j < N; j++)
			dp[i][j] = 0, dp2[i][j] = 0;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		in[v].push_back(u);
		out[u] = false;
	}
	int x = 0;
	for (int i = 1; i <= n; i++)
		if (out[i])
			x = i;
	dfs(x);
	int st = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		if (st != M) {
			st = max(st, i);
			if (dp[x][i] || dp2[x][i])
				ans = (st + dp[x][i]);
			st += (dp[x][i]); 
			if (st >= M) {
				st = M;
			}
			if (ans >= M)
				ans -= M;
		} else {
			ans += dp[x][i];
			if (ans >= M)
				ans -= M;
		}
		if (dp2[x][i])
			st = M;
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}