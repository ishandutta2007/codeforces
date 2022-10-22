/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
vector <int> adj[N], adj2[N], w[N], w2[N];
bool vis[N], vis2[N];
int h[N], h2[N];

void dfs(int x) {
	vis[x] = true;
	for (auto y : adj[x]) {
		if (!vis[y]) {
			dfs(y);
		}
	}
}

void dfs2(int x) {
	vis2[x] = true;
	for (auto y : adj2[x]) {
		if (!vis2[y]) {
			dfs2(y);
		}
	}
}

int32_t main() {
	int n, m1, m2;
	cin >> n >> m1 >> m2;
	for (int i = 0; i < m1; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 0; i < m2; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i])
			dfs(i);
		for (int j = 0; j < n; j++)
			if (!vis[j])
				h[j]++;
	}
	for (int i = 0; i < n; i++) {
		if (!vis2[i])
			dfs2(i);
		for (int j = 0; j < n; j++)
			if (!vis2[j])
				h2[j]++;
	}
	for (int i = 0; i < n; i++) {
		w[h[i]].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		w2[h2[i]].push_back(i);
	}
	vector <pair <int, int>> ans;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (h2[i] == h2[j] || h[i] == h[j]) {
				continue;
			}
			ans.push_back({i + 1, j + 1});
			int x = h[i], y = h[j];
			for (auto aa : w[y]) {
				w[x].push_back(aa);
				h[aa] = x;
			}
			w[y] = {};
			x = h2[i], y = h2[j];
			for (auto aa : w2[y]) {
				w2[x].push_back(aa);
				h2[aa] = x;
			}
			w2[y] = {};
		}
	}
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].F << ' ' << ans[i].S << '\n';
	}
}