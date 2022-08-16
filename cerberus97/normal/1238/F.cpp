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

vector<int> g[N];
int ans = 0;

int solve(int u, int p);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; ++i) {
			g[i].clear();
		}
		for (int i = 1; i < n; ++i) {
			int u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		ans = 0;
		solve(1, 0);
		cout << ans + 2 << '\n';
	}
}

int solve(int u, int p) {
	int deg = (p != 0);
	int mx1 = 0, mx2 = 0;
	for (auto &v : g[u]) {
		if (v != p) {
			++deg;
			int cand = solve(v, u);
			if (cand > mx1) {
				mx2 = mx1;
				mx1 = cand;
			} else if (cand > mx2) {
				mx2 = cand;
			}
		}
	}
	ans = max(ans, mx1 + mx2 + deg - 1);
	return mx1 + deg - 1;
}