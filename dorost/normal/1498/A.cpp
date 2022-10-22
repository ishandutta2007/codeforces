/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long 

void solve() {
	int n;
	cin >> n;
	for (int x = n; ; x++) {
		int a = 0;
		string s = to_string(x);
		for (int i = 0; i < s.size(); i++) {
			a += s[i] - '0';
		}
		a = __gcd(a, x);
		if (a != 1) {
			cout << x << ' ';
			return;
		}
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