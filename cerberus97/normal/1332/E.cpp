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

const int N = 1e5 + 10, mod = 998244353;

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

int main() {
	fast_cin();
	int n, m, l, r;
	cin >> n >> m >> l >> r;
	ll a = ll(n) * m;
	ll x = (r / 2) - ((l - 1) / 2);
	ll y = (r - l + 1) - x;
	if (a % 2 == 1) {
		cout << pwr(x + y, a) % mod << '\n';
		return 0;
	}
	ll ans = (pwr(x + y, a) + pwr(abs(x - y), a) + mod) % mod;
	ans = (ans * pwr(2, mod - 2)) % mod;
	cout << ans << endl;
}