/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	string b;
	cin >> b;
	string a;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			a += '1';
		} else {
			if (a[i - 1] - '0' + b[i - 1] - '0' == b[i] - '0' + 1) {
				a += '0';
			} else {
				a += '1';
			}
		}
	}
	cout << a << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}