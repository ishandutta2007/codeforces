/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int x[N];

void solve() {
	int a, b;
	cin >> a >> b;
	if ((b ^ x[a - 1]) == 0) {
		cout << a << ' ';
	} else if ((b ^ x[a - 1]) != a) {
		cout << a + 1 << ' ';
	} else {
		cout << a + 2 << ' ';
	}
}

int32_t main() {
	x[0] = 0;
	for (int i = 1; i < N; i++) {
		x[i] = x[i - 1] ^ i;
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}