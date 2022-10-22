/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string s;
	cin >> n >> s;
	if (s[0] == '?') {
		char c = 'R';
		for (int i = 1; i < n; i++) {
			if (s[i] != '?') {
				c = ((i % 2 == 0) ^ (s[i] == 'R') ? 'B' : 'R');
				break;
			}
		}
		s[0] = c;
	}
	for (int i = 1; i < n; i++) {
		if (s[i] == '?') {
			s[i] = (s[i - 1] == 'B' ? 'R' : 'B');
		}
	}
	cout << s << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}