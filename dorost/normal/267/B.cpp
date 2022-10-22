/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, M = 402468;
bool vis_e[N];
bool vis[M];
int pt[M], x[N], y[N], in;
vector <pair <int, int>> g[M];
vector <int> tour;
vector <int> wef[7][7];

void dfs(int v, int e = -1) {
	while (pt[v] < (int)g[v].size()) {
		int edge = g[v][pt[v]].F, u = g[v][pt[v]].S;
		pt[v]++;
		if (!vis_e[edge]) {
			vis_e[edge] = true;
			dfs(u, edge);
		}
	}
	tour.push_back(v);
	if (e == 105) {
		in = (int)tour.size();
	}
}

void dfsv(int v) {
	vis[v] = true;
	for (auto [wef, u] : g[v]) {
		if (!vis[u]) {
			dfsv(u);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n = 6, m;
	cin >> m;
	int lst = 0;
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i];
		wef[x[i]][y[i]].push_back(i + 1);
		lst = x[i];
		g[y[i]].push_back(make_pair(i, x[i]));
		g[x[i]].push_back(make_pair(i, y[i]));
	}
	dfsv(lst);
	vector <int> v;
	for (int i = 0; i <= n; i++) {
		if (((!vis[i]) && ((int)g[i].size() != 0))) {
			cout << "No solution";
			return 0;
		}
		if ((int)g[i].size() & 1) 
			v.push_back(i);
	}
	if ((int)v.size() > 2) {
		cout << "No solution";
		return 0;
	} else if (v.size() == 2) {
		g[v[0]].push_back(make_pair(105, v[1]));
		g[v[1]].push_back(make_pair(105, v[0]));
	}
	dfs(lst);
	if ((int)v.size() == 2) {
		tour.pop_back();
		rotate(tour.begin(), tour.begin() + in, tour.end());
	}
	for (int i = 0; i < (int)tour.size() - 1; i++) {
		int x = tour[i];
		int y = tour[i + 1];
		if (!wef[x][y].empty()) {
			cout << wef[x][y].back() << " +\n";
			wef[x][y].pop_back();
		} else{ 
			cout << wef[y][x].back() << " -\n";
			wef[y][x].pop_back();
		}
	}
	cout << endl;
}