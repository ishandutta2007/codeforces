/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int dp[N], s[N], root;
vector <int> g[N];
bool masir[N];

void dfs(int v, int p) {
	s[v] = 1;
	masir[v] &= (((int)g[v].size()) <= 2);
	masir[v] &= (v != root);
	int cnt = 0, cntb = 0, cntba = 0;
	bool f = false;
	for (int u : g[v]) {
		if (u != p) {
			dfs(u, v);
			f |= (dp[u] >= 2);
			masir[v] &= masir[u];
			dp[v] += dp[u];
			s[v] += s[u];
			if (dp[u] == 0)
				cntb++;	
			cnt++;
			if (s[u] == 1)
				cntba++;
		}
	}
	if (cntb)
		dp[v] += cntb - 1;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i <= n + 10; i++)
		dp[i] = 0, g[i].clear(), s[i] = 0, masir[i] = true;
	root = -1;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
		if (g[x].size() >= 2)
			root = x;
		if (g[y].size() >= 2)
			root = y;
	}
	if (n <= 3) {
		cout << n - 1 << '\n';
		return;
	}
	int ans = INT_MAX;
	for (int i = 1; i <= n; i++) {
		root = i;
		for (int i = 0; i <= n + 10; i++)
			dp[i] = 0, s[i] = 0, masir[i] = true;
		dfs(root, -1);
		ans = min(ans, dp[root]);
	}
	cout << ans + 1 << endl;
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