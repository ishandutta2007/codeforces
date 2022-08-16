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

const int N = 1e5 + 10;

inline ll pwr(ll x, ll e, ll mod);

int main() {
	ll a, b, p, x, ans = 0;
	cin >> a >> b >> p >> x;
	ll temp = pwr(a, p - 2, p);
	ll d = temp;
	for (ll k = 1; k <= p - 1 and k <= x; ++k) {
		ll c = (x - k) / (p - 1);
		ll e = (k - ((b * d) % p) + p) % p;
		if (c >= e) {
			ans += (c - e) / p + 1;
		}
		d = (d * temp) % p;
	}
	cout << ans;
}

inline ll pwr(ll x, ll e, ll mod) {
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