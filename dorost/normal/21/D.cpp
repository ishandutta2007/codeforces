/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 16, INF = 50000000LL * 10000LL;
int dp[1 << N];
int dis[N][N];
int d[N], cntm = 0;
bool vis[N];
vector <int> g[N];

void dfs(int x) {
	vis[x] = true;
	for (int y : g[x]) {
		cntm++;
		if (!vis[y]) {
			dfs(y);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m, sum = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				dis[i][j] = INF;
			} else {
				dis[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].push_back(y);
		g[y].push_back(x);
		sum += w;
		d[x]++;
		d[y]++;
		dis[x][y] = min(dis[x][y], w);
		dis[y][x] = min(dis[y][x], w);
	}
	dfs(1);
	if (cntm != m * 2) {
		cout << -1 << endl;
		return 0;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	int mask = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] % 2) {
			mask += (1 << i);
		}
	}
	dp[0] = sum;
	for (int i = 1; i < (1 << (n + 1)); i++) {
		if (i & 1 || (__builtin_popcount(i) & 1))
			continue;
		dp[i] = INF;
		for (int j = 1; j <= n; j++) {
			for (int k = j + 1; k <= n; k++) {
				if (((i >> j) & 1) && ((i >> k) & 1)) {
					dp[i] = min(dp[i], dis[j][k] + dp[i ^ (1 << j) ^ (1 << k)]);
				}
			}
		}
	}
	cout << dp[mask];
}