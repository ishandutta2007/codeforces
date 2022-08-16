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

const int N = 2e5 + 10;

vector<int> g[N];
int seen[N];

int dfs(int u, int n);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<pii> rooks(m);
		for (int i = 1; i <= 2 * n; ++i) {
			g[i].clear();
			seen[i] = 0;
		}
		for (auto& [x, y] : rooks) {
			cin >> x >> y;
			if (x != y) {
				g[x].pb(y);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (!seen[i]) {
				ans += dfs(i, n);
			}
		}
		cout << ans << '\n';
	}
}

int dfs(int u, int n) {
	int ans = (!g[u].empty());
	seen[u] = 1;
	for (auto& v : g[u]) {
		if (!seen[v]) {
			ans += dfs(v, n);
		} else if (seen[v] == 1) {
			++ans;
		}
	}
	seen[u] = 2;
	return ans;
}