/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	string s1 = s + 'a', s2 = 'a' + s;
	string t1 = s1, t2 = s2;
	reverse(t1.begin(), t1.end());
	reverse(t2.begin(), t2.end());
	if (t1 != s1) {
		cout << "YES\n" << s1 << '\n';
	} else if (t2 != s2) {
		cout << "YES\n" << s2 << '\n';
	} else {
		cout << "NO\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}