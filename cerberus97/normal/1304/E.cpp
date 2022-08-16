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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, LOG = log2(N) + 2, inf = 1e9 + 42;

vector<int> g[N];
int depth[N], up[N][LOG];

void dfs(int u, int p);
int get_dist(int u, int v);
void add_dist(vector<int>& d, int dist);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	int q; cin >> q;
	while (q--) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		vector<int> d(2, inf);
		add_dist(d, get_dist(a, b));
		add_dist(d, get_dist(a, x) + get_dist(y, b) + 1);
		add_dist(d, get_dist(a, y) + get_dist(x, b) + 1);
		if (d[k % 2] <= k) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}

void dfs(int u, int p) {
	depth[u] = depth[p] + 1;
	up[u][0] = p;
	for (int j = 1; j < LOG; ++j) {
		up[u][j] = up[up[u][j - 1]][j - 1];
	}
	for (auto& v : g[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
}

int get_dist(int u, int v) {
	int ans = 0;
	if (depth[u] < depth[v]) {
		swap(u, v);
	}
	for (int j = LOG - 1; j >= 0; --j) {
		if (depth[u] - (1 << j) >= depth[v]) {
			u = up[u][j];
			ans += (1 << j);
		}
	}
	if (u == v) {
		return ans;
	}
	for (int j = LOG - 1; j >= 0; --j) {
		if (up[u][j] != up[v][j]) {
			u = up[u][j];
			v = up[v][j];
			ans += (1 << (j + 1));
		}
	}
	return ans + 2;
}

void add_dist(vector<int>& d, int dist) {
	d[dist % 2] = min(d[dist % 2], dist);
}