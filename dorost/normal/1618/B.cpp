/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 105;
string s[N];

void solve() {
	int n;
	cin >> n;
	int in = 0;
	for (int i = 0; i < n - 2; i++) {
		cin >> s[i];
		if (i != 0) {
			if (s[i][0] != s[i - 1][1])
				in = i - 1;
		}
	}
	for (int i = 0; i <= in; i++) {
		cout << s[i][0];
	}
	cout << s[in][1];
	for (int i = in + 1; i < n - 2; i++) {
		cout << s[i][0];
	}
	cout << s[n - 3][1];
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}