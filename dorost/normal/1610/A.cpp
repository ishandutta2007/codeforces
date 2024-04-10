/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1)
		cout << 0;
	else if (n == 1 || m == 1)
		cout << 1;
	else
		cout << 2;
	cout << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}