/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201234;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int sred = 0, sblue = a[0];
	for (int i = 1; i < (n + 1) / 2; i++) {
		sred += a[n - i];
		sblue += a[i];
		if (sblue < sred) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
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