/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 501234, M = (1 << 20);
bool vis_e[N];
bool vis[M];
int x[N], y[N];
int pt[M], wef = 0;
vector <pair <int, int>> g[M];
vector <int> tour;

void dfs(int v, int e = -1) {
	vis[v] = true;
	while (pt[v] < (int)g[v].size()) {
		int edge = g[v][pt[v]].F, u = g[v][pt[v]].S;
		pt[v]++;
		if (!vis_e[edge]) {
			vis_e[edge] = true;
			dfs(u, edge);
		}
	}
	if (e != -1) {
		if (v == (x[e] & wef)) {
			tour.push_back(e * 2 + 1);
			tour.push_back(e * 2 + 2);
		} else {
			tour.push_back(e * 2 + 2);
			tour.push_back(e * 2 + 1);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	vector <int> anstour;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	int ans = 0;
	int l = -1, r = 21;
	while (r - l > 1) {
		int k = (l + r) / 2;
		wef = (1 << k) - 1;
		for (int i = 0; i < M; i++) {
			g[i].clear();
			vis[i] = false;
			pt[i] = 0;
			if (i < N) {
				vis_e[i] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			int u = x[i] & wef;
			int v = y[i] & wef;
			g[u].push_back(make_pair(i, v));
			g[v].push_back(make_pair(i, u));
		}
		tour.clear();
		dfs(x[0] & wef);
		bool f = true;
		for (int i = 0; i < M; i++) {
			if (((!vis[i]) && ((int)g[i].size() != 0)) || ((int)g[i].size() & 1)) {
				f = false;
			}
		}
		if (f)
			anstour = tour, ans = k, l = k;
		else
			r = k;
	}
	cout << ans << endl;
	for (int i : anstour)
		cout << i << ' ';
	cout << endl;
}