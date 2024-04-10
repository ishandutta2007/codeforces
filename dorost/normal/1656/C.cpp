/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

void solve() {
	int n;
	cin >> n;
	bool is0 = false, is1 = false;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 0)
			is0 = true;
		else if (a[i] == 1)
			is1 = true;
	}
	if (is0 && is1) {
		cout << "NO\n";
		return;
	}
	if (!is1) {
		cout << "YES\n";
		return;
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++) {
		if (a[i] == a[i + 1] - 1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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