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

const int N = 2e5 + 10;

int par[N], sz[N];

int get_root(int u);
bool merge(int u, int v);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		merge(u, v);
	}
	int ans = 0;
	for (int l = 1; l <= n; ) {
		int cur = sz[get_root(l)];
		for (int j = l; j <= l + cur - 1; ++j) {
			ans += merge(l, j);
			cur = sz[get_root(l)];
		}
		l += cur;
	}
	cout << ans << endl;
}

int get_root(int u) {
	if (u != par[u]) {
		par[u] = get_root(par[u]);
	}
	return par[u];
}

bool merge(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u == v) {
		return false;
	}
	sz[u] += sz[v];
	par[v] = u;
	return true;
}