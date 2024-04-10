/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 512;
int a[N];

void solve() {
	int n, x;
	cin >> n >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (is_sorted(a, a + n)) {
		cout << 0 << '\n';
		return;
	}
	for (int i = 0; i <= n && !is_sorted(a, a + n); i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] > x) {
				swap(x, a[j]);
				break;
			}
		}
		if (is_sorted(a, a + n)) {
			cout << i + 1 << '\n';
			return;
		}
	}
	cout << -1 << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}