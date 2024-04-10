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
	bool f = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] != a[0]) {
			f = false;
		}
	}
	if (f) {
		for (int i = 0; i < n; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	sort(a, a + n);
	int mn = INT_MAX;
	int in = -1;
	for (int i = 0; i < n - 1; i++) {
		if ((abs(a[i] - a[i + 1])) < mn) {
			mn = ((abs(a[i] - a[i + 1])));
			in = i;
		}
	}
	cout << a[in] << ' ';
	for (int i = 0; i < n; i++) {
		if (a[i] >= a[in] && i != in && i != in + 1) {
			cout << a[i] << ' ';
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < a[in] && i != in && i != in + 1) {
			cout << a[i] << ' ';
		}
	}
	cout << a[in + 1] << '\n';

}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}