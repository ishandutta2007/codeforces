/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n, ans = 0, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int mn = a[0], mx = a[0];
	for (int i = 1; i < n; i++) {
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		if (mx - mn > 2 * x) {
			mx = a[i];
			mn = a[i];
			ans++;
		}
	}
	cout << ans << '\n';
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