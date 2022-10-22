/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
map <int, int> mp;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	ll ans = 0;
	mp[0]++;
	int n, ps = 0, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ps = ps ^ x;
		int l = min(ps, (1 << k) - ps - 1);
		mp[l]++;
	}
	for (auto [x, y] : mp) {
		ll a = y / 2, b = (y + 1) / 2;
		ans += a * (a - 1) / 2;
		ans += b * (b - 1) / 2;
	}
	cout << (ll)n * (ll)(n + 1) / 2 - ans;
}