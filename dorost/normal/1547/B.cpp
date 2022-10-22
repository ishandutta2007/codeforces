/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	int l = -1, r = -1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'a')
			l = r = i;
	}
	if (l == -1) {
		cout << "No\n";
		return;
	}
	char c = 'a';
	while (r - l != ((int)s.size()) - 1) {
		c++;
		bool f = false;
		if (l != 0) {
			if (s[l - 1] == c) {
				l--;
				f = true;
			}
		} 
		if (!f && r != (int)s.size() - 1) {
			if (s[r + 1] == c) {
				r++;
				f = true;
			}
		}
		if (!f) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}