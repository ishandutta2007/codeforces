/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N];

void solve() {
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < k; i++) {
		ans -= a[i];
		ans -= a[i + k];
		ans += a[i + k] / a[i];
	}
	cout << ans << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}