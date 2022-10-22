/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (auto c : s) {
		if (c == '1')
			a++;
		else
			b++;
	}
	if (a == b) {
		a--;
	}
	cout << min(a, b) << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}