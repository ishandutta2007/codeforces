/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 11;
int a[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	k++;
	for (int i = 0; i < n; i++) {
		int mx = (i == n - 1 ? LLONG_MAX : (a[i + 1] - a[i]));
		int h = 1;
		if (mx != LLONG_MAX) {
			int r = 1;
			for (int i = 0; i < mx; i++) 
				r *= 10;
			r -= 1;
			mx = r;
		}
		for (int j = 0; j < a[i]; j++) 
			h *= 10;
		if (k <= mx) {
//			cout << h << ' ' << k << '\n';
			ans += h * k;
			k = 0;
		} else {
			ans += h * mx;
			k -= mx;
		}
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