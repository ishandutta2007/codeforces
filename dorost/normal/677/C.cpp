/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int M = 1000 * 1000 * 1000 + 7;

string to_bit(char s) {
	int x;
	if (s == '-')
		x = 62;
	else if (s == '_')
		x = 63;
	else if (s <= '9') {
		x = s - '0';
	} else if (s <= 'Z') {
		x = 10 + s - 'A';
	} else {
		x = 36 + s - 'a';
	}
	string ans;
	while (x) {
		ans += x % 2 + '0';
		x /= 2;
	}
	reverse(ans.begin(), ans.end());
	while (ans.size() != 6) {
		ans = "0" + ans;
	}
	return ans;
}

int32_t main() {
	string s;
	cin >> s;
	int ans = 1;
	for (int i = 0; i < s.size(); i++) {
		string a = to_bit(s[i]);
		for (auto c : a) {
			if (c == '0')
				ans *= 3, ans %= M;
		}
	}
	cout << ans;
}