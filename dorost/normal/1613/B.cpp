/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N];

void solve() {
	int n, mn = INT_MAX;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
	}
	int cnt = n / 2;
	for (int i = 0; i < n; i++) {
		if (a[i] == mn)
			continue;
		cout << a[i] << ' ' << mn << '\n';
		cnt--;
		if (cnt == 0)
			break;
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}