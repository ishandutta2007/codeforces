/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
vector <int> a;

void solve() {
	int k;
	cin >> k;
	cout << a[k - 1] << ' ';
}

int32_t main() {
	for (int i = 1; i <= 100000; i++) {
		if (i % 3 == 0 || i % 10 == 3)
			continue;
		a.push_back(i);
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}