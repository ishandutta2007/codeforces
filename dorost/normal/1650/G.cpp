/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234, M = 1000 * 1000 * 1000 + 7;
vector <int> g[N];
vector <int> bdag[N], bbag[N];
int dp1[N], dp2[N], n, m;
int so, t;
int dis[N];
int dis2[N];

void bfs(int s) {
	for (int i = 1; i <= n; i++)
		dis[i] = -1;
	queue <int> q;
	dis[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto y : g[x]) {
			if (dis[y] == -1) {
				dis[y] = dis[x] + 1;
				q.push(y);
			}
		}
	}
}

void bfs2(int s) {
	for (int i = 1; i <= n; i++)
		dis2[i] = -1;
	queue <int> q;
	dis2[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto y : g[x]) {
			if (dis2[y] == -1) {
				dis2[y] = dis2[x] + 1;
				q.push(y);
			}
		}
	}
}

int anss(int x) {
	if (dp1[x] != -1)
		return dp1[x];
	if (x == so)
		return 1;
	int ans = 0;
	for (auto y : bbag[x]) {
		ans += anss(y);
		ans %= M;
	}
	return dp1[x] = ans;
}

int anst(int x) {
	if (dp2[x] != -1)
		return dp2[x];
	if (x == t)
		return 1;
	int ans = 0;
	for (auto y : bdag[x]) {
		ans += anst(y);
		ans %= M;
	}
	return dp2[x] = ans;
}

void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		g[i].clear();
		bdag[i].clear();
		bbag[i].clear();
		dp1[i] = -1;
		dp2[i] = -1;
	}
	cin >> so >> t;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(so);
	bfs2(t);
	for (int i = 1; i <= n; i++) {
		for (auto j : g[i]) {
			if (dis[i] + 1 == dis[j]) {
				bdag[i].push_back(j);
				bbag[j].push_back(i);
			} 
		}
	}
	ll ans = anss(t);
	for (int i = 1; i <= n; i++) {
		for (auto j : g[i]) {
			if (dis[i] + dis2[j] + 1 ==	 dis[t] + 1) {
				ll x = (ll)anss(i) * (ll)anst(j);
				x %= M;
				ans += x;
				ans %= M;
			}
		}
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