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

const int N = 1e5 + 10;

struct edge {
	int u, v, w;
	bool operator<(const edge &o) const {
		return w < o.w;
	}
};

edge e[N];
int par[N], sz[N], special[N];

int get_root(int u);
int merge(int u, int v);

int main() {
	fast_cin();
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; ++i) {
		int x; cin >> x;
		special[x]++;
	}
	for (int i = 0; i < m; ++i) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	sort(e, e + m);
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int root = merge(e[i].u, e[i].v);
		if (special[root] == k) {
			for (int j = 1; j <= k; ++j) {
				cout << e[i].w << ' ';
			}
			cout << endl;
			return 0;
		}
	}
}

int get_root(int u) {
	if (par[u] == u) {
		return u;
	} else {
		return get_root(par[u]);
	}
}

int merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return u;
	} 
	if (sz[u] > sz[v]) {
		swap(u, v);
	}
	sz[v] += sz[u];
	special[v] += special[u];
	par[u] = v;
	return v;
}