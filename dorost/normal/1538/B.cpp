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
	int x = 0, sum = 0, y = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	if (sum % n) {
		cout << -1 << '\n';
		return;
	}
	sum /= n;
	for (int i = 0; i < n; i++) {
		if (a[i] < sum) {
			x += sum - a[i];
		}
	}
	if (x == 0) {
		cout << 0 << '\n';
		return;
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] > sum) {
			y += a[i] - sum;
			if (y >= x) {
				cout << n - i << '\n';
				return;
			}
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