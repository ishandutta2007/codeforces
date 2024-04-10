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
	int x = 0;
	for (auto c : s) {
		if (c == '1')
			x++;
	}
	vector <int> v;
	for (int i = (int)s.size() - 1; i >= (int)s.size() - x; i--) {
		if (s[i] == '0')
			v.push_back(i + 1);
	}
	for (int i = (int)s.size() - x - 1; i >= 0; i--) {
		if (s[i] == '1')
			v.push_back(i + 1);
	}
	reverse(v.begin(), v.end());
	if (v.size() == 0) {
		cout << 0 << '\n';
	} else {
		cout << 1 << '\n';
		cout << v.size() << ' ';
		for (auto x : v) 
			cout << x << ' ';
		cout << '\n';
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}