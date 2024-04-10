/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	int mx = (a / 3) + (b / 3) + (c / 3);
	for (int i = 1; i < 3; i++) {
		if (min({a, b, c}) < i)
			continue;
		a--, b--, c--;
		mx = max(mx, i + (a / 3) + (b / 3) + (c / 3));

	}
	cout << mx;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}