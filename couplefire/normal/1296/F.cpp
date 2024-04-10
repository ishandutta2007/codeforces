#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> val;
vector<vector<pair<int, int>>> g;

void dfs(int v, int pv, int pe, vector<pair<int, int>> &p) {
	p[v] = make_pair(pv, pe);
	for (auto it : g[v]) {
		int to = it.first;
		int idx = it.second;
		if (to == pv) continue;
		dfs(to, v, idx, p);
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	g = vector<vector<pair<int, int>>>(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(make_pair(v, i));
		g[v].push_back(make_pair(u, i));
	}
	
	vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(n));
	for (int i = 0; i < n; ++i) {
		dfs(i, -1, -1, p[i]);
	}
	
	val = vector<int>(n - 1, 1000000);

    cin >> m;
	vector<pair<pair<int, int>, int>> q(m);
	for (int i = 0; i < m; ++i) {
		cin >> q[i].first.first >> q[i].first.second >> q[i].second;
		--q[i].first.first;
		--q[i].first.second;
	}
	sort(q.begin(), q.end(), [&](pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.second < b.second;
	});
	
	for (int i = 0; i < m; ++i) {
		int u = q[i].first.first;
		int v = q[i].first.second;
		while (v != u) {
			int pv = p[u][v].first;
			int pe = p[u][v].second;
			val[pe] = q[i].second;
			v = pv;
		}
	}
	
	for (int i = 0; i < m; ++i) {
		int u = q[i].first.first;
		int v = q[i].first.second;
		int mx = 1000000;
		while (v != u) {
			int pv = p[u][v].first;
			int pe = p[u][v].second;
			mx = min(mx, val[pe]);
			v = pv;
		}
		if (mx != q[i].second) {
			cout << -1 << endl;
			return 0;
		}
	}
	
	for (int i = 0; i < n - 1; ++i) {
		cout << val[i] << " ";
	}
	cout << endl;
	
	return 0;
}