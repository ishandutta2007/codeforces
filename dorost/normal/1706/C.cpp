/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], b[N], ps[N], ss[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n - 1; i++) {
		b[i] = max(0LL, max(a[i - 1], a[i + 1]) - a[i] + 1);
	}
	int ans = 0;
	if (n % 2) {
		for (int i = 1; i < n - 1; i += 2)
			ans += b[i];
	} else {
		ps[0] = 0;
		int x = (n - 1) / 2;
		for (int i = 1; i < n - 1; i += 2) {
			ps[(i + 1) / 2] = ps[(i + 1) / 2 - 1] + b[i];
		}
		ss[0] = 0;
		for (int i = n - 2; i > 0; i -= 2) {
			ss[(n - i) / 2] = ss[(n - i) / 2 - 1] + b[i];
		}
		int mn = LLONG_MAX;
		for (int i = 0; i <= x; i++) {
			mn = min(mn, ps[i] + ss[x - i]);
		}
		ans = mn;
	}
	cout << ans << ' ';
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