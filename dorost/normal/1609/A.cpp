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
	ll x = 1, sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		while (a[i] % 2 == 0) {
			x *= 2;
			a[i] /= 2;
		}
		sum += a[i];
	}
	cout << sum + (x - 1) * *max_element(a, a + n) << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}