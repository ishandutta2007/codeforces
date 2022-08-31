/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 5e5 + 10, M = N, inf = 1e9 + 42;

int a[M], b[M];
vector<int> g[N];
int deg[N], depth[N], dist[N], back[N];
bool seen[N];

vector<int> solve(int n, int m);
void bfs(int s, int n);
void dfs(int u);
vector<int> path(int s, int t);
vector<int> get_any_path(int u);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
			deg[i] = 0;
		}
		for (int i = 1; i <= m; ++i) {
			cin >> a[i] >> b[i];
			g[a[i]].pb(b[i]);
			g[b[i]].pb(a[i]);
			++deg[a[i]];
			++deg[b[i]];
		}
		auto ans = solve(n, m);
		if (ans.empty() or ans.size() == n) {
			cout << "No\n";
		} else {
			cout << "Yes\n" << n - ans.size() << '\n';
			for (int i = 1; i <= n; ++i) {
				seen[i] = false;
			}
			for (auto &v : ans) {
				seen[v] = true;
			}
			for (int i = 1; i <= n; ++i) {
				if (!seen[i]) {
					cout << i << ' ';
				}
			}
			cout << '\n';
		}
	}
}

vector<int> solve(int n, int m) {
	vector<int> at[3];
	for (int i = 1; i <= n; ++i) {
		deg[i] %= 3;
		if (deg[i] == 0) {
			return {i};
		}
		at[deg[i]].pb(i);
	}
	if (at[1].size() >= 2) {
		int s = at[1][0];
		bfs(s, n);
		// cout << "HERE" << endl;
		// for (int i = 1; i <= n; ++i) {
		// 	cout << i << ' ' << deg[i] << ' ' << dist[i] << ' ' << back[i] << endl;
		// }
		int t = at[1][1];
		for (auto &v : at[1]) {
			if (v != s and dist[v] < dist[t]) {
				t = v;
			}
		}
		return path(s, t);
	} else {
		int s = (at[1].empty() ? at[2][0] : at[1][0]);
		for (int i = 1; i <= n; ++i) {
			seen[i] = false;
		}
		back[s] = depth[s] = 0;
		dfs(s);
		int min_2_cycle = n + 1, au = -1, av = -1;
		for (int i = 1; i <= m; ++i) {
			int u = a[i], v = b[i];
			if (depth[u] > depth[v]) {
				swap(u, v);
			}
			if (depth[v] > depth[u] + 1 and deg[u] == 2 and deg[v] == 2) {
				if (depth[v] - depth[u] < min_2_cycle) {
					min_2_cycle = depth[v] - depth[u];
					au = u; av = v;
				}
			}
		}
		if (min_2_cycle <= n) {
			return path(au, av);
		} else if (deg[s] == 1) {
			vector<vector<int>> paths;
			for (int v = 1; v <= n; ++v) {
				if (back[v] == s) {
					paths.pb(get_any_path(v));
				}
			}
			assert(paths.size() > 1);
			vector<int> ans = paths[0];
			ans.pop_back();
			for (auto &v : paths[1]) {
				ans.pb(v);
			}
			return ans;
		} else {
			return {};
		}
	}
}

void bfs(int s, int n) {
	for (int i = 1; i <= n; ++i) {
		dist[i] = inf;
		back[i] = 0;
	}
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		for (auto &v : g[u]) {
			if (dist[v] > dist[u] + 1) {
				dist[v] = dist[u] + 1;
				back[v] = u;
				q.push(v);
			}
		}
	}
}

void dfs(int u) {
	seen[u] = true;
	for (auto &v : g[u]) {
		if (!seen[v]) {
			depth[v] = depth[u] + 1;
			back[v] = u;
			dfs(v);
		}
	}
}

vector<int> path(int s, int t) {
	vector<int> ans = {t};
	while (t != s) {
		t = back[t];
		ans.pb(t);
	}
	return ans;
}

vector<int> get_any_path(int u) {
	for (auto &v : g[u]) {
		if (depth[v] != depth[u] - 1 and deg[v] == 1) {
			return path(v, u);
		}
	}
	for (auto &v : g[u]) {
		if (depth[v] > depth[u]) {
			return get_any_path(v);
		}
	}
	assert(0);
}