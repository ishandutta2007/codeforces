/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
#define int long long
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int mx = 0;
	for (int i = 0; i < n - 1; i++) {
		mx = max(mx, a[i] * a[i + 1]);
	}
	cout << mx << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}