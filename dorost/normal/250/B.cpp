/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 8;
string t[M], g[M];

void solve() {
	string s, r;
	cin >> s;
	int k = 0;
	for (int i = 0; i < 8; i++)
		t[i] = "";
	int num = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (i != 0 && s[i] == ':') {
			t[k] = r;
			if (t[k] != "")
				num++;
			k++;
			r = "";
		} else if (s[i] != ':') {
			r += s[i];
		}
	}
	if (s[s.size() - 1] != ':') {
		t[k] = r;
		if (t[k] != "")
			num++;
		k++;
		r = "";
	}
	num = 8 - num;
	int y = 0;
	for (int i = 0; i < k; i++) {
		if (t[i] == "") {
			for (int j = 0; j < num; j++) {
				g[y] = "0000";
				y++;
			}
		} else {
			int x = 4 - t[i].size();
			for (int j = 0; j < x; j++)
				t[i] = '0' + t[i];
			g[y] = t[i];
			y++;
		}
	}
	for (int i = 0; i < 8; i++) {
		cout << g[i];
		if (i != 7)
			cout << ':';
	}
	cout << '\n';
}

int32_t main() {
	int q = 1;
	cin >> q;
	while (q--) {
		solve();
	}
}