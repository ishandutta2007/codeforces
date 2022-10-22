/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int x1, p1, x2, p2;
	cin >> x1 >> p1 >> x2 >> p2;
	int k1 = (to_string(x1).size());
	int k2 = (to_string(x2).size());
	if (k1 + p1 > k2 + p2) {
		cout << ">";
	} else if (k1 + p1 < k2 + p2) {
		cout << "<";
	} else {
		if (p1 > p2 + 10) {
			cout << ">";
		} else if (p2 > p1 + 10) {
			cout << "<";
		} else {
			ll a = x1;
			ll b = x2;
			int l = min(p1, p2);
			p1 -= l;
			p2 -= l;
			for (int i = 0; i < p1; i++)
				a *= 10;
			for (int i = 0; i < p2; i++)
				b *= 10;
			if (a == b) {
				cout << "=";
			} else if (a > b) {
				cout << ">";
			} else {
				cout << "<";
			}
		}
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}