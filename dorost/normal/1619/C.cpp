/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string a, s, b;
	cin >> a >> s;
	int in1 = (a.size()) - 1, in2 = (s.size()) - 1;
	string t;
	while (in1 >= 0 && in2 >= 0) {
		t += s[in2];
		reverse(t.begin(), t.end());
		string g;
		g += a[in1];
		ll x = stoll(t), y = stoll(g);
		reverse(t.begin(), t.end());
		if (x >= y) {
			if (x - y >= 10) {
				cout << -1 << ' ';
				return;
			}
			b += (x - y + '0');
			in1--;
			in2--;
			t = "";
		} else {
			in2--;
		}
	}
	if (in1 >= 0) {
		cout << -1 << ' ';
		return;
	}
	for (int i = in2; i >= 0; i--) {
		b += s[i];
	}
	reverse(b.begin(), b.end());
	cout << stoll(b) << ' ';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}