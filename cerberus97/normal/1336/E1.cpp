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

const int M = 35, H = 20, B = 15, mod = 998244353;

void add(int& a, int b) {
	a += b;
	if (a > mod) {
		a -= mod;
	}
}

int dp[M + 1][(1 << B)];

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (auto& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end(), greater<ll>());
	vector<ll> basis;
	ll in_basis = 0, free = (1ll << m) - 1;
	for (auto& i : a) {
		for (auto& val : basis) {
			if ((i ^ val) < i) {
				i ^= val;
			}
		}
		if (i != 0) {
			basis.pb(i);
			ll cur = (1ll << __lg(i));
			in_basis |= cur;
			free ^= cur;
		}
	}
	vector<int> ans(m + 1, 0);
	int sz = basis.size();
	if (sz <= H) {
		int tot = (1 << sz);
		for (int mask = 0; mask < tot; ++mask) {
			ll val = 0;
			for (int i = 0; i < sz; ++i) {
				if ((mask >> i) & 1) {
					val ^= basis[i];
				}
			}
			++ans[__builtin_popcountll(val)];
		}
	} else {
		for (int i = sz - 1; i >= 0; --i) {
			for (int j = 0; j < i; ++j) {
				if ((basis[j] ^ basis[i]) < basis[j]) {
					basis[j] ^= basis[i];
				}
			}
		}
		for (auto& val : basis) {
			int nval = 0;
			for (int i = 0; i < m; ++i) {
				if ((free >> i) & 1) {
					nval <<= 1;
					if ((val >> i) & 1) {
						nval |= 1;
					}
				}
			}
			val = nval;
		}
		free = (1 << __builtin_popcountll(free)) - 1;
		dp[0][0] = 1;
		for (int i = 0; i < sz; ++i) {
			for (int j = i; j >= 0; --j) {
				for (int mask = 0; mask <= free; ++mask) {
					add(dp[j + 1][mask ^ basis[i]], dp[j][mask]);
				}
			}
		}
		for (int j = 0; j <= sz; ++j) {
			for (int mask = 0; mask <= free; ++mask) {
				add(ans[__builtin_popcount(mask) + j], dp[j][mask]);
			}
		}
	}
	int mul = 1;
	for (int i = 0; i < n - sz; ++i) {
		mul = (2 * mul) % mod;
	}
	for (int i = 0; i <= m; ++i) {
		cout << (ll(ans[i]) * mul) % mod << ' ';
	}
	cout << endl;
}