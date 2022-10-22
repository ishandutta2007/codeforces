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
	int a, b;
	cin >> a >> b >> s;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (s[i] == '0')
			a--;
		else if (s[i] == '1')
			b--;
	}
	if (a < 0 || b < 0) {
		cout << -1;
		return;
	}
	for (int i = 0; i < n / 2; i++) {
		if ((s[i] == '1' &&  s[n - i - 1] == '0') || (s[i] == '0' &&  s[n - i - 1] == '1')) {
			cout << -1;
			return;
		}
		if (s[i] == '?' && s[n - i - 1] == '?') {
			/*if (a >= 2) {
			  s[i] = '0';
			  s[n - i - 1] = '0';
			  a -= 2;
			  } else if (b >= 2) {
			  s[i] = '1';
			  s[n - i - 1] = '1';
			  b -= 2;
			  } else {
			  cout << -1 << ' ';
			  return;
			  } */
			continue;
		}
		if (s[i] == s[n - i - 1]) {
			continue;
		}
		if (s[i] == '?') {
			if (s[n - i - 1] == '0') {
				if (a == 0) {
					cout << -1;
					return;
				} else {
					a--;
					s[i] = '0';
				}
			} else {
				if (b == 0) {
					cout << -1;
					return;
				} else {
					b--;
					s[i] = '1';
				}
			}
		} else {
			if (s[i] == '0') {
				if (a == 0) {
					cout << -1;
					return;
				} else {
					a--;
					s[n - i - 1] = '0';
				}
			} else {
				if (b == 0) {
					cout << -1;
					return;
				} else {
					b--;
					s[n - i - 1] = '1';
				}
			}
		}
	}
	for (int i = 0; i < n / 2; i++) {
		if (s[i] == '?' && s[n - i - 1] == '?') {
			if (a >= 2) {
				s[i] = '0';
				s[n - i - 1] = '0';
				a -= 2;
			} else if (b >= 2) {
				s[i] = '1';
				s[n - i - 1] = '1';
				b -= 2;
			} else {
				cout << -1;
				return;
			}
		}
	}
	if (n % 2) {
		if (s[n / 2] == '?') {
			if (a >= 1)
				s[n / 2] = '0';
			else if (b >= 1) {
				s[n / 2] = '1';
			} else {
				cout << -1;
				return;
			}
		}
	}
	cout << s;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
		cout << '\n';
	}
}