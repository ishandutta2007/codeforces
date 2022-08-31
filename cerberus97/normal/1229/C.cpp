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

vector<int> big[N];
int deg[N];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v) {
			swap(u, v);
		}
		big[u].pb(v);
		// small[v].insert(u);
		++deg[u]; ++deg[v];
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += big[i].size() * (deg[i] - ll(big[i].size()));
	}
	cout << ans << '\n';
	int q; cin >> q;
	while (q--) {
		int u; cin >> u;
		ans -= big[u].size() * (deg[u] - ll(big[u].size()));
		for (auto &v : big[u]) {
			ans += deg[v] - 2 * ll(big[v].size()) - 1;
			big[v].pb(u);
		}
		big[u].clear();
		cout << ans << '\n';
	}
}