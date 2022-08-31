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

const int N = 75, M = 210, B = 17, inf = 1e9 + 42;

struct state_t {
	int u, mask, d;
	bool operator<(const state_t &o) const {
		return d > o.d;
	}
};

vector<int> g_small[N], g_large[N];
int seen[N], sz[N], bit[N], id_to_bit[N];
int dist[N][(1 << B)];

void dfs(int u, int id);

int main() {
	fast_cin();
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	for (int i = 1; i <= m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		if (c == a) {
			g_small[u].pb(v);
			g_small[v].pb(u);
		} else {
			g_large[u].pb(v);
			g_large[v].pb(u);
		}
	}
	int nxt_id = 0;
	for (int i = 1; i <= n; ++i) {
		if (!seen[i]) {
			dfs(i, ++nxt_id);
			id_to_bit[nxt_id] = -1;
		}
	}
	int nxt_bit = 0;
	for (int i = 1; i <= n; ++i) {
		if (sz[seen[i]] > 3) {
			if (id_to_bit[seen[i]] == -1) {
				id_to_bit[seen[i]] = nxt_bit++;
			}
			bit[i] = id_to_bit[seen[i]];
		} else {
			bit[i] = -1;
		}
	}
	int tot = (1 << nxt_bit);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < tot; ++j) {
			dist[i][j] = inf;
		}
	}
	// cout << bit[1] << endl;
	int s_mask = ((bit[1] == -1) ? 0 : (1 << bit[1]));
	dist[1][s_mask] = 0;
	priority_queue<state_t> q;
	q.push({1, s_mask, 0});
	while (!q.empty()) {
		auto cur = q.top();
		q.pop();
		int u = cur.u, mask = cur.mask, d = cur.d;
		if (d > dist[u][mask]) {
			continue;
		}
		for (auto &v : g_small[u]) {
			if (d + a < dist[v][mask]) {
				dist[v][mask] = d + a;
				q.push({v, mask, d + a});
			}
		}
		for (auto &v : g_large[u]) {
			// cout << u << ' ' << mask << ' ' << d << ' ' << v << endl;
			if (bit[v] != -1 and (mask & (1 << bit[v]))) {
				continue;
			} else if (bit[v] == -1 and seen[v] == seen[u]) {
				continue;
			}
			int new_mask = mask | ((bit[v] == -1) ? 0 : (1 << bit[v]));
			if (d + b < dist[v][new_mask]) {
				dist[v][new_mask] = d + b;
				q.push({v, new_mask, d + b});
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		int ans = inf;
		for (int j = 0; j < tot; ++j) {
			ans = min(ans, dist[i][j]);
		}
		cout << ans << ' ';
	}
	cout << endl;
}

void dfs(int u, int id) {
	seen[u] = id;
	++sz[id];
	for (auto &v : g_small[u]) {
		if (!seen[v]) {
			dfs(v, id);
		}
	}
}