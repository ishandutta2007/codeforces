/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 401234;
int a[N], p[N];

int32_t main() {
	int n, I;
	cin >> n >> I;
	I = I * 8 / n;
	if (I > 20) {
		I = N;
	} else {
		I = pow(2, I);
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int x = 1;
	for (int i = 0; i < n; i++) {
		if (i != 0 && a[i] != a[i - 1]) {
			x++;
		}
		p[i] = x;
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		if (i != 0 && a[i] == a[i - 1])
			continue;
		int y = 0;
		if (i != 0)
			y = p[i - 1];
		int in = upper_bound(p, p + n, y + I) - p;
		mx = max(mx, in - i);
	}
	cout << n - mx;
}