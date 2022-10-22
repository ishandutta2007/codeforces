/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	bool f = true;
	for (int i = 0; i < n - k; i++) {
		if ((s[i] == '0' && s[i + k] == '1') || (s[i + k] == '0' && s[i] == '1')) {
			f = false;
		}
		if (s[i] == '0' && s[i + k] == '?') {
			s[i + k] = '0';
		}
		if (s[i] == '1' && s[i + k] == '?') {
			s[i + k] = '1';
		}
		if (s[i] == '?' && s[i + k] == '0') {
			s[i] = '0';
		}
		if (s[i] == '?' && s[i + k] == '1') {
			s[i] = '1';
		}
	}
	for (int i = n - k - 1; i >= 0; i--) {
		if ((s[i] == '0' && s[i + k] == '1') || (s[i + k] == '0' && s[i] == '1')) {
			f = false;
		}
		if (s[i] == '0' && s[i + k] == '?') {
			s[i + k] = '0';
		}
		if (s[i] == '1' && s[i + k] == '?') {
			s[i + k] = '1';
		}
		if (s[i] == '?' && s[i + k] == '0') {
			s[i] = '0';
		}
		if (s[i] == '?' && s[i + k] == '1') {
			s[i] = '1';
		}
	}
	if (!f) {
		cout << "No ";
		return;
	}
	int x = 0, y = 0;
	for (int i = 0; i < k; i++) {
		if (s[i] == '?')
			y++;
		if (s[i] == '1')
			x++;
	}
	int su = k / 2;
	su -= x;
	if (su < 0 || su > y) {
		cout << "No ";
		return;
	}
//	if (abs(su - y) % 2 == 0) {
		cout << "Yes ";
//	}else{
//		cout << "No ";
//	}
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