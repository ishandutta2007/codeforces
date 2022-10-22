/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	int a, b, mn = INT_MAX;
	cin >> a >> b;
	for (int i = b; i <= b + 50; i++) {
		int ans = i - b;
		if (i == 1) 
			continue;
		int x = a;
		while (x != 0) {
			x /= i;
			ans++;
		}
		mn = min(mn, ans);
	}
	cout << mn << ' ';
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