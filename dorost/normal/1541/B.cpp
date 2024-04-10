/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
pair <int, int> a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].F;
		a[i].S = i;
	}
	sort(a, a + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j].F > 2 * n / (i + 1)) {
				break;
			}
			if (a[i].F * a[j].F == a[i].S + a[j].S + 2) {
				ans++;
			}
		}
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