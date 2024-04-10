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
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		if ((int)s.size() == 2) {
			cout << s[1] << '\n';
		} else {
			char mn = '9';
			for (char c : s)
				mn = min(mn, c);
			cout << mn << '\n';
		}
	}
}