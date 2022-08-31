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

const int N = 1e5 + 10;

int par[N], sz[N];

int get_root(int u);
void merge(int u, int v, int wt, ll& num);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sz[i] = 1;
		par[i] = i;
	}
	vector<vector<int>> g(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<int> ids(n);
	iota(ids.begin(), ids.end(), 1);
	sort(ids.begin(), ids.end(), [&] (int u, int v) {
		return a[u] > a[v];
	});
	ll num = 0;
	for (auto& u : ids) {
		for (auto& v : g[u]) {
			if (a[v] >= a[u]) {
				merge(u, v, a[u], num);
			}
		}
	}
	cout << fixed << setprecision(10) << ld(num) / (ll(n) * (n - 1)) << endl;
}

int get_root(int u) {
	if (u != par[u]) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

void merge(int u, int v, int wt, ll& num) {
	u = get_root(u);
	v = get_root(v);
	if (u != v) {
		num += ll(wt) * ll(sz[u]) * sz[v] * 2;
		par[u] = v;
		sz[v] += sz[u];
	}
}