/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 503, INF = 1000 * 1000 * 1000;
int par[N][N];
vector <pair <int, int>> g[N];
int dis[N][N];
int u[N * N], v[N * N], w[N * N];

void dijkstra (int s) {
	for (int i = 0; i < N; i++) {
		dis[s][i] = INF;
	}
	dis[s][s] = 0;
	set <pair <int, int>> q;
	q.insert(make_pair(dis[s][s], s));
	while (!q.empty()) {
		int x = (*q.begin()).S;
		q.erase(q.begin());
		int d = dis[s][x];
		for (auto [y, w] : g[x]) {
			if (dis[s][y] == d + w)
				par[s][y]++;
			if (dis[s][y] <= d + w) {
				continue;
			}
			q.erase(make_pair(dis[s][y], y));
			dis[s][y] = d + w;
			q.insert(make_pair(dis[s][y], y));
			par[s][y] = 1;
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
		cin >> u[i] >> v[i] >> w[i];
		g[u[i]].push_back(make_pair(v[i], w[i]));
		g[v[i]].push_back(make_pair(u[i], w[i]));
	}
	for (int i = 1; i <= n; i++) 
		dijkstra(i);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll ans = 0;
			for (int k = 1; k <= n; k++) {
				if (dis[i][k] + dis[k][j] == dis[i][j]) 
					ans += par[j][k];
			}
			cout << ans << ' ';
		}
	}
}