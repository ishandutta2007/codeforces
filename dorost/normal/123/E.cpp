/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int s[N], w[N], sd[N], yd[N], su[N], yu[N];
ll dpd[N], dpu[N];
int ss = 0, sw = 0;
int n;
vector <int> g[N];

void dfs(int v, int p = -1) {
	sd[v] = w[v];
	yd[v] = 0;
	for (int u : g[v]) {
		if (u != p) {
			dfs(u, v);
			sd[v] += sd[u];
			yd[v] += 1 + yd[u];
		}
	}
	yu[v] = (n - 1) - yd[v];
	su[v] = sw - sd[v];
	dpd[v] = (yu[v]) * (sd[v] - w[v]);
	for (int u : g[v]) {
		if (u != p) {
			dpd[v] += (dpd[u] - (yu[u]) * (sd[u] - w[u])) + (yd[v] - yd[u]) * sd[u];
		}
	}
}

void dfsu (int v, int p = -1) {
	ld sum1 = 0, sum2 = 0;
	for (int u : g[v]) {
		if (u != p) {
			dpu[u] = yd[u] * su[u];
			dpu[u] += dpu[v] - (yd[v] * su[v]);
			dpu[u] += (yd[v] - yd[u]) * (su[v]);
			dpu[u] += (1) * (w[v]);
			sum1 += yd[u] * sd[u];
			sum2 += (dpd[u] - ((ld)yu[u] * (sd[u] - w[u])));
		}
	}
	for (int u : g[v]) {
		if (u != p) {
			dpu[u] -= (sum1 - yd[u] * sd[u]);
			dpu[u] += (n - 1 - yd[u]) * (sd[v] - w[v] - sd[u]);
			dpu[u] += (sum2 - (dpd[u] - (yu[u] * (sd[u] - w[u]))));
		}
	}
	for (int u : g[v]) 
		if (u != p) 
			dfsu(u, v);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> w[i];
		ss += s[i];
		sw += w[i];
	}
	dfs(1);
	dfsu(1);
	ld ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += s[i] * (dpd[i] + dpu[i]);
	}
	cout << fixed << setprecision(11) << ans / ((ld)ss * (ld)sw);
}