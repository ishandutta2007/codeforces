/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int a, b;
	cin >> a >> b;
	cout << min({(a + b) / 3, a, b});
}