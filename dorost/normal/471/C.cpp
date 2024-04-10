/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	ll n;
	cin >> n;
	int ans = 0;
	for (ll sz = 1; sz < 1000 * 1000 * 2; sz++) {
		if ((n + sz) % 3)
			continue;;
		ll x = (n + sz) / 3;
		if (sz * (sz + 1) / 2 <= x) {
			ans++;
		}
	}
	cout << ans;
}