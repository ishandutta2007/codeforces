/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

bool is_prime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return (x > 1);
}

void solve() {
	int n;
	string s;
	cin >> n >> s;
	for (auto c : s) {
		if (c != '3' && c != '7' && c != '5' && c != '2') {
			cout << 1 << '\n' << ' ' << c << '\n';
			return;
		}
	}
	n = min(n, 10);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string t;
			t += s[i];
			t += s[j];
			int x = stoi(t);
			if (!is_prime(x)) {
				cout << 2 << '\n' << ' ' << x << '\n';
				return;
			}
		}
	}
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}