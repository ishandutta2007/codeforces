#include <bits/stdc++.h>

using namespace std;

int T;
vector<int> p, d;
vector<int> tin, tout;
vector<vector<int>> g;

void dfs(int v, int par = -1, int dep = 0) {
	p[v] = par;
	d[v] = dep;
	tin[v] = T++;
	for (auto to : g[v]) {
		if (to == par) continue;
		dfs(to, v, dep + 1);
	}
	tout[v] = T++;
}

bool isAnc(int v, int u) {
	return tin[v] <= tin[u] && tout[u] <= tout[v];
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;
	T = 0;
	p = d = vector<int>(n);
	tin = tout = vector<int>(n);
	g = vector<vector<int>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		vector<int> v(k);
		for (auto &it : v) {
			cin >> it;
			--it;
		}
		
		int u = v[0];
		for (auto it : v) if (d[u] < d[it]) u = it;
		for (auto &it : v) {
			if (it == u) continue;
			if (p[it] != -1) it = p[it];
		}
		bool ok = true;
		for (auto it : v) ok &= isAnc(it, u);
		if (ok) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}