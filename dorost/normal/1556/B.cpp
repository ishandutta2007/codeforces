/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];	

void solve() {
	int n;
	cin >> n;
	vector <int> v;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0)
			v.push_back(i), x++;
		else
			y++;
	}
	if (x == y) {
		int mn = INT_MAX, ans = 0;
		for (int i = 0; i < n; i += 2) {
			ans += abs(v[i / 2] - i);
		}
		mn = min(mn, ans);
		ans = 0;
		for (int i = 1; i < n; i += 2) {
			ans += abs(v[i / 2] - i);
		}
		mn = min(mn, ans);
		cout << mn << ' ';
	} else if (x + 1 == y) {
		int ans = 0;
		for (int i = 1; i < n; i += 2) {
			ans += abs(v[i / 2] - i);
		}
		int mn = ans;
		cout << mn << ' ';
	} else if (x == y + 1) {
		int ans = 0;
		for (int i = 0; i < n; i += 2) {
			ans += abs(v[i / 2] - i);
		}
		int mn = ans;
		cout << mn << ' ';
	} else {
		cout << -1 << ' ';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}