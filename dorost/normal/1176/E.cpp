/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int h[N];
bool vis[N];
vector <int> adj[N];
vector <int> hh[N];

void dfs(int x) {
	vis[x] = true;
	for (auto y : adj[x]) {
		if (vis[y])
			continue;
		h[y] = h[x] + 1;
		dfs(y);
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		adj[i].clear();
		hh[i].clear();
		vis[i] = false;
		h[i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int v, w;
		cin >> v >> w;
		w--;
		v--;
		adj[v].push_back(w);
		adj[w].push_back(v);
	}
	dfs(0);
	for (int i = 0; i < n; i++) {
		hh[h[i]].push_back(i);
	}
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			x += hh[i].size();
		else
			y += hh[i].size();
	}
	if (x <= n / 2) {
		cout << x << '\n';
		for (int i = 0; i < n; i += 2) {
			for (int j = 0; j < hh[i].size(); j++)
				cout << hh[i][j] + 1 << ' ';
		}
		cout << '\n';
	} else {
		cout << y << '\n';
		for (int i = 1; i < n; i += 2) {
			for (int j = 0; j < hh[i].size(); j++)
				cout << hh[i][j] + 1 << ' ';
		}
		cout << '\n';
	}
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