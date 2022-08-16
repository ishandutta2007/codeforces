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

const int N = 1e5 + 10, A = 52, M = 54, mod = 1e9 + 7;

ll ctr[M];
ll fact[N], finv[N];
ll dp_pref[M][N / 2], dp_suff[M][N / 2];
ll ans[M][M];

ll pwr(ll x, ll e);

int main() {
	fast_cin();
	string s; cin >> s;
	int n = s.length() / 2;
	for (auto &i : s) {
		i = ((i <= 'Z') ? (i - 'A' + 1) : (i - 'a' + 27));
		++ctr[i];
	}
	fact[0] = finv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
		finv[i] = pwr(fact[i], mod - 2);
	}
	ll prod_all = 1;
	for (int i = 1; i <= A; ++i) {
		prod_all *= finv[ctr[i]];
		prod_all %= mod;
	}
	dp_suff[A + 1][0] = 1;
	for (int i = A + 1; i > 1; --i) {
		for (int j = 0; j <= n; ++j) {
			dp_suff[i - 1][j] += dp_suff[i][j];
			dp_suff[i - 1][j] %= mod;
			if (ctr[i - 1] and j + ctr[i - 1] <= n) {
				dp_suff[i - 1][j + ctr[i - 1]] += dp_suff[i][j];
				dp_suff[i - 1][j + ctr[i - 1]] %= mod;
			}
		}
	}
	for (int x = 1; x < A; ++x) {
		memset(dp_pref, 0, sizeof(dp_pref));
		int temp = ctr[x];
		ctr[x] = 0;
		dp_pref[0][0] = 1;
		for (int i = 0; i < A; ++i) {
			for (int j = 0; j <= n; ++j) {
				dp_pref[i + 1][j] += dp_pref[i][j];
				if (dp_pref[i + 1][j] >= mod) {
					dp_pref[i + 1][j] -= mod;
				}
				int sum = j + ctr[i + 1];
				if (ctr[i + 1] and sum <= n) {
					dp_pref[i + 1][sum] += dp_pref[i][j];
					if (dp_pref[i + 1][sum] >= mod) {
						dp_pref[i + 1][sum] -= mod;
					}
				}
			}
		}
		for (int y = x + 1; y <= A; ++y) {
			ans[x][y] = 0;
			if (ctr[x] + ctr[y] > n) {
				continue;
			}
			for (int sum = 0; sum <= n; ++sum) {
				if (dp_pref[y - 1][sum]) {
					ans[x][y] += dp_pref[y - 1][sum] * dp_suff[y + 1][n - sum];
					ans[x][y] %= mod;
				}
			}
		}
		ctr[x] = temp;
	}
	// cout << dp_suff[1][n] << endl;
	int q; cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		x = s[x]; y = s[y];
		if (x == y) {
			ll res = (dp_suff[1][n] * fact[n]) % mod;
			res = (res * fact[n]) % mod;
			res = (res * prod_all) % mod;
			cout << res << '\n';
		} else {
			if (x > y) {
				swap(x, y);
			}
			ll res = (2 * ans[x][y] * fact[n]) % mod;
			res = (res * fact[n]) % mod;
			res = (res * prod_all) % mod;
			cout << res << '\n';
		}
	}
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		e /= 2;
		x = (x * x) % mod;
	}
	return res;
}