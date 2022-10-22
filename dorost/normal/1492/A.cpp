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
	int p, a, b, c;
	cin >> p >> a >> b >> c;
	cout << min({(p + a - 1) / a * a - p, (p + b - 1) / b * b - p, (p + c - 1) / c * c - p}) << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}