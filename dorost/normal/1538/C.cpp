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
	int n, l, r;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int in1 = upper_bound(a + i + 1, a + n, r - a[i]) - (a + i);
		int in2 = upper_bound(a + i + 1, a + n, l - a[i] - 1) - (a + i);
		ans += in1 - in2;
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