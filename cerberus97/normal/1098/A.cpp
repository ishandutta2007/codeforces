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
const ll inf = 1e18 + 42;

vector<int> g[N];
ll a[N], s[N];

bool dfs(int u, int p);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		g[p].pb(i);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	if (dfs(1, 0)) {
		ll ans = 0;
		for (int i = 1; i <= n; ++i) {
			ans += a[i];
		}
		cout << ans << endl;
	} else {
		cout << -1 << endl;
	}
}

bool dfs(int u, int p) {
	if (s[u] != -1) {
		a[u] = s[u] - s[p];
		if (a[u] < 0) {
			return false;
		}
	} else if (g[u].empty()) {
		s[u] = s[p];
		a[u] = 0;
	} else {
		s[u] = inf;
		for (auto &v : g[u]) {
			s[u] = min(s[u], s[v]);
		}
		s[u] = max(s[u], s[p]);
		a[u] = s[u] - s[p];
		if (a[u] < 0) {
			return false;
		}
	}
	for (auto &v : g[u]) {
		if (!dfs(v, u)) {
			return false;
		}
	}
	return true;
}