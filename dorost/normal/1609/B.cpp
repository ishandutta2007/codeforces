/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main() {
	int n, q;
	string s;
	cin >> n >> q >> s;
	int cn = 0;
	s = "000" + s + "000";
	n += 6;
	for (int i = 0; i < n - 2; i++) {
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
			cn++;
	}
	while (q--) {
		int x;
		char c;
		cin >> x >> c;
		x += 2;
		for (int i = x - 2; i <= x; i++) {
			if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
				cn--;
		}
		s[x] = c;
		for (int i = x - 2; i <= x; i++) {
			if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
				cn++;
		}
		cout << cn << ' ';
	}
}