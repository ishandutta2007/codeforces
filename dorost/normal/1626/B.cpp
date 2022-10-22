/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	int in1 = -1;
	for (int i = 0; i < n; i++) {
		if ((s[i] - '0' + s[i + 1] - '0') >= 10)
			in1 = i;
	}
	if (in1 == -1) {
		in1 = 0;
	}
	for (int i = 0; i < in1; i++) {
		cout << s[i];
	}
	cout << (s[in1] - '0' + s[in1 + 1] - '0');
	for (int i = in1 + 2; i < n; i++)
		cout << s[i];
	cout << '\n';
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