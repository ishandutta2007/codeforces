/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], b[N], cnt = 0;
vector <int> g[N];
bool vis[N];

void dfs(int v) {
	vis[v] = true;
	cnt++;
	for (auto u : g[v]) {
		if (!vis[u]) {
			dfs(u);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		vis[i] = false;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		g[a[i]].push_back(b[i]);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			cnt = 0;
			dfs(i);
			sum += cnt / 2;
		}
	}
	ll ans = 0;
	for (int i = n; i >= n - sum + 1; i--) {
		ans += i * 2;
	}
	for (int i = 1; i <= sum; i++) {
		ans -= i * 2;
	}
	cout << ans << ' ';
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