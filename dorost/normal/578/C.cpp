/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], n;

ld mx (ld x) {
	ld mn = 0, sum = 0, mxwef = 0, mx2 = 0;
	for (int i = 0; i < n; i++) {
		sum += ((ld)a[i] - x);
		mn = min(mn, sum);
		mx2 = max(mx2, sum);
		mxwef = max(mxwef, abs(sum - mn));
		mxwef = max(mxwef, abs(sum - mx2));
	}
	return mxwef;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ld l = -20000, r = 20000;
	for (int i = 0; i < 300; i++) {
		ld mid = (l + r) / 2;
		if (mx((l + mid) / 2) < mx((mid + r) / 2)) {
			r = (r + mid) / 2;
		} else {
			l = (l + mid) / 2;
		}
	}
	cout << fixed << setprecision(7);
	cout << mx(l);
}