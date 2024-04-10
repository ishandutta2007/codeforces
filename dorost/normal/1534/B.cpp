/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 401234;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	a[n] = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (a[0] > a[1]) {
				ans += a[0] - a[1];
				a[0] = a[1];
			}
		} else if (i == n - 1 && n != 1) {
			if (a[n - 1] > a[n - 2]) {
				ans += a[n - 1] - a[n - 2];
				a[n - 1] = a[n - 2];
			}
		} else {
			if (a[i] > a[i + 1] && a[i] > a[i - 1]) {
				int x = max(a[i - 1], a[i + 1]);
				ans += a[i] - x;
				a[i] = x;
			}
		}
	}
	ans += a[0] + a[n - 1];
	for (int i = 1; i < n; i++) {
		ans += abs(a[i] - a[i - 1]);
	}
	cout << ans << '\n';
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