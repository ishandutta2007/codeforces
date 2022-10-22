/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	cin >> n;
	if (n % 2) {
		cout << 'c';
		n--;
	}
	for (int i = 0; i < n / 2; i++) {
		cout << 'a';
	}
	if (n)
		cout << 'b';
	for (int i = 1; i < n / 2; i++) {
		cout << 'a';
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