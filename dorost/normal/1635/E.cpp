/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], d[N], an[N];
vector <pair <int, bool>> g[N];
vector <int> g2[N];
bool c[N], vis[N], vis2[N];

void dfs(int v) {
	vis[v] = true;
	for (auto [u, w] : g[v]) {
		if (!vis[u]) {
			c[u] = !c[v];
			dfs(u);
		} else {
			if (c[v] == c[u]) {
				cout << "NO";
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
	for (int i = 0; i < m; i++) {
		int t, u, v;
		cin >> t >> u >> v;
		t--;
		g[u].push_back(make_pair(v, t));
		g[v].push_back(make_pair(u, t));
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		c[i] = 0;
		dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		if (c[i] == 0) {
			for (auto [j, w] : g[i]) {
				if (w == 0) {
					g2[i].push_back(j);
					d[j]++;
				} else {
					g2[j].push_back(i);
					d[i]++;
				}
			}
		}
	}
	queue <int> q;
	vector <int> ans;
	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) {
			q.push(i);
			vis2[i] = true;
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		ans.push_back(x);
		for (auto y : g2[x]) {
			if (vis2[y])
				continue;
			d[y]--;
			if (d[y] == 0) {
				vis2[y] = true;
				q.push(y);
			}
		}
	}
	if (ans.size() != n) {
		cout << "NO";
		return 0;
	}
	for (int i = 0; i < n; i++) 
		an[ans[i]] = i;
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		cout << (c[i] == 0 ? "L " : "R ") << an[i] << '\n';
	}
}