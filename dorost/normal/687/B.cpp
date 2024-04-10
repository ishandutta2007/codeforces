/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, k;
	cin >> n >> k;
	int lcm = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x = __gcd(x, k);
		lcm = (lcm * x) / __gcd(lcm, x);
	}
	cout << (lcm == k ? "Yes" : "No");
}