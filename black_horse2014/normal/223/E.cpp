#include <bits/stdc++.h>
using namespace std;

const int N = 110000;

int x[N], y[N], vis[N], a[N];
vector<int> con[N];
map<int, int> flow[N], sum[N];

int dfs(int u) {
	if (vis[u]) return 0;
	vis[u] = 1;
	int ret = 1;
	for (int v : con[u]) {
		int d = dfs(v);
		ret += d;
		flow[v][u] = d;
		flow[u][v] = -d;
	}
	return ret;
}

long long vect(int p1, int p2) {
	return 1LL * x[p1] * y[p2] - 1LL * x[p2] * y[p1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		con[u].push_back(v);
		con[v].push_back(u);
	}
	int mx = -2e9, id;
	for (int i = 1; i <= n; i++) {
		cin >> x[i] >> y[i];
		if (mx < x[i]) mx = x[i], id = i;
	}
	++n;
	x[n] = x[id] + 1, y[n] = y[id];
	con[id].push_back(n), con[n].push_back(id);
	dfs(n);
	for (int i = 1; i <= n; i++) {
		vector<long double> vd;
		vector<int> id;
		int k = 0;
		for (int j : con[i]) {
			vd.push_back(atan2l(y[j] - y[i], x[j] - x[i]));
			id.push_back(k++);
		}
		sort(id.begin(), id.end(), [&](int u, int v) {
			return vd[u] < vd[v];
		});
		for (int j = 0, cur = 0; j < con[i].size(); j++) {
			cur += flow[i][con[i][id[j]]];
			sum[i][con[i][id[j]]] = cur;
		}
	}
	int q; cin >> q;
	while (q--) {
		int k; cin >> k;
		for (int i = 0; i < k; i++) cin >> a[i];
		long long s = 0;
		for (int i = 0; i < k; i++)  s += vect(a[i], a[(i+1)%k]);
		if (s < 0) reverse(a, a + k);
		int ans = 0;
		for (int i = 0; i < k; i++) {
			int pr = a[(i-1+k)%k], cu = a[i], ne = a[(i+1)%k];
			ans += (sum[cu][ne] - sum[cu][pr] - flow[cu][ne]);
			if (atan2l(y[ne] - y[cu], x[ne] - x[cu]) < atan2l(y[pr] - y[cu], x[pr] - x[cu])) ans++;
		}
		cout << ans << endl;
	}
}