/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mn = n + 1;
	for (int i = 0; i < n; i++) {
		int x = 0;
		for (int j = i; j < n; j++) {
			x = __gcd(x, a[j]);
			if (x == 1) {
				mn = min(mn, j - i + 1);
				break;
			}
		}
	}
	if (mn > n) {
		cout << -1;
		return;
	}
	int ans = mn - (mn == 1 ? 1 : 2);
	for (int i = 0; i < n; i++) {
		if (a[i] != 1) {
			ans++;
		}
	}
	cout << ans;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}