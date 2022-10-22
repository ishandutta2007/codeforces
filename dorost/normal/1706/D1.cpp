/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = INT_MAX;
	for (int mx = 0; mx <= a[n - 1]; mx++) {
		int mn = INT_MAX;
		bool f = true;
		for (int i = 0; i < n; i++) {
			int wef;
			if (a[i] <= mx)
				wef = a[i];
			else if (a[i] / k > mx)
				f = false;
			else {
				int l = k;
				int r = 0;
				while (l - r > 1) {
					int mid = (l + r) / 2;
					if (a[i] / mid <= mx) {
						l = mid;
					} else {
						r = mid;
					}
				}
				wef = a[i] / l;
			}
			mn = min(mn, wef);
		}
		if (f)
			ans = min(ans, mx - mn);
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