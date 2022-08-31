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
ll fact[N];

ll dfs(int u, int p, bool circle);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 2; i <= n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	ll ans = dfs(1, 0, true) * n;
	ans %= mod;
	cout << ans << endl;
}

ll dfs(int u, int p, bool circle) {
	int ch = 0;
	ll ans = 1;
	for (auto &v : g[u]) {
		if (v != p) {
			ans *= dfs(v, u, false);
			ans %= mod;
			++ch;
		}
	}
	ans *= (circle ? fact[ch] : fact[ch + 1]);
	ans %= mod;
	return ans;
}