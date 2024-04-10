/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, M = 402468;
bool vis_e[M];
bool vis[M];
int pt[M];
int x[N];
int y[N], n;
char ans[N];
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
	tour.push_back(e);
	if (e != -1 && e < n) {
		ans[e] = (v < N ? 'r' : 'b');
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		g[x[i]].push_back(make_pair(i, y[i] + N));
		g[y[i] + N].push_back(make_pair(i, x[i]));
	}
	bool f = false;
	int lst = -1;
	int cnt = n;
	for (int i = 0; i < M; i++) {
		if ((int)g[i].size() & 1) {
			if (f) {
				g[i].push_back({cnt, lst});
				g[lst].push_back({cnt, i});
				cnt++;
			}
			f = !f;
			lst = i;
		}
	}
	for (int i = 0; i < M; i++) {
		if (!vis[i])
			dfs(i);
	}
	for (int i = 0; i < n; i++)
		cout << ans[i];
	cout << endl;
}