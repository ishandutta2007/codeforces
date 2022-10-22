/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	int mn = INT_MAX;
	for (int x = 1; x <= 63244; x++) {
		int ans = x - 1;
		ans += (n - 1) / x;
		mn = min(mn, ans);
	}
	cout << mn << '\n';
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