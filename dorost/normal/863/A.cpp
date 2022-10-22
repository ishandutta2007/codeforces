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
	for (int i = 0; i <= 10; i++) {
		string g = s;
		reverse(g.begin(), g.end());
		if (g == s) {
			cout << "YES";
			return 0;
		}
		s = "0" + s;
	}
	cout << "NO";
}