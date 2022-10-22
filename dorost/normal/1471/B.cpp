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
	vector <pair <int, int>> a;
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int y;
		cin >> y;
		a.push_back({y, 1});
	}
	for (int i = 0; i < a.size(); i++) {
		if (a[i].F % x)
			break;
		a.push_back({a[i].F / x, a[i].S * x});
	}
	int sum = 0;
	for (int i = 0; i < a.size(); i++) {
		sum += a[i].F * a[i].S;
	}
	cout << sum << '\n';
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