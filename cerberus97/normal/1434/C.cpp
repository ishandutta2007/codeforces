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

const int N = 1e5 + 10;

ll check(ll a, ll b, ll c, ll d, ll k, ll m);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > b * c) {
			cout << -1 << '\n';
			continue;
		}
		ll mx_k = (c + d - 1) / d + 1;
		ll ans = max(check(a, b, c, d, 1, mx_k), check(a, b, c, d, mx_k, mx_k));
		ll num = (2 * a + b * d), den = (2 * b * d);
		ans = max(ans, check(a, b, c, d, num / den, mx_k));
		ans = max(ans, check(a, b, c, d, (num + den - 1) / den, mx_k));
		cout << ans << '\n';
	}
}

ll check(ll a, ll b, ll c, ll d, ll k, ll m) {
	if (k < 1 or k > m) {
		return 0;
	}
	return a * k - (b * d * k * (k - 1) / 2);
}