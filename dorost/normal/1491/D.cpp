/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int a, b;
	cin >> a >> b;
	bool f = (a <= b);
	vector <bool> x, y;
	while (a) {
		x.push_back(a % 2);
		a /= 2;
	}
	while (b) {
		y.push_back(b % 2);
		b /= 2;
	}
	if (x.size() <= y.size()) {
		while (x.size() < y.size())
			x.push_back(0);
	} else {
		while (x.size() > y.size())
			y.push_back(0);
	}
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	a = 0, b = 0;
	for (int i = x.size() - 1; i >= 0; i--) {
//		cout << x[i] << ' ' << y[i] << '\n';
		if (x[i])
			a++;
		if (y[i])
			b++;
		if (a < b)
			f = false;
	}
	cout << (f ? "YES" : "NO") << ' ';
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