/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
vector <int> a;

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i != 0 && __gcd(x, a.back()) != 1) {
			a.push_back(1);
		}
		a.push_back(x);
	}
	cout << a.size() - n << '\n';
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}