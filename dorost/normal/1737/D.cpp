/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 503, M = 250012;
int dis[N][N], u[M], v[M], w[M];

void solve() {
	int n, m;
	cin >> n >> m;
	ll ans = LLONG_MAX;
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= n + 1; j++) {
			dis[i][j] = M;
			if (i == j)
				dis[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		dis[u[i]][v[i]] = 1;
		dis[v[i]][u[i]] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 0; i < m; i++) {
		ll x = 1 + dis[1][u[i]] + dis[v[i]][n];
		ll y = 1 + dis[1][v[i]] + dis[u[i]][n];
		x = min(x, y);
		for (int j = 1; j <= n; j++) {
			x = min(x, (min ((ll)dis[j][u[i]], (ll)dis[j][v[i]]) + (ll)dis[j][1] + (ll)dis[j][n] + 2LL));
		}
		ans = min(ans, x * (ll)w[i]);
	}
	cout << ans << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}