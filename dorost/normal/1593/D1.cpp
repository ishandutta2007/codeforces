/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 41;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int x = *min_element(a, a + n), ans = 0, y = *max_element(a, a + n);
	if (x == y) {
		cout << -1 << ' ';
		return;
	}
	for (int i = 0; i < n; i++) {
		ans = __gcd(ans, a[i] - x);
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