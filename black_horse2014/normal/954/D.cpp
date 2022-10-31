#include <bits/stdc++.h>
using namespace std;

const int N = 1100;

int dis[2][N], con[N][N], q[N], a[2];
vector<int> adj[N];

int main() {
	int n, m, s, t; scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		con[u][v] = con[v][u] = 1;
	}
	a[0] = s, a[1] = t;
	const int inf = 1e9;
	for (int i = 1; i <= n; i++) dis[0][i] = dis[1][i] = inf;
	for (int j = 0; j < 2; j++) {
		int qn = 0;
		q[qn++] = a[j];
		dis[j][a[j]] = 0;
		for (int i = 0; i < qn; i++) {
			int u = q[i];
			for (int v : adj[u]) {
				if (dis[j][v] == inf) {
					q[qn++] = v;
					dis[j][v] = dis[j][u] + 1;
				}
			}
		}
	}
	int D = dis[0][t];
	int ans = 0;
	for (int u = 1; u <= n; u++) {
		for (int v = u+1; v <= n; v++) {
			if (con[u][v]) continue;
			int _D = min(dis[0][u] + 1 + dis[1][v], dis[1][u] + 1 + dis[0][v]);
			if (_D < D) continue;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}