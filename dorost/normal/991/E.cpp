/* 	* In the name of GOD * */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
int fac[20];

int tav(int x, int n) {
	if (n == 0)
		return 1;
	int ans = tav(x, n / 2);
	ans = ans * ans;
	if (n % 2) {
		ans *= x;
	}
	return ans;
}

void solve() {
	fac[0] = 1;
	for (int i = 1; i < 19; i++) {
		fac[i] = fac[i - 1] * i;
	}
	string s;
	cin >> s;
	int y = s.size(), ans = 0;
	int mx = 1 << y;
	set <char> st;
	set <string> sst;
	for (auto c : s) {
		st.insert(c);
	}
	for (int i = 0; i < mx; i++) {
		int x = i, xx = 0, yy = 0;
		set <char> st2;
		string t;
		for (int j = 0; j < y; j++) {
			if (x % 2) {
				st2.insert(s[j]);
				if (s[j] != '0')
					xx++;
				yy++;
				t += s[j];
			}
			x /= 2;
		}
		sort(t.begin(), t.end());
		if (sst.count(t))
			continue;
		bool f = true;
		if (st.size() != st2.size()) {
			continue;
		}
		for (int j = 1; j < 10; j++) {
			int aa = fac[yy - 1], aaa = 0;
			int cnt[10] = {};
			for (int i = 0; i < t.size(); i++) {
				if (t[i] != j + '0') {
					cnt[t[i] - '0']++;
				} else {
					aaa++;
				}
			}
//			cout << j << ' ' << aaa << endl;
			if (!aaa)
				continue;
			cnt[j] = aaa - 1;
			for (int i = 0; i < 10; i++) {
				aa /= fac[cnt[i]];
			}
			ans += aa;
//			cout << aa << endl;
		}
//		cout << t << endl;
		sst.insert(t);
	}
	cout << ans;
}

int32_t main() {
	solve();
}