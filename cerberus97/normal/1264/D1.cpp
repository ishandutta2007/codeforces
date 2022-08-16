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

int pref[N], suff[N];
int pref_blank[N], suff_blank[N];
ll ncr[N][N], ncr_sum[N][N];

ll choose(int n, int k);
ll choose_geq(int n, int k);

int main() {
	fast_cin();
	for (int i = 0; i < N; ++i) {
		ncr[i][i] = ncr[i][0] = 1;
		for (int j = 1; j < i; ++j) {
			ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
		}
		ncr_sum[i][i] = 1;
		for (int j = i - 1; j >= 0; --j) {
			ncr_sum[i][j] = (ncr_sum[i][j + 1] + ncr[i][j]) % mod;
		}
	}
	string s; cin >> s;
	int n = s.length();
	s = " " + s;
	for (int i = 1; i <= n; ++i) {
		pref[i] = pref[i - 1] + (s[i] == '(');
		pref_blank[i] = pref_blank[i - 1] + (s[i] == '?');
	}
	for (int i = n; i >= 1; --i) {
		suff[i] = suff[i + 1] + (s[i] == ')');
		suff_blank[i] = suff_blank[i + 1] + (s[i] == '?');
	}
	ll ans = 0;
	for (int d = 1; d <= n; ++d) {
		for (int i = 1; i < n; ++i) {
			if (s[i] == ')') {
				continue;
			} else if (pref[i - 1] >= d) {
				break;
			} else {
				ll ways = choose(pref_blank[i - 1], d - 1 - pref[i - 1]);
				ways *= choose_geq(suff_blank[i + 1], d - suff[i + 1]);
				ways %= mod;
				ans += ways;
				ans %= mod;
			}
		}
	}
	cout << ans << endl;
}

ll choose(int n, int k) {
	if (k < 0 or k > n) {
		return 0;
	} else {
		return ncr[n][k];
	}
}

ll choose_geq(int n, int k) {
	k = max(k, 0);
	if (k > n) {
		return 0;
	}
	return ncr_sum[n][k];
}