#include <bits/stdc++.h>

using namespace std;

const int N = 210;

int n, k;
vector<int> a;
vector<vector<int>> g, dp;

void dfs(int v, int p) {
	dp[v][0] = a[v];
	for (auto to : g[v]) {
		if (to != p) dfs(to, v);
	}
	for (int dep = 0; dep < N; ++dep) {
		if (dep == 0) {
			for (auto to : g[v]) {
				if (to == p) continue;
				dp[v][dep] += dp[to][max(0, k - dep - 1)];
			}
		} else {
			for (auto to : g[v]) {
				if (to == p) continue;
				int cur = dp[to][dep - 1];
				for (auto other : g[v]) {
					if (other == p || other == to) continue;
					cur += dp[other][max(dep - 1, k - dep - 1)];
				}
				dp[v][dep] = max(dp[v][dep], cur);
			}
		}
	}
	for (int dep = N - 1; dep > 0; --dep) {
		dp[v][dep - 1] = max(dp[v][dep - 1], dp[v][dep]);
	}
}

int main() {
	
	cin >> n >> k;
	++k;
	a = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	g = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	dp = vector<vector<int>>(n, vector<int>(N));
	dfs(0, -1);
	cout << dp[0][0] << endl;
	
	return 0;
}