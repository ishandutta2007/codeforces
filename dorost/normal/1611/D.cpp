/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int b[N], ans[N], w[N];
vector <int> g[N];
bool vis[N];

void dfs(int x) {
	vis[x] = true;
	for (auto y : g[x]) {
		if (!vis[y]) {
			ans[y] = w[y] - w[x];
			dfs(y);
		}
	}
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		vis[i] = false, g[i].clear(), ans[i] = 0;
	int root = -1;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
		if (b[i] == i)
			root = i;
		else
			g[b[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x--;
		w[x] = i;
	}
	ans[root] = 0;
	dfs(root);
	for (int i = 0; i < n; i++) {
		if (ans[i] < 0) {
			cout << -1 << '\n';
			return;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}