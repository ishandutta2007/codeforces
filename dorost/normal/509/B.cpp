/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N];

int32_t main() {
	int n, k, mn = INT_MAX, mx = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
	}
	if (mx - mn > k) {
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i]; j++) {
			cout << (j % k + 1) << ' ';
		}
		cout << '\n';
	}
}