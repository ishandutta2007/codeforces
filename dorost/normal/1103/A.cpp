/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	string s;
	cin >> s;
	pair <int, int> a[] = {{1, 1}, {2, 1}, {3, 1}, {4, 1}}, b[] = {{1, 3}, {3, 3}, {1, 4}, {3, 4}};
	int x = 0, y = 0;
	for (auto c : s) {
		if (c == '0') {
			cout << a[x % 4].S << ' ' << a[x % 4].F << '\n';
			x++;
		} else {
			cout << b[y % 4].S << ' ' << b[y % 4].F << '\n';
			y++;
		}
	}
}