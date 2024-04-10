/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s, t;
	int a, b, k;
	cin >> a >> b >> k;
	if (k == a + b) {
		cout << "No";
		return;
	}
	if (a == 0) {
		if (k == 0) {
			cout << "Yes\n";
			for (int i = 0; i < b; i++) {
				cout << 1;
			}
			cout << '\n';
			for (int i = 0; i < b; i++) {
				cout << 1;
			}
		} else {
			cout << "No";
		}
		return;
	}
	if (b == 1) {
		if (k == 0) {
			cout << "Yes\n";
			cout << 1;
			for (int i = 0; i < a; i++) {
				cout << 0;
			}
			cout << '\n';
			cout << 1;
			for (int i = 0; i < a; i++) {
				cout << 0;
			}
		} else {
			cout << "No";
		}
		return;
	}
	int n = a + b;
	if (k == n - 1) {
		cout << "No";
		return;
	}
	cout << "Yes\n";
	for (int i = 0; i < n; i++) {
		s += '0';
		t += '0';
	}
	s[1] = '1';
	t[k + 1] = '1';
	b -= 2;
	s[0] = '1';
	t[0] = '1';
	for (int i = 0; i < n; i++) {
		if (b == 0)
			break;
		if (s[i] == '0' && t[i] == '0') {
			b--;
			s[i] = '1';
			t[i] = '1';
		}
	}
	cout << s << '\n' << t;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
}