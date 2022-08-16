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

ll ctr[N], dp[N];
vector<int> factors[N];

ll pwr(ll x, ll e);

int main() {
	fast_cin();
	int m; cin >> m;
	for (int i = 1; i <= m; ++i) {
		for (int j = i; j <= m; j += i) {
			factors[j].pb(i);
		}
	}
	ll sum = 0;
	dp[1] = 0;
	for (int i = 2; i <= m; ++i) {
		int s = factors[i].size();
		ll temp = m;
		for (int j = s - 1; j >= 0; --j) {
			ctr[j] = m / factors[i][j];
			for (int k = j + 1; k < s; ++k) {
				if (factors[i][k] % factors[i][j] == 0) {
					ctr[j] -= ctr[k];
				}
			}
			temp += ctr[j] * dp[factors[i][j]];
		}
		temp %= mod;
		dp[i] = temp * pwr(m - ctr[s - 1], mod - 2);
		dp[i] %= mod;
		sum += dp[i];
	}
	sum %= mod;
	sum *= pwr(m, mod - 2);
	++sum;
	sum %= mod;
	cout << sum << endl;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e /= 2;
	}
	return res;
}