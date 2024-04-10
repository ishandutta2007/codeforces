/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int l, r, x, y;
	cin >> l >> r >> x >> y;
	if (y % x) {
		cout << 0 << '\n';
		return 0;
	}
	y = y / x;
	l = (l + x - 1) / x;
	r = r / x;
	ll ans = 0;
	for (int i = 1; i * i <= y; i++) {
		if (y % i)
			continue;
		if (i >= l && i <= r && y / i >= l && y / i <= r) {
			if (__gcd(i, y / i) == 1) {
				if (i * i == y)
					ans++;
				else 
					ans += 2;
			}
		}
	}
	cout << ans;
}