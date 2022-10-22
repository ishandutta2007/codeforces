/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b;
	cin >> a >> b;
	int n = a + b;
	int x = (a + b) / 2, y = n - x;
	set <int> v;
	int mn, mx;
	int x2 = x, a2 = a, y2 = y, b2 = b;
	x = x - (min(x, a));
	a -= min(x2, a);
	mn = a + x;
	x = x2;
	a = a2;
	y = y2;
	y = y - (min(y, a));
	a -= min(y2, a);
	mx = min(y2, a2) + x - a;
	x = x2;
	a = a2;
	y = y2;
	for (int i = mn; i <= mx; i += 2) {
		v.insert(i);
	}
	swap(x, y);
	swap(x2, y2);
	x2 = x, a2 = a;
	x = x - (min(x, a));
	a -= min(x2, a);
	mn = a + x;
	x = x2;
	a = a2;
	y = y2;
	y = y - (min(y, a));
	a -= min(y2, a);
	mx = min(y2, a2) + x - a;
	x = x2;
	for (int i = mn; i <= mx; i += 2) {
		v.insert(i);
	}
	cout << v.size() << '\n';
	for (auto x : v) {
		cout << x << ' ';
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}