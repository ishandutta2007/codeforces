/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];
int ps[N], ps2[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ps[0] = 0;
	ps2[0] = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1]) {
			ps[i] = ps[i - 1] + (a[i] - a[i - 1]);
			ps2[i] = ps2[i - 1];
		} else {
			ps2[i] = ps2[i - 1] + (a[i - 1] - a[i]);
			ps[i] = ps[i - 1];
		}
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (l <= r) {
			cout << ps2[r] - ps2[l] << '\n';
		} else {
			cout << ps[l] - ps[r] << '\n';
		}
	}
}