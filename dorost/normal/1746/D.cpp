/* 	* In the name of GOD  */

#pragma GCC optimize("O3,unroll-loops")

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
#define F first
#define S second
#define mkp make_pair
const int N = 201234;
int p[N], s[N];
vector <int> g[N];
map <int, ll> mp[N];

void dfs (int v, int k, ll sum) {
	if (mp[v][k] != 0)
		return;
	if (g[v].empty()) {
		mp[v][k] = sum * (ll)k + 1;
		return;
	}
	int x = k / (int)g[v].size();
	int y = k % (int)g[v].size();
	ll ans = 0;
	vector <int> ve;
	for (int u : g[v]) {
		dfs (u, x, sum + s[u]);
		if (y)
			dfs (u, x + 1, sum + s[u]);
		ans += (mp[u][x] - 1);
		if (y)
			ve.push_back(mp[u][x + 1] - mp[u][x]);
	}
	sort(ve.begin(), ve.end());
	reverse(ve.begin(), ve.end());
	for (int j = 0; j < y; j++)
		ans += ve[j];
	mp[v][k] = ans + 1;
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i <= n + 10; i++) {
		g[i].clear();
		mp[i].clear();
	}
	for (int i = 2; i <= n; i++) {
		cin >> p[i];
		g[p[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	dfs(1, k, s[1]);
	cout << mp[1][k] - 1 << '\n';
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