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

const ll N = 1e5 + 10, mod = 1e9 + 7;

ll pwr(ll x, ll e);

int main() {
	ll x, k;
	cin >> x >> k;
	if (x == 0) {
		cout << 0;
		return 0;
	}
	x %= mod;
	ll p2 = pwr(2, k);
	ll ans = p2 * (2 * x + mod - 1) + 1;
	cout << ans % mod;
}

ll pwr(ll x, ll e) {
	ll res = 1;
	while (e) {
		if (e & 1) {
			res = (res * x) % mod;
		}
		e >>= 1;
		x = (x * x) % mod;
	}
	return res;
}