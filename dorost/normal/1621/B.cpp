/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
map <pair <int, int>, int> mp;

void solve() {
	int n;
	cin >> n;
	mp.clear();
	int ans = 0;
	int mn = INT_MAX, mx = INT_MIN;
	int a1 = INT_MAX, a2 = INT_MAX;
	for (int i = 0; i < n; i++) {
		int l, r, c;
		cin >> l >> r >> c;
		if (mp[{l, r}] == 0) {
			mp[{l, r}] = c;
		} else {
			mp[{l, r}] = min(c, mp[{l, r}]);
		}
		if (l < mn) {
			mn = l;
			a1 = c;
		} else if (mn == l) {
			a1 = min(a1, c);
		}
		if (r > mx) {
			mx = r;
			a2 = c;
		} else if (mx == r) {
			a2 = min(a2, c);
		}
		cout << min(a1 + a2, (mp[{mn, mx}] == 0 ? INT_MAX : mp[{mn, mx}])) << '\n';
	}
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