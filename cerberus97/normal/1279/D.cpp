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

const int N = 1e6 + 10, mod = 998244353;

int k[N], cnt[N];
vector<int> v[N];

ll pwr(ll x, ll e);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> k[i];
		v[i].resize(k[i]);
		for (auto& j : v[i]) {
			cin >> j;
			++cnt[j];
		}
	}
	ll num = 0;
	for (int i = 1; i <= n; ++i) {
		ll temp = 0;
		for (auto& j : v[i]) {
			temp += cnt[j];
		}
		temp %= mod;
		temp *= pwr(k[i], mod - 2);
		temp %= mod;
		temp *= pwr(n, mod - 2);
		temp %= mod;
		temp *= pwr(n, mod - 2);
		temp %= mod;
		num += temp;
	}
	cout << num % mod << '\n';
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