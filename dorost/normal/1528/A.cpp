/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int l[N][2], dp[N][2], par[N];
vector <int> adj[N];
bool vis[N];
int n;

void dfs(int x) {
	vis[x] = true;
	for (auto y : adj[x]) {
		if (vis[y])
			continue;
		dfs(y);
		par[y] = x;
	}
}

int ans(int x, int i) {
	if (dp[x][i] != -1)
		return dp[x][i];
	vis[x] = true;
	int mx = 0;
	for (auto y : adj[x]) {
		if (par[y] != x)
			continue;
		int an = max(abs(l[x][i] - l[y][0]) + ans(y, 0), abs(l[x][i] - l[y][1]) + ans(y, 1));
		mx += an;
	}
	return dp[x][i] = mx;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		dp[i][0] = -1;
		dp[i][1] = -1;
		par[i] = -1;
		vis[i] = false;
		cin >> l[i][0] >> l[i][1];
	}
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		vis[i] = false;
	}
	int mx = ans(0, 0);
	for (int i = 0; i < n; i++) {
		vis[i] = false;
	}
	mx = max(mx, ans(0, 1));
	cout << mx << '\n';
	for (int i = 0; i < n; i++) {
//		cout << dp[i][0] << ' ' << dp[i][1] << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}