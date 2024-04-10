/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long 
int t[4];

void solve() {
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < 4; i++) {
		int k;
		cin >> k;
		int mn = INT_MAX, mx = INT_MIN;
		for (int i = 0; i < k; i++) {
			int a;
			cin >> a;
			mn = min(mn, a);
			mx = max(mx, a);
		}
		t[i] = mx - mn;
	}
	cout << max(w * max(t[0], t[1]), h * max(t[2], t[3])) << '\n';
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