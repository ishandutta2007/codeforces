/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234, LG = 30;
vector <int> g[LG][N];
int vis[N][LG];
bool good[N];
int cnt[N][LG], u[N], v[N], w[N];

void dfs(int v, int root, int b) {
	vis[v][b] = root;
	if (good[v])
		cnt[root][b]++;
	for (auto u : g[b][v]) {
		if (!vis[u][b]) {
			dfs(u, root, b);
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
		for (int j = 0; j < LG; j++) {
			if (w[i] & (1 << j)) {
				g[j][v[i]].push_back(u[i]);
				g[j][u[i]].push_back(v[i]);
			}
		}
		if (w[i] % 2 == 0) {
			good[v[i]] = true;
			good[u[i]] = true;
		}
	}
	for (int i = 0; i < LG; i++) {
		for (int j = 1; j <= n; j++) {
			if (!vis[j][i]) {
				dfs(j, j, i);
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		bool zero = false;
		for (int i = 0; i < LG; i++) {
			if (vis[u][i] == vis[v][i])
				zero = true;
		}
		if (zero) {
			cout << 0 << ' ';
			continue;
		}
		bool one = false;
		for (int i = 1; i < LG; i++) {
			if (cnt[vis[u][i]][i])
				one = true;
		}
		if (one) {
			cout << 1 << ' ';
		} else {
			cout << 2 << ' ';
		}
	}
}