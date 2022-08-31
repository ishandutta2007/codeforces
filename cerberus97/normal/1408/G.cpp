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

const int N = 1500 + 10, mod = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int mul(ll a, int b) {
	return (a * b) % mod;
}

struct edge_t {
	int w, u, v;
	bool operator<(const edge_t& o) const {
		return w < o.w;
	}
};

int par[N], sz[N], esz[N];
vector<int> dp[N];

int get_root(int u);
void merge(int u, int v);

int main() {
	fast_cin();
	int n; cin >> n;
	vector<edge_t> edges;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int a; cin >> a;
			if (i < j) {
				edges.pb({a, i, j});
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
		sz[i] = 1;
		esz[i] = 0;
		dp[i] = {0, 1};
	}
	sort(edges.begin(), edges.end());
	for (auto& e : edges) {
		// cout << e.u << ' ' << e.v << endl;
		merge(e.u, e.v);
	}
	int u = get_root(1);
	for (int k = 1; k <= n; ++k) {
		cout << dp[u][k] << ' ';
	}
	cout << '\n';
}

int get_root(int u) {
	if (u != par[u]) {
		u = get_root(par[u]);
	}
	return par[u];
}

void merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u != v) {
		par[v] = u;
		vector<int> tmp(sz[u] + sz[v] + 1, 0);
		for (int i = 0; i <= sz[u]; ++i) {
			for (int j = 0; j <= sz[v]; ++j) {
				tmp[i + j] = add(tmp[i + j], mul(dp[u][i], dp[v][j]));
			}
		}
		dp[u] = tmp;
		sz[u] += sz[v];
		esz[u] += esz[v];
	}
	++esz[u];
	if ((sz[u] * (sz[u] - 1)) / 2 == esz[u]) {
		dp[u][1] = add(dp[u][1], 1);
	}
	// cout << "merge " << u << ' ' << v << endl;
	// cout << sz[u] << ' ' << esz[u] << endl;
	// for (auto& i : dp[u]) {
	// 	cout << i << ' ';
	// }
	// cout << endl << endl;
}