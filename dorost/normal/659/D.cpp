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
	int x = (n - 2) * 2;
	for (int i = 0; i <= x; i++) {
		if ((x - i) % 3 == 0 && (x - i) / 3 + i == n) {
			cout << (x - i) / 3 << '\n';
			return 0;
		}
	}
	assert(1);
}