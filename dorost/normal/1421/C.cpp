/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	int n = (int)s.size();
	cout << 4 << '\n';
	cout << "L " << n - 1 << '\n';
	cout << "R " << 2 * n - 3 << '\n';
	cout << "L " << 2 * n - 2 << '\n';
	cout << "L " << 2 << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}