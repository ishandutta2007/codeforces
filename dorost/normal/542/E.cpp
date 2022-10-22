/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
vector <int> g[N], c;
bool vis[N], w[N];
int dis[N];

int lsp(vector <int> v) {
	int mx = 0;
	for (auto i : v) {
		for (auto x : v)
			dis[x] = -1;
		dis[i] = 0;
		queue <int> q;
		q.push(i);
		while (!q.empty()) {
			int x = q.front();
			mx = max(mx, dis[x]);
			q.pop();
			for (auto y : g[x]) {
				if (dis[y] == -1) {
					dis[y] = dis[x] + 1;
					q.push(y);
				}
			}
		}
	}
	return mx;
}

void dfs(int x) {
	vis[x] = true;
	c.push_back(x);
	for (auto y : g[x]) {
		if (!vis[y]) {
			w[y] = !w[x];
			dfs(y);
		} else {
			if (w[y] == w[x]) {
				cout << -1;
				exit(0);
			}
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	vector <vector <int>> cc;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			c.clear();
			w[i] = 0;
			dfs(i);
			cc.push_back(c);
		}
	}
	int ans = 0;
	for (auto v : cc) {
		ans += lsp(v);
	}
	cout << ans;
}