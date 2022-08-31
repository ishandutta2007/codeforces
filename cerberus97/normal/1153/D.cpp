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

const int N = 3e5 + 10;

int op[N], sz[N];
vector<int> g[N];

int solve(int u);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> op[i];
	}
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		g[p].pb(i);
	}
	cout << solve(1) << endl;
}

int solve(int u) {
	if (g[u].empty()) {
		sz[u] = 1;
		return 1;
	}
	int sum = 0, mx = -N;
	for (auto &v : g[u]) {
		int p = solve(v);
		sz[u] += sz[v];
		mx = max(mx, p - sz[v]);
		sum += sz[v] - p + 1;
	}
	if (op[u] == 0) {
		return sz[u] - sum + 1;
	} else {
		return sz[u] + mx;
	}
}