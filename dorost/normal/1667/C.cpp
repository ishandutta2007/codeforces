/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	cin >> n;
	cout << (2 * n + 1) / 3 << '\n';
	if (n % 3 == 0) {
		cout << n << ' ' << n << '\n';
		n--;
	} else if (n % 3 == 1) {
		n++;
	}
	int k = (n - 2) / 3;
	for (int i = 1; i <= 2 * k + 1; i++) {
		if (i <= k + 1) {
			cout << i << ' ' << k + 2 - i << '\n';
		} else {
			int y = i - (k + 1);
			cout << i << ' ' << k + 1 + k + 1 - y << '\n';
		}
	}
}