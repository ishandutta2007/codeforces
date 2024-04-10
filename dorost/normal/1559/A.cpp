/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N];

void solve() {
	int n;
	cin >> n;
	cin >> a[0];
	int x = a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		x = x & a[i];
	}
	cout << x << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}