/* 	* In the name of GOD *  */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n;
	cin >> n;
	if (n % 2050) {
		cout << -1 << ' ';
		return;
	}
	n /= 2050;
	int ans = 0;
	while (n) {
		ans += n % 10;
		n /= 10;
	}
	cout << ans << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}