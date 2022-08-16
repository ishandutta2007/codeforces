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

const int N = 1.5e5 + 10, V = 10 * N;

bool seen[N], is_building[V];
map<pii, int> all_cells;
priority_queue<int> pq;
int rx[V], ry[V];
vector<int> node_list[V], cyc_nb[V];
int par[V], sz[V];
bool is_free[V];
int cx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int cy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int get_root(int u);
void merge(int u, int v, bool ch);
bool check_outside(int x, int y, set<pii> &s);
bool check(int i);
int dfs(int u);

int main() {
	fast_cin();
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; ++i) {
		cin >> rx[i] >> ry[i];
		all_cells[{rx[i], ry[i]}] = i;
		is_building[i] = true;
		for (int d = 0; d < 8; ++d) {
			all_cells[{rx[i] + cx[d], ry[i] + cy[d]}];
		}
	}
	int m = n, leftmost = 1;
	for (auto &i : all_cells) {
		if (!i.second) {
			i.second = ++m;
		}
		tie(rx[i.second], ry[i.second]) = i.first;
		if (rx[i.second] < rx[leftmost]) {
			leftmost = i.second;
		}
	}
	is_free[leftmost] = true;
	for (int i = 1; i <= m; ++i) {
		sz[i] = 1;
		par[i] = i;
		node_list[i] = {i};
		for (int d = 0; d < 8; ++d) {
			int x = rx[i] + cx[d];
			int y = ry[i] + cy[d];
			cyc_nb[i].pb(all_cells[{x, y}]);
		}
	}
	for (int i = 1; i <= m; ++i) {
		for (int d = 1; d < 8; d += 2) {
			int j = cyc_nb[i][d];
			if (j and !is_building[i] and !is_building[j]) {
				merge(i, j, false);
			}
		}
	}
	if (dfs(1) != n) {
		cout << "NO\n";
		return 0;
	}
	memset(seen, 0, sizeof(seen));
	for (int i = 1; i <= n; ++i) {
		if (check(i)) {
			seen[i] = true;
			pq.push(i);
		}
	}
	vector<int> ans;
	while (!pq.empty()) {
		int u = pq.top();
		pq.pop();
		if (!check(u)) {
			seen[u] = false;
			continue;
		}
		ans.pb(u);
		is_building[u] = false;
		for (int d = 1; d < 8; d += 2) {
			int v = cyc_nb[u][d];
			if (!is_building[v]) {
				merge(u, v, true);
			}
		}
		for (int d = 0; d < 8; ++d) {
			int v = cyc_nb[u][d];
			if (is_building[v] and !seen[v] and check(v)) {
				seen[v] = true;
				pq.push(v);
			}
		}
	}
	if (ans.size() == n) {
		cout << "YES\n";
		reverse(ans.begin(), ans.end());
		for (auto &i : ans) {
			cout << i << '\n';
		}
	} else {
		cout << "NO\n";
	}
}

int get_root(int u) {
	if (par[u] != u) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

void merge(int u, int v, bool ch) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return;
	}
	if (is_free[v]) {
		swap(u, v);
	}
	if (is_free[u] and !is_free[v]) {
		for (auto &i : node_list[v]) {
			is_free[i] = true;
			if (ch) {
				for (auto &j : cyc_nb[i]) {
					if (is_building[j] and !seen[j] and check(j)) {
						seen[j] = true;
						pq.push(j);
					}
				}
			}
		}
	}
	if (sz[u] < sz[v]) {
		swap(u, v);
	}
	sz[u] += sz[v];
	par[v] = par[u];
	for (auto &i : node_list[v]) {
		node_list[u].pb(i);
	}
	node_list[v].clear();
}

bool check(int i) {
	bool free = false;
	for (int d = 1; d < 8; d += 2) {
		if (is_free[cyc_nb[i][d]]) {
			free = true;
			break;
		}
	}
	if (!free) {
		return false;
	}
	for (int d1 = 1; d1 < 8; d1 += 2) {
		for (int d2 = (d1 + 2); d2 < 8; d2 += 2) {
			int u = cyc_nb[i][d1], v = cyc_nb[i][d2];
			if (is_building[u] or get_root(u) != get_root(v)) {
				continue;
			}
			bool b1 = false, b2 = false;
			for (int j = (d1 + 1); j < d2; ++j) {
				if (is_building[cyc_nb[i][j]]) {
					b1 = true;
				}
			}
			for (int j = (d2 + 1) % 8; j != d1; j = (j + 1) % 8) {
				if (is_building[cyc_nb[i][j]]) {
					b2 = true;
				}
			}
			if (b1 and b2) {
				return false;
			}
		}
	}
	return true;
}

int dfs(int u) {
	if (seen[u]) {
		return 0;
	}
	seen[u] = true;
	int ans = 1;
	for (auto &v : cyc_nb[u]) {
		if (is_building[v]) {
			ans += dfs(v);
		}
	}
	return ans;
}