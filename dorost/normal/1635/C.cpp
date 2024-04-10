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
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (a[n - 1] < a[n - 2]) {
		cout << -1 << '\n';
		return;
	}
	int in = n - 1;
	for (int i = n - 1; i >= 1; i--) {
		if (a[i] >= a[i - 1]) {
			in--;
		} else {
			break;
		}
	}
	if (in == 0) {
		cout << 0 << '\n';
		return;
	}
	for (int i = in; i < n - 1; i++) {
		int x = a[i] - a[i + 1];
		if (x <= a[i]) {
			cout << i << '\n';
			for (int j = 0; j < i; j++) {
				cout << j + 1 << ' ' << i + 1 << ' ' << i + 2 << '\n';
			}
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