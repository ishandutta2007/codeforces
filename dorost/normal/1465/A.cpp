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
	string s;
	cin >> n >> s;
	int x = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] != ')') {
			x = i;
			break;
		}
	}
	int a = n - 1 - x, b = x + 1;
	if (a > b) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}