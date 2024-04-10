/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];

void solve() {
	ll ans = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	if (k >= n) {
		for (int i = 0; i < n; i++)
			ans += a[i];
	} else {
		ll mx = 0;
		ll sum = 0;
		for (int i = 0; i < k; i++)
			sum += a[i];
		mx = max(mx, sum);
		for (int i = 1; i <= n - k; i++) {
			sum -= a[i - 1];
			sum += a[i + k - 1];
			mx = max(mx, sum);
		}
		ans = mx;
	}
	if (k <= n) {
		ans += (k * (k - 1)) / 2;
	} else {
		ans += (k * (k - 1)) / 2;
		k -= n;
		ans -= (k * (k - 1)) / 2;
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