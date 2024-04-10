/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], b[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	b[0] = a[0];
	b[n] = a[n - 1];
	for (int i = 0; i < n - 1; i++) {
		b[i + 1] = a[i] * a[i + 1] / __gcd(a[i], a[i + 1]);
	}
	bool f = true;
	for (int i = 0; i < n; i++) {
		f &= (__gcd(b[i], b[i + 1]) == a[i]);
	}
	cout << (f ? "YES" : "NO") << '\n';
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