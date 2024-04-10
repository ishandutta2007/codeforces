/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int n;
	cin >> n;
	ll sum = 0;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mx = max(mx, x);
		sum += x;
	}
	cout << max((ll)mx, (sum + n - 2) / (n - 1));
}