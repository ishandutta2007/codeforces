#include <iostream>
#include <vector> 
#include <algorithm> 
#include <string> 
#include <cassert> 
#include <algorithm> 
#include <set> 
#include <iomanip> 
#include <queue> 
#include <deque> 
#include <unordered_set> 
#include <unordered_map> 
#include <functional> 
#include <cmath> 
#include <map> 
#include <random> 
#include <chrono> 
#include <cstdio> 
#include <bitset> 
#include <numeric> 

bool home = true;
using namespace std;

typedef long long ll;

ll dp[17][17][(1 << 16)];

int combine(int lastdigits, int new_digit) {
	assert(0 <= lastdigits && lastdigits < (1 << 16));
	assert(0 <= new_digit && new_digit < 16);
	return (lastdigits * 16 + new_digit) & ((1 << 16) - 1);
}

ll get(int len, int curmax, int lastdigits) {
	if (dp[len][curmax][lastdigits] != -1) return dp[len][curmax][lastdigits];
	assert(0 <= len && len < 17);
	assert(0 <= curmax && curmax < 17);
	assert(0 <= lastdigits && lastdigits < (1 << 16));

	ll& sol = dp[len][curmax][lastdigits];
	sol = 0;

	if (len == 0) {
		if (lastdigits & (1 << curmax)) {
			return sol = 1;
		}
		else {
			return sol = 0;
		}
	}
	assert(len > 0);
	
	for (int i = 0; i < 16; i++) {
		sol += get(len - 1, max(i, curmax), combine(lastdigits, i));
	}
	return sol;
}

vector<int> getDigits(ll num) {
	vector<int> sol;
	while (num) {
		sol.push_back(num % 16);
		num /= 16;
	}
	reverse(sol.begin(), sol.end());
	return sol;
}

ll solve(ll limit) {
	if (limit <= 0) return 0;
	vector<int> digits = getDigits(limit);
	int sz = (int)digits.size();
	ll sol = 0;

	int curmax = 0, lastdigits = 0;

	for (int com = 0; com <= sz; com++) {

		if (com == sz) {
			sol += get(0, curmax, lastdigits);
			break;
		}
		for (int p = 0; p < digits[com]; p++) {
			sol += get(sz - com - 1, max(curmax, p), combine(lastdigits, p));
		}
		curmax = max(curmax, digits[com]);
		lastdigits = combine(lastdigits, digits[com]);
	}
	return sol;
}

ll toNum(string s) {
	ll sol = 0;
	for (auto& ch : s) {
		ll curdigit = 0;
		if ('0' <= ch && ch <= '9') {
			curdigit = ch - '0';
		}
		else {
			curdigit = ch - 'a' + 10;
		}
		assert(0 <= curdigit && curdigit < 16);
		sol = sol * 16 + curdigit;
	}
	return sol;
}

ll read() {
	string s;
	cin >> s;
	return toNum(s);
}

signed main() {
#ifdef ONLINE_JUDGE
	home = 0;
#endif

	if (home) {
		FILE* stream;
		freopen_s(&stream, "iron_man.txt", "r", stdin);
	}
	else {
		ios::sync_with_stdio(0); cin.tie(0);
	}

	for (int i = 0; i < 17; i++) for (int j = 0; j < 17; j++) for (int k = 0; k < (1 << 16); k++) dp[i][j][k] = -1;

	int q;
	cin >> q;
	while (q--) {
		ll l, r;
		l = read();
		r = read();
		cout << solve(r) - solve(l - 1) << "\n";
	}

}
// (a ^ b) < a = > only the biggest of b matters