/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
bool vis[N];
vector <int> g[N];
int s[N];
int dp[N];

void dfs(int v) {
	s[v] = 1;
	vis[v] = true;
	vector <int> wef;
	for (int u : g[v]) {
		if (!vis[u]) {
			dfs(u);
			s[v] += s[u];
			wef.push_back(u);
		}
	}
	if ((int)wef.size() == 0) {
		dp[v] = 0;
	}  else if ((int)wef.size() == 1) {
		dp[v] = s[v] - 2;
	} else {
		int x = wef[0];
		int y = wef[1];
		dp[v] = max(s[x] - 1 + dp[y], s[y] - 1 + dp[x]);
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i <= n; i++) {
			dp[i] = 0;
			s[i] = 0;
			g[i].clear();
			vis[i] = false;
		}
		for (int i = 0; i < n - 1; i++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1);
		cout << dp[1] << '\n';
	}
}