/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

void solve() {
	int n, mn = INT_MAX, x = 0;
	cin >> n;
	map <int, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mp[a[i]]++;
	}
	int mx = 0;
	for (auto [x, y] : mp)
		mx = max(mx, y);
	cout << n - mx;
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}