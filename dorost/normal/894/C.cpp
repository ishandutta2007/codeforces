/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int s[N], n;

int32_t main() {
	cin >> n;
	int gcd = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		gcd = __gcd(gcd, s[i]);
	}
	if (gcd != s[0]) {
		cout << -1;
		return 0;
	}
	cout << 2 * n << '\n';
	for (int i = 0; i < n; i++) {
		cout << s[i] << ' ';
		cout << s[0] << ' ';
	}
}