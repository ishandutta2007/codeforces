/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012;
ll a[N], b[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll mn = LLONG_MAX;
	for (int i = 0; i < n; i++) {
		ll ans = 0;
		for (int j = 0; j < n; j++)
			b[j] = 0;
		for (int j = i + 1; j < n; j++) {
			b[j] = ((b[j - 1] / a[j]) + 1) * a[j];
			ans += ((b[j - 1] / a[j]) + 1);
		}
		for (int j = i - 1; j >= 0; j--) {
			b[j] = ((b[j + 1] / a[j]) + 1) * a[j];
			ans += ((b[j + 1] / a[j]) + 1);
		}
		mn = min(mn, ans);
	}
	cout << mn;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}