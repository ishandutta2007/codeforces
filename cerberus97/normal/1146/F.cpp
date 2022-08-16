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

const int N = 2e5 + 10, mod = 998244353;

vector<int> g[N];
ll ways[N], sum[N];

ll inverse(ll x);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		int p; cin >> p;
		g[p].pb(i);
	}
	for (int u = n; u >= 1; --u) {
		if (g[u].empty()) {
			ways[u] = sum[u] = 1;
			continue;
		}
		ll temp = 1, pways = 1;
		for (auto &v : g[u]) {
			temp *= (ways[v] + sum[v]);
			temp %= mod;
			pways *= ways[v];
			pways %= mod;
		}
		sum[u] = temp - pways + mod;
		sum[u] %= mod;
		ways[u] = temp;
		for (auto &v : g[u]) {
			temp = pways * inverse(ways[v]);
			temp %= mod;
			temp *= sum[v];
			temp %= mod;
			ways[u] += mod - temp;
		}
		ways[u] %= mod;
	}
	cout << ways[1] << endl;
}

ll inverse(ll x) {
	ll res = 1, e = mod - 2;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e /= 2;
	}
	return res;
}