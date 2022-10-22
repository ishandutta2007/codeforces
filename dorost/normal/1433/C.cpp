/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	bool f = false;
	for (int i = 1; i < n; i++)
		if (a[i] != a[0])
			f = true;
	if (!f) {
		cout << -1 << '\n';
		return;
	}
	int an = 0, mx = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] > mx) { 
			mx = a[i];
		}
	for (int i = 0; i < n; i++) {
		if (a[i] != mx)
			continue;
		if (i == 0) {
			if (a[i + 1] != mx) {
				an = i;
			}
		} else if (i == n - 1) {
			if (a[i - 1] != mx) {
				an = i;
			}
		} else {
			if (a[i + 1] != mx || a[i - 1] != mx)
				an = i;
		}
	}
	cout << an + 1 << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}