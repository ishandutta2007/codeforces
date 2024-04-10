/* 	* In the name of GOD  */
 
#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int M = 63;
#define int long long
int p2[M];

int ans(int n, int m) {
	string s = to_string(n), t = to_string(m);
	int in = 0;
	for (int i = 0; i < s.size(); i++) {
		if (in == t.size())
			continue;
		if (t[in] == s[i])
			in++;
	}
	return t.size() - in + s.size() - in;
}

void solve() {
	int n;
	cin >> n;
	int mn = INT_MAX;
	for (int i = 0; i < M; i++) {
		mn = min(mn, ans(n, p2[i]));
	}
	cout << mn << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	p2[0] = 1;
	for (int i = 1; i < M; i++) {
		p2[i] = p2[i - 1] * 2;
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}