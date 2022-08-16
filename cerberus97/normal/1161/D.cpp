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

const int N = 2e3 + 10, mod = 998244353;

vector<pii> g[N];
bool seen[N];
int val[N];
ll p2[N];

bool assign(int u, int x);

int main() {
	p2[0] = 1;
	for (int i = 1; i < N; ++i) {
		p2[i] = (2 * p2[i - 1]) % mod;
	}
	string s; cin >> s;
	int n = s.length();
	ll ans = 0;
	for (int p = 1; p < n; ++p) {
		memset(seen, 0, sizeof(seen));
		for (int i = 0; i < 2 * n; ++i) {
			g[i].clear();
		}
		for (int i = 0, j = n - 1; i < j; ++i, --j) {
			g[i + n].pb({j + n, 0});
			g[j + n].pb({i + n, 0});
		}
		for (int i = 0; i < n; ++i) {
			if (s[i] != '?') {
				g[i].pb({i + n, s[i] - '0'});
				g[i + n].pb({i, s[i] - '0'});
			}
		}
		for (int i = p, j = n - 1; i < j; ++i, --j) {
			g[i].pb({j, 0});
			g[j].pb({i, 0});
		}
		bool ok = true;
		ok = ok and assign(n, 1);
		for (int i = 0; i < p; ++i) {
			ok = ok and assign(i, 0);
		}
		if (p < n) {
			ok = ok and assign(p, 1);
		}
		int ctr = 0;
		for (int i = 0; i < 2 * n; ++i) {
			if (!seen[i]) {
				ok = ok and assign(i, 0);
				++ctr;
			}
		}
		if (ok) {
			ans += p2[ctr];
			ans %= mod;
		}
	}
	cout << ans << endl;
}

bool assign(int u, int x) {
	if (seen[u]) {
		return val[u] == x;
	}
	seen[u] = true;
	val[u] = x;
	bool ok = true;
	for (auto &e : g[u]) {
		ok = ok and assign(e.first, e.second ^ x);
	}
	return ok;
}