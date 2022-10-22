/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 10123;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (a[0] == 1) {
		cout << n + 1 << ' ';
		for (int i = 1; i <= n; i++) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	if (a[n - 1] == 0) {
		for (int i = 1; i <= n + 1; i++) {
			cout << i << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == 0 && a[i + 1] == 1) {
			for (int j = 1; j <= (i + 1); j++) {
				cout << j << ' ';
			}
			cout << n + 1 << ' ';
			for (int j = i + 2; j <= n; j++) {
				cout << j << ' ';
			}
			cout << '\n';
			return;
		}
	}
	cout << -1 << '\n';
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