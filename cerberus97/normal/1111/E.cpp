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

const int N = 1e5 + 10, LOG = log2(N) + 2, K = 310, mod = 1e9 + 7;

vector<int> g[N];
bool mark[N];
int depth[N], up[N][LOG];
int ent_time[N], ext_time[N];
int nxt_time = 1;
int tree[4 * N];
ll dp[2][K];

void dfs(int u, int p);
int lca(int u, int v);
void update(int i, int l, int r, int p, int x);
int query(int i, int l, int r, int p);

int main() {
	// cout << sizeof(dp) / 1e6 << endl;
	fast_cin();
	int n, q;
	cin >> n >> q;
	for (int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	while (q--) {
		int k, m, r;
		cin >> k >> m >> r;
		vector<pii> special_nodes(k);
		for (auto &i : special_nodes) {
			cin >> i.second;
			mark[i.second] = true;
			update(1, 1, n, ent_time[i.second], 1);
			update(1, 1, n, ext_time[i.second], -1);
		}
		for (auto &i : special_nodes) {
			int u = i.second, l = lca(u, r);
			i.first = query(1, 1, n, ent_time[u]) + query(1, 1, n, ent_time[r]) - 2 * query(1, 1, n, ent_time[l]);
			i.first += mark[l] - 1;
			// cout << i.second << ' ' << i.first << endl;
		}
		sort(special_nodes.begin(), special_nodes.end());
		dp[0][0] = 1;
		for (int j = 1; j <= m; ++j) {
			dp[0][j] = 0;
		}
		for (int i = 1; i <= k; ++i) {
			dp[i & 1][0] = 0;
			for (int j = 1; j <= m; ++j) {
				dp[i & 1][j] = dp[(i - 1) & 1][j] * (j - special_nodes[i - 1].first) + dp[(i - 1) & 1][j - 1];
				dp[i & 1][j] %= mod;
			}
		}
		ll ans = 0;
		for (int j = 1; j <= m; ++j) {
			ans += dp[k & 1][j];
		}
		cout << ans % mod << '\n';
		for (auto &i : special_nodes) {
			mark[i.second] = false;
			update(1, 1, n, ent_time[i.second], -1);
			update(1, 1, n, ext_time[i.second], 1);
		}
	}
}

void dfs(int u, int p) {
	up[u][0] = p;
	for (int i = 1; i < LOG; ++i) {
		up[u][i] = up[up[u][i - 1]][i - 1];
	}
	ent_time[u] = nxt_time++;
	for (auto &v : g[u]) {
		if (v != p) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	}
	ext_time[u] = nxt_time;
}

int lca(int u, int v) {
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	for (int i = LOG - 1; i >= 0; --i) {
		if (depth[u] - (1 << i) >= depth[v]) {
			u = up[u][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = LOG - 1; i >= 0; --i) {
		if (up[u][i] != up[v][i]) {
			u = up[u][i];
			v = up[v][i];
		}
	}
	return up[u][0];
}

void update(int i, int l, int r, int p, int x) {
	if (p < l or p > r) {
		return;
	} else if (l == r) {
		tree[i] += x;
	} else {
		tree[i] += x;
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		update(lc, l, mid, p, x);
		update(rc, mid + 1, r, p, x);
	}
}

int query(int i, int l, int r, int p) {
	if (p < l) {
		return 0;
	} else if (p >= r) {
		return tree[i];
	} else {
		int mid = (l + r) / 2, lc = 2 * i, rc = lc + 1;
		return query(lc, l, mid, p) + query(rc, mid + 1, r, p);
	}
}