/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
int a[55];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i] = n - i;
		cout << n - i << ' ';
	}
	cout << '\n';
	for (int i = 0; i < n - 1; i++) {
		swap(a[i], a[i + 1]);
		for (int j = 0; j < n; j++)
			cout << a[j] << ' ';
		cout << '\n';
		swap(a[i], a[i + 1]);
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