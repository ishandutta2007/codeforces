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

vector<int> g[N];
int sz[N];

void dfs(int u, int par);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		g[p].pb(i);
		g[i].pb(p);
	}
	dfs(1, 0);
	sort(sz + 1, sz + 1 + n);
	for (int i = 1; i <= n; ++i) {
		cout << sz[i] << ' ';
	}
}

void dfs(int u, int par) {
	sz[u] = 0;
	for (auto &v : g[u]) {
		if (v != par) {
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
	if (sz[u] == 0) {
		sz[u] = 1;
	}
}