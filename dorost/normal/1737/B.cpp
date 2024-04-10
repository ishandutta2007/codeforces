/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int f(int n) {
	int l = 0, r = 1000 * 1000 * 1000 + 10;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (mid * mid <= n)
			l = mid;
		else
			r = mid;
	}
	int ans = l;
	l = 0, r = 1000 * 1000 * 1000 + 10;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (mid * (mid + 1) <= n)
			l = mid;
		else
			r = mid;
	}
	ans += l;
	l = 0, r = 1000 * 1000 * 1000 + 10;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (mid * (mid + 2) <= n)
			l = mid;
		else
			r = mid;
	}
	ans += l;
	return ans;
}

void solve() {
	int l, r;
	cin >> l >> r;
	cout << f(r) - f(l - 1) << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}