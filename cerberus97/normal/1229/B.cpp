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

const int N = 1e5 + 10, mod = 1e9 + 7;

ll x[N];
vector<int> g[N];
vector<pll> gcds[N];
ll ans = 0;

void dfs(int u, int p);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1, 0);
	cout << ans << endl;
}

void dfs(int u, int p) {
	gcds[u].pb({x[u], 1});
	for (auto &i : gcds[p]) {
		ll prv = i.first, cnt = i.second;
		ll d = __gcd(prv, gcds[u].back().first);
		if (d == gcds[u].back().first) {
			gcds[u].back().second += cnt;
		} else {
			gcds[u].push_back({d, cnt});
		}
	}
	for (auto &i : gcds[u]) {
		ans += i.first * i.second;
		ans %= mod;
	}
	for (auto &v : g[u]) {
		if (v != p) {
			dfs(v, u);
		}
	}
}