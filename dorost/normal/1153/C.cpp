/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool isO(string s) {
	int x = 0;
	for (int i = 0; i < (int)s.size() - 1; i++) {
		if (s[i] == '(')
			x++;
		else
			x--;
		if (x <= 0)
			return false;
	}
	x += (s[s.size() - 1] == '(' ? 1 : -1);
	return (x == 0);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int n;
	string s;
	cin >> n >> s;
	if (n % 2) 
		return cout << ":(", 0;
	int a = n / 2, b = n / 2;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(')
			a--;
		if (s[i] == ')')
			b--;
	}
	if (a < 0 || b < 0)
		return cout << ":(", 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '?') {
			if (a)
				s[i] = '(', a--;
			else
				s[i] = ')';
		}
	}
	if (isO(s)) {
		cout << s;
	} else
		cout << ":(";
}