/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 202, M = 4012;
vector <int> g[N];
int a[N];
int u[M], v[M], w[M];
int dis[N][N];
bool vis[N], c[N];

void dfs(int v) {
	vis[v] = true;
	for (auto u : g[v]) {
		if (!vis[u]) {
			c[u] = !c[v];
			dfs(u);
		} else {
			if (c[u] == c[v]) {
				cout << "NO\n";
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
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = INT_MAX / 2;
		}
		dis[i][i] = 0;
	}
	for (int i = 0; i < m; i++) {
		int x, y, b;
		cin >> x >> y >> b;
		g[x].push_back(y);
		g[y].push_back(x);
		u[2 * i] = x;
		v[2 * i] = y;
		w[2 * i] = +1;
		dis[x][y] = min(dis[x][y], 1);
		if (b == 0) {
			u[2 * i + 1] = y;
			v[2 * i + 1] = x;
			w[2 * i + 1] = +1;
			dis[y][x] = min(dis[y][x], 1);
		} else {
			u[2 * i + 1] = y;
			v[2 * i + 1] = x;
			w[2 * i + 1] = -1;
			dis[y][x] = min(dis[y][x], -1);
		}
	}
	c[1] = 0;
	dfs(1);
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][k] + dis[k][j], dis[i][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (dis[i][i] < 0) {
			cout << "NO\n";
			exit(0);
		}
	}
	cout << "YES\n";
	int mx = 0, r = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dis[i][j] > mx) {
				mx = dis[i][j];
				r = i;
			}
		}
	}
	cout << mx << '\n';
	for (int i = 0; i < N; i++)
		a[i] = INT_MAX / 2;
	a[r] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m * 2; j++) {
			a[v[j]] = min(a[v[j]], a[u[j]] + w[j]);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
}