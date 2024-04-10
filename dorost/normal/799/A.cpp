/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int n, t, k, d;
	cin >> n >> t >> k >> d;
	int a = (n + k - 1) / k * t;
	int b = d;
	n -= d / t * k;
	b = d + ((n + 1) / 2 + k - 1) / k * t;
	cout << ((b < a) ? "YES" : "NO");
}