/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int cnt = 0, wh[N];
vector <pair <int, int>> w[N];
ll dis[43][N];
bool vis[N];
vector <pair <int, int>> g[N];
pair <pair <int, int>, int> yal[23];
vector <int> ras;
int st[N];
int h[N], n, m;
int cc = 0;
ll ans[N];

pair <bool, int> is_valid (int v, int u, int k) {
	if (k == 0)
		return make_pair(true, n);
	int x = (upper_bound(w[k].begin(), w[k].end(), make_pair(st[v], N))) - w[k].begin() - 1;
	int y = (upper_bound(w[k].begin(), w[k].end(), make_pair(st[u], N))) - w[k].begin() - 1;
	return make_pair((x == y), (w[k][x]).S);
}
 
int lca(int v, int u) {
	if (h[v] > h[u])
		swap(v, u);
	int l = 0, r = min(h[v], h[u]);
	pair <bool, int> i = is_valid(v, u, r);
	if (i.F) {
		return i.S;
	}
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(v, u, mid).F) {
			l = mid;
		} else {
			r = mid;
		}
	}
	return is_valid(v, u, l).S;
}

void dfs(int v) {
	st[v] = cc;
	cc++;
	vis[v] = true;
	w[h[v]].push_back(make_pair(st[v], v));
	for (auto [u, w] : g[v]) {
		if (!vis[u]) {
			h[u] = h[v] + 1;
			ans[u] = ans[v] + w;
			dfs(u);
		} else {
			if (abs(h[u] - h[v]) == 1 || u > v)
				continue;
			yal[cnt] = (make_pair(make_pair(u, v), w));
			cnt++;
			ras.push_back(u);
			ras.push_back(v);
		}
	}
}

void dijkstra (int s) {
	for (int i = 0; i < N; i++) {
		dis[s][i] = LLONG_MAX;
	}
	dis[s][ras[s]] = 0;
	set <pair <ll, int>> q;
	q.insert(make_pair(dis[s][ras[s]], ras[s]));
	while (!q.empty()) {
		int x = (*q.begin()).S;
		q.erase(q.begin());
		ll d = dis[s][x];
		for (auto [y, w] : g[x]) {
			if (dis[s][y] <= d + w) {
				continue;
			}
			q.erase(make_pair(dis[s][y], y));
			dis[s][y] = d + w;
			q.insert(make_pair(dis[s][y], y));
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n >> m;
	ras.push_back(n);
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		g[u].push_back(make_pair(v, d));
		g[v].push_back(make_pair(u, d));
	}
	h[n] = 0;
	dfs(n);
	sort(ras.begin(), ras.end());
	ras.erase(unique(ras.begin(), ras.end()), ras.end());
	for (int i = 0; i < ras.size(); i++) {
		wh[ras[i]] = i;
		dijkstra(i);
	}
	for (int i = 0; i < N; i++)
		sort(w[i].begin(), w[i].end());
	int q;
	cin >> q;
	while (q--) {
		int s, t;
		cin >> s >> t;
		ll mn = LLONG_MAX;
		for (int i = 0; i < m - (n - 1); i++) {
			int u = yal[i].F.F;
			int v = yal[i].F.S;
			int wa = yal[i].S;
			mn = min(mn, dis[wh[u]][s] + dis[wh[v]][t] + wa);
			mn = min(mn, dis[wh[v]][s] + dis[wh[u]][t] + wa);
		}
		mn = min(mn, ans[s] + ans[t] - ans[lca(s, t)] * 2);
//		cout << lca(s, t) << '\n';
		cout << mn << '\n';
	}
}