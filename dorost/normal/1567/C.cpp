/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long

void solve() {
	string s;
	cin >> s;
	string t = "0", r = "0";
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0)
			t += s[i];
		else
			r += s[i];
	}
	int x = stoi(t), y = stoi(r);
	cout << (x + 1) * (y + 1) - 2 << ' ';
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