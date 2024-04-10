/* 	* In the name of GOD 
	* Ftr max vhwxyhkvxl ux pbma rhn :)) */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 105;
int a[N];

void solve() {
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i == n - 1)
			continue;
		if (a[i] <= k) {
			k -= a[i];
			ans += a[i];
			a[i] = 0;
		} else {
			ans += k;
			a[i] -= k;
			k = 0;
		}
	}
	a[n - 1] += ans;
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
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