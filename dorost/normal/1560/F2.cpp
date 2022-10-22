/* 	* In the name of GOD  */

#include "bits/stdc++.h"

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	if (s == "1000000000") {
		if (k == 1) 
			cout << "1111111111" << ' ';
		else
			cout << s << ' ';
		return;
	}
	if (k >= 9) {
		cout << s << ' ';
		return;
	}
	set <char> st;
	string mn = "99999999999";
	string t;
	for (int i = 0; i <= s.size(); i++) {
		if (i == s.size()) {
			if (st.size() <= k) {
				mn = min(mn, s);
			}
			continue;
		}
		for (char c = s[i] + 1; c <= '9'; c++) {
			set <char> st2 = st;
			st2.insert(c);
			string t2 = t;
			t2 += c;
//			cout << t2 << ' ' << st2.size() << '\n';
			if (st2.size() > k) {
				continue;
			}
			if (st2.size() == k) {
				char x = *st2.begin();
				while (t2.size() != s.size()) 
					t2 += x;
				if (t2 >= s) {
					mn = min(mn, t2);
				}
			} else {
				char x = '0';
				while (t2.size() != s.size()) 
					t2 += x;
				if (t2 >= s) {
					mn = min(mn, t2);
				}
			}
		}
		st.insert(s[i]);
		t += s[i];
	}
	cout << mn << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}