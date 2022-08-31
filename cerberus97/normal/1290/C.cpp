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

const int N = 3e5 + 10;

int par[N], ans = 0;
bool up[N], color[N], is_fixed[N];
int sz[N][2];

pii get_root(int u);
void set_color(int u, int c);
void add_edge(int u, int v, int x);

int main() {
	fast_cin();
	int n, k; string s;
	cin >> n >> k >> s;
	s = " " + s;
	vector<vector<int>> at(n + 1);
	for (int i = 1; i <= k; ++i) {
		int c; cin >> c;
		for (int j = 0; j < c; ++j) {
			int x; cin >> x;
			at[x].pb(i);
		}
	}
	for (int i = 1; i <= k; ++i) {
		par[i] = i;
		sz[i][0] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		if (at[i].size() == 1) {
			set_color(at[i][0], s[i] == '0');
		} else if (at[i].size() == 2) {
			int u = at[i][0], v = at[i][1];
			add_edge(u, v, s[i] == '0');
		}
		cout << ans << '\n';
	}
}

pii get_root(int u) {
	if (u != par[u]) {
		auto pu = get_root(par[u]);
		pu.second ^= up[u];
		return pu;
	} else {
		return {u, 0};
	}
}

void set_color(int u, int c) {
	auto p = get_root(u);
	u = p.first;
	c ^= p.second;
	is_fixed[u] = true;
	if (color[u] != c) {
		color[u] = c;
		ans += sz[u][0] - sz[u][1];
		swap(sz[u][0], sz[u][1]);
	}
}

void add_edge(int u, int v, int x) {
	auto pu = get_root(u);
	auto pv = get_root(v);
	x ^= pu.second ^ pv.second;
	u = pu.first; v = pv.first;
	if (u == v) {
		return;
	}
	if (is_fixed[u]) {
		swap(u, v);
	}
	if ((color[u] ^ color[v]) != x) {
		if (is_fixed[v] or sz[u][0] - sz[u][1] <= sz[v][0] - sz[v][1]) {
			color[u] ^= 1;
			ans += sz[u][0] - sz[u][1];
			swap(sz[u][0], sz[u][1]);
		} else {
			color[v] ^= 1;
			ans += sz[v][0] - sz[v][1];
			swap(sz[v][0], sz[v][1]);
		}
	}
	if (sz[u][0] + sz[u][1] < sz[v][0] + sz[v][1]) {
		swap(u, v);
	}
	sz[u][0] += sz[v][0];
	sz[u][1] += sz[v][1];
	par[v] = u;
	up[v] = x;
	is_fixed[u] |= is_fixed[v];
}