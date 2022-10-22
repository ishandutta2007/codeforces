/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234, M = 1000 * 1000 * 1000 + 7;
int a[N], w[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		w[a[i]] = i;
	}
	int l = w[0], r = w[0], t = 1;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		if (w[i] >= l && w[i] <= r) {
			ans *= (r - l + 1 - t);
			ans %= M;
			t++;
		} else {
			t++;
			l = min(l, w[i]);
			r = max(r, w[i]);
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