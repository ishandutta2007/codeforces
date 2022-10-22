/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

void solve() {
	int n;
	string s;
	cin >> n >> s;
	if (s[0] == 'D') {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'D')
				s[i] = 'R';
			else
				s[i] = 'D';
		}
	}
	int in = s.size();
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'D') {
			in = i;
			break;
		}
	}
	int r = 0, d = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == 'D')
			d++;
		else
			r++;
	ll ans = n - (r - in);
	if (in != s.size())
		ans += ((ll)n - (ll(d))) * ((ll)n - (ll(r)));
	for (int i = in + 1; i < s.size(); i++) {
		if (s[i] == 'R') {
			ans += (n - d);
		} else {
			ans += (n - r);
		}
	}
	cout << ans << ' ';
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