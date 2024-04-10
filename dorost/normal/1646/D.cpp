/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
vector <int> g[N];
int ans[N];
pair <int, int> dp[N][2];
bool f[N];

void dfs(int v, int p) {
	dp[v][1] = {1, g[v].size()};
	dp[v][0] = {0, 0};
	for (auto u : g[v]) {
		if (u != p) {
			dfs(u, v);
			int k = 0;
			if (dp[u][1].F > dp[u][0].F || (dp[u][1].F == dp[u][0].F && dp[u][1].S < dp[u][0].S))
				k = 1;
			dp[v][0].F += dp[u][k].F;
			dp[v][0].S += dp[u][k].S;
			dp[v][1].F += dp[u][0].F;
			dp[v][1].S += dp[u][0].S;
		}
	}
}

void dfs2(int v, int p, int x) {
	if (x == 0) {
		f[v] = false;
		for (auto u : g[v]) {
			if (u != p) {
				dfs2(u, v, 1);
			}
		}
	} else {
		if (dp[v][0].F > dp[v][1].F || (dp[v][0].F == dp[v][1].F && dp[v][0].S < dp[v][1].S)) {
			f[v] = false;
			for (auto u : g[v]) {
				if (u != p) {
					dfs2(u, v, 1);
				}
			}
		} else {
			f[v] = true;
			for (auto u : g[v]) {
				if (u != p) {
					dfs2(u, v, 0);
				}
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if (n == 2) {
		cout << 2 << ' ' << 2 << '\n' << 1 << ' ' << 1 << '\n';
		return 0;
	}
	dfs(1, -1);
	dfs2(1, -1, 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i])
			ans[i] = (int)g[i].size();
		else
			ans[i] = 1;
		sum += ans[i];
	}
	cout << max(dp[1][0].F, dp[1][1].F) << ' ' << sum << '\n';
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
}