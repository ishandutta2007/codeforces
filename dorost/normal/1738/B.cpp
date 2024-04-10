/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N], b[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		if (i)
			b[i - (n != k)] = a[i] - a[i - 1];
	}
	if (n == k)
		b[0] = a[0];
	if (n == k) {
		cout << (is_sorted(b, b + n) ? "YES" : "NO") << '\n';
	} else {
		bool f = true;
		if (k != 1 && !is_sorted(b, b + k - 1))
			f = false;
		if (k != 1 && b[0] * (n - k + 1) < a[0])
			f = false;
		cout << (f ? "YES" : "NO") << '\n';
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