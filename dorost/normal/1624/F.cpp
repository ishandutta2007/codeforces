/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int ask(int k) {
	cout << "+ " << k << endl;
	int y;
	cin >> y;
	return y;
}

int32_t main() {
	int n;
	cin >> n;
	int l = 1, r = n;
	int c = 0;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		int x = mid + c;
		int d = (x + n - 1) / n * n;
		int y = (x + n - 1) / n;
		if (ask((d - (mid + c))) == y) {
			l = mid;
		} else {
			r = mid;
		}
		c += (d - (mid + c));
	}
	cout << "! " << l + c << endl;
}