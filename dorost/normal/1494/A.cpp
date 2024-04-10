/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool reg(string s) {
	int x = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(')
			x++;
		else
			x--;
		if (x < 0)
			return false;
	}
	if (x != 0)
		return false;
	else
		return true;
}

void solve() {
	string s;
	cin >> s;
	for (int i = 0; i < 8; i++) {
		int x = i;
		char a = (x % 2 ? ')' : '(');
		x /= 2;
		char b = (x % 2 ? ')' : '(');
		x /= 2;
		char c = (x % 2 ? ')' : '(');
		string t = "";
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == 'A')
				t += a;
			if (s[j] == 'B')
				t += b;
			if (s[j] == 'C')
				t += c;
		}
		if (reg(t)) {
			cout << "YES ";
			return;
		}
	}
	cout << "NO ";
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}