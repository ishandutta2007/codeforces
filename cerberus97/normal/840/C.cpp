/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 320, mod = 1e9 + 7;

ll a[N], fact[N], choose[N][N], dp[N][N];
int c[N], s[N];
bool seen[N];

inline bool is_square(ll x);

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int g = 0;
	for (int i = 1; i <= n; ++i) {
		if (!seen[i]) {
			seen[i] = true;
			c[++g]  = 1;
			for (int j = i + 1; j <= n; ++j) {
				if (is_square(a[i] * a[j])) {
					seen[j] = true;
					++c[g];
				}
			}
		}
	}

	for (int i = 0; i <= n; ++i) {
		choose[i][0] = choose[i][i] = 1;
	}

	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
		for (int j = 1; j < i; ++j) {
			choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % mod;
		}
	}

	s[0] = 0;
	for (int i = 1; i <= g; ++i) {
		s[i] = s[i - 1] + c[i];
	}

	dp[0][0] = 1;
	for (int i = 0; i < g; ++i) {
		for (int j = 0; j <= s[i]; ++j) {
			ll temp = (dp[i][j] * fact[c[i + 1]]) % mod;
			int k   = s[i] - j + 1;
			for (int l = 0; l <= min(j, c[i + 1]); ++l) {
				ll mul = (temp * choose[j][l]) % mod;
				for (int r = max(0, 1 - l); r <= min(c[i + 1] - l, k); ++r) {
					int j_next = j - l + c[i + 1] - l - r;
					ll ways    = (mul  * choose[k][r]) % mod;
					ways       = (ways * choose[c[i + 1] - 1][l + r - 1]) % mod;
					dp[i + 1][j_next] += ways;
					dp[i + 1][j_next] %= mod;
				}
			}
		}
	}

	cout << dp[g][0] << endl;
}

inline bool is_square(ll x) {
	ll sq = round(sqrt(x));
	for (ll cand = sq - 2; cand <= sq + 2; ++cand) {
		if (cand * cand == x) {
			return true;
		}
	}

	return false;
}