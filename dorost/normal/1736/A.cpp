/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1003;
int a[N], b[N];

void solve() {
	int n;
	cin >> n;
	int a0 = 0, b0 = 0;
	int d = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (a[i] != b[i])
			d++;
		if (!a[i])
			a0++;
		if (!b[i])
			b0++;
	}
	cout << min(d, 1 + abs(a0 - b0)) << '\n';
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