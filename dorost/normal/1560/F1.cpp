/* 	* In the name of GOD  */

#include "bits/stdc++.h"

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
string x2;
vector <int> y2;
string dp[8][2];

string ans(int k, bool f) {
	if (k >= x2.size()) 
		return "";
	if (k != 0 && dp[k - 1][f] != "-1")
		return dp[k - 1][f];
	string mn = "999999999999";
	if (f) {
		auto cc = lower_bound(y2.begin(), y2.end(), (x2[k] - '0')), cc2 = upper_bound(y2.begin(), y2.end(), (x2[k] - '0'));
		char c = ((*cc) + '0'), c2 = ((*cc2) + '0');
		if (cc != y2.end() && c >= '0' && c <= '9' && c == x2[k]) {
			string h = ans(k + 1, true);
			if (h.size() == (x2.size() - k - 1)) {
				h = c + h;
				mn = min(mn, h);
			}
		}
		if (cc2 != y2.end() && c2 >= '0' && c2 <= '9' && c2 > x2[k]) {
			string h = ans(k + 1, false);
			if (h.size() == (x2.size() - k - 1)) {
				h = c2 + h;
				mn = min(mn, h);
			}
		}
	} else {
		string h = ans(k + 1, false);
		h = (char)((*(y2.begin())) + '0') + h;
		mn = min(mn, h);
	}
	if (k != 0)
		dp[k - 1][f] = mn;
	return mn;
}

void solve() {
	string s;
	cin >> s;
	int k;
	cin >> k;
	string mn = "-";
	if (s == "1000000000") {
		if (k == 1) 
			cout << "1111111111" << ' ';
		else
			cout << s << ' ';
		return;
	}
	for (int i = 0; i < 10; i++) {
		for (int j = i; j < 10; j++) {
			vector <int> d;
			d.push_back(i);
			if (j != i)
				d.push_back(j);
			//		for (int j = 0; j < 10; j++) {
			//			if (y % 2)
			//				d.push_back(j);
			//			y /= 2;
			//		}
			if (d.size() > k) {
				continue;
			}
			y2 = d;
			x2 = s;
			for (int i = 0; i < 8; i++) 
				for (int j = 0; j < 2; j++)
					dp[i][j] = "-1";
			string t = ans(0, 1);
			if (t >= s && t.size() == s.size()) {
				if (mn == "-") 
					mn = t;
				else
					mn = min(mn, t);
			}
		}
	}
	cout << mn << ' ';
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