/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
string s;

bool is_valid(int x) {
	int c1 = 0;
	for (char c : s) {
		if (c == '1')
			c1++;
	}
	c1 -= x;
	int cnt = 0, lst = 0;
	int n = s.size();
	for (int i = 0; i < n; i++) {
		if (i != 0 && s[i - 1] == '0')
			cnt--;
		while (true) {
			if (lst == n) {
				break;
			}
			if (s[lst] == '0')
				cnt++;
			if (cnt > x) {
				cnt--;
				break;
			}
			lst++;
		}
		if (((lst - i) - cnt) >= c1) {
			return true;
		}
	}
	return false;
}

void solve() {
	cin >> s;
	int l = -1, r = 201234;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if (is_valid(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << '\n';
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