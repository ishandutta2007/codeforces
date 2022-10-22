/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 55;
int a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	if (n & 1) {
		cout << "Mike\n";
	} else {
		int mnf = INT_MAX, mns = INT_MAX;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				mnf = min(mnf, a[i]);
			} else {
				mns = min(mns, a[i]);
			}
		}
		if (mns != mnf) {
			cout << (mnf < mns ? "Joe" : "Mike") << '\n';
		} else {
			for (int i = 0; i < n; i++) {
				if (a[i] == mnf) {			
					cout << (i % 2 == 0 ? "Joe" : "Mike") << '\n';
					return;
				}
			}
		}
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