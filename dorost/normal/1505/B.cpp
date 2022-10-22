/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int a;
	cin >> a;
	int x = a;
	while (x >= 10) {
		int ans = 0;
		while (x) {
			ans += x % 10;
			x /= 10;
		}
		x = ans;
	}
	cout << x;
}