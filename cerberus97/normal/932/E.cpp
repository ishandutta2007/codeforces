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

const int K = 5e3 + 10, mod = 1e9 + 7;

bool seen[K][K];
ll dp[K][K];

ll solve(int a, ll b, int c);
ll pwr(ll x, ll e);

int main() {
	ll n, k;
	cin >> n >> k;
	cout << solve(0, n, k);
}

ll solve(int a, ll b, int c) {
	if (seen[a][c]) {
		return dp[a][c];
	} else {
		ll ans = 0;
		if (b < 0) {
			ans = 0;
		} else if (!c) {
			ans = pwr(2, b);
		} else {
			ans = b * solve(a + 1, b - 1, c - 1);
			ans += a * solve(a, b, c - 1);
			ans %= mod;
		}
		seen[a][c] = true;
		dp[a][c] = ans;
		return ans;
	}
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		x = (x * x) % mod;
		e >>= 1;
	}
	return res;
}