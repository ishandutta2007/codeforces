/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 201235;
int a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n, m;
	cin >> n >> m;
	int gcd = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (i != 0)
			gcd = __gcd(gcd, abs(a[i] - a[i - 1]));
	}
	for (int i = 0; i < m; i++) {
		int b;
		cin >> b;
		cout << __gcd(gcd, a[0] + b) << ' ';
	}
}