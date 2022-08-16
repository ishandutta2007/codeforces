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

const int N = 5e5 + 10, mod = 1e9 + 7;

int par[N];
bool have[N];

int get_root(int u);
bool merge(int u, int v);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	vector<int> basis;
	for (int i = 1; i <= m; ++i) {
		par[i] = i;
	}
	for (int i = 1; i <= n; ++i) {
		int k; cin >> k;
		if (k == 1) {
			int x; cin >> x;
			x = get_root(x);
			if (!have[x]) {
				have[x] = true;
				basis.pb(i);
			}
		} else {
			int u, v;
			cin >> u >> v;
			if (merge(u, v)) {
				basis.pb(i);
			}
		}
	}
	int p2 = 1;
	for (int i = 0; i < basis.size(); ++i) {
		p2 = (2 * p2) % mod;
	}
	cout << p2 << ' ' << basis.size() << '\n';
	for (auto& i : basis) {
		cout << i << ' ';
	}
	cout << endl;
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
	if (u == v or (have[u] and have[v])) {
		return false;
	}
	par[v] = u;
	have[u] |= have[v];
	return true;
}