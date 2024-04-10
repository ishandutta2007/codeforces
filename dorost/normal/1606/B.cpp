/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	int x = 1;
	int ans = 0;
	while (x <= k && x < n) {
		x *= 2;
		ans++;
	}
	if (x >= n)
		cout << ans;
	else {
		cout << ans + (n - x + k - 1) / k;
	}
	cout << ' ';
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