/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int x = 0, ans = 0;
	string s;
	cin >> s;
	for (auto c : s) {
		if (c == '(')
			x++;
		if (c == ')' && x) {
			x--;
			ans += 2;
		}
	}
	cout << ans;
}