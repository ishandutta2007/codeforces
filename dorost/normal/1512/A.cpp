/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	if (a[0] != a[1]) {
		if (a[0] != a[2]) {
			cout << 1 << ' ';
		} else {
			cout << 2 << ' ';
		}
		return;
	}
	int x = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] != x) {
			cout << i + 1 << ' ';
			return;
		}
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}