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
	int n;
	cin >> n;
	int x = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == n)
			x = i;
	}
	if (x != 0 && x != n - 1) {
		cout << -1 << '\n';
	} else {
		if (x == 0) {
			reverse(a + 1, a + n);
		} else {
			reverse(a, a + n - 1);
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}