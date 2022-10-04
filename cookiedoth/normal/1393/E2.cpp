/*

Code for problem E by cookiedoth
Generated 07 Aug 2020 at 06.09 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

=_=
\_()_/
^_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MOD = 1e9 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

void subt(int &a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

int n;
vector<string> S;
vector<vector<int> > dp;

void read() {
	cin >> n;
	S.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> S[i];
	}
}

int opp(int x) {
	return (x == 0 ? 0 : MOD - x);
}

int len;
string s1, s2;
vector<int> dp1, dp2;

void prepare(int id) {
	len = max(S[id].size(), S[id + 1].size());
	s1 = S[id];
	s2 = S[id + 1];
	dp1 = dp[id];
	dp1.resize(len + 1);
	if (len > S[id].size()) {
		dp1[len] = dp1[S[id].size()];
		dp1[S[id].size()] = 0;
	}
	dp2 = vector<int> (len + 1);
	while (s1.size() < len) {
		s1.push_back('$');
	}
	while (s2.size() < len) {
		s2.push_back('$');
	}
}

vector<int> lcp, lcpR, lcpL;

void calc_lcp() {
	lcp.assign(len + 1, 0);
	lcpR.assign(len, 0);
	lcpL.assign(len + 1, 0);
	for (int i = len - 1; i >= 0; --i) {
		lcp[i] = (s1[i] == s2[i] ? lcp[i + 1] + 1 : 0);
	}
	for (int i = len - 2; i >= 0; --i) {
		lcpR[i] = (s1[i] == s2[i + 1] ? lcpR[i + 1] + 1 : 0);
	}
	for (int i = len - 1; i >= 1; --i) {
		lcpL[i] = (s1[i] == s2[i - 1] ? lcpL[i + 1] + 1 : 0);
	}
}

void add_emp() {
	if (lcp[0] == len || s1[lcp[0]] < s2[lcp[0]]) {
		add(dp2[len], dp1[len]);
	}
	for (int i = 0; i < len; ++i) {
		int ok;
		if (i > lcp[0]) {
			ok = (s1[lcp[0]] < s2[lcp[0]]);
		} else {
			ok = (lcpL[i + 1] == len - 1 - i || s1[i + 1 + lcpL[i + 1]] < s2[i + lcpL[i + 1]]);
			// cerr << "lcp = " << lcpL[i + 1] << endl;
			// cerr << "ok = " << ok << endl;
		}
		if (ok) {
			add(dp2[len], dp1[i]);
		}
	}
	for (int i = 0; i < len; ++i) {
		int ok;
		if (i > lcp[0]) {
			ok = (s1[lcp[0]] < s2[lcp[0]]);
		} else {
			ok = (lcpR[i] < len - 1 - i && s1[i + lcpR[i]] < s2[i + 1 + lcpR[i]]);
			if (lcpR[i] == len - 1 - i && s1[len - 1] == '$') {
				ok = 1;
			}
		}
		if (ok) {
			add(dp2[i], dp1[len]);
		}
	}
}

void add_L() {
	vector<int> val(len + 1), suffix_dep(len + 1);
	for (int i = 0; i < len; ++i) {
		if (i > lcp[0]) {
			if (s1[lcp[0]] < s2[lcp[0]]) {
				add(val[i], dp1[i]);
			}
		} else {
			int pos = i + 1 + lcpL[i + 1];
			add(suffix_dep[i], dp1[i]);
			add(suffix_dep[pos], opp(dp1[i]));
			if (pos == len || s1[pos] < s2[pos - 1]) {
				add(val[pos], dp1[i]);
			}
		}
	}
	for (int i = 1; i < len; ++i) {
		add(val[i], val[i - 1]);
		add(suffix_dep[i], suffix_dep[i - 1]);
	}
	for (int i = 0; i < len; ++i) {
		add(dp2[i], val[i]);
		int pos = i + 1 + lcp[i + 1];
		if (pos == len || s2[pos] > s1[pos]) {
			add(dp2[i], suffix_dep[i]);
		}
	}
}

void add_R() {
	vector<int> bad_suffix(len + 1), ok_suffix(len + 1);
	for (int i = 0; i < len; ++i) {
		int pos = i + 1 + lcp[i + 1];
		if (pos == len || s2[pos] > s1[pos]) {
			add(ok_suffix[i], dp1[i]);
		} else {
			add(bad_suffix[i], dp1[i]);
		}
	}
	for (int i = len - 2; i >= 0; --i) {
		add(bad_suffix[i], bad_suffix[i + 1]);
		add(ok_suffix[i], ok_suffix[i + 1]);
	}
	for (int i = 0; i < len; ++i) {
		if (i > lcp[0]) {
			if (s1[lcp[0]] < s2[lcp[0]]) {
				add(dp2[i], ok_suffix[i + 1]);
				add(dp2[i], bad_suffix[i + 1]);
			}
		} else {
			int pos = i + lcpR[i];
			add(dp2[i], ok_suffix[i + 1]);
			subt(dp2[i], ok_suffix[pos + 1]);
			if (pos == len - 1 || s1[pos] < s2[pos + 1]) {
				add(dp2[i], ok_suffix[pos + 1]);
				add(dp2[i], bad_suffix[pos + 1]);
			}
		}
	}
}

void update_dp(int id) {
	dp[id + 1] = dp2;
	dp[id + 1].resize(S[id + 1].size() + 1);
	// cerr << "mda" << endl;
	// output(all(dp2));
	dp[id + 1][S[id + 1].size()] = dp2[len];

}

void recalc_dp(int id) {
	prepare(id);
	// cerr << "s1/s2" << endl;
	// cerr << s1 << endl;
	// cerr << s2 << endl;
	// cerr << "dp1" << endl;
	// output(all(dp1));
	calc_lcp();
	add_emp();
	// cerr << "add_emp" << endl;
	// output(all(dp2));
	add_L();
	// cerr << "add_L" << endl;
	add_R();
	// cerr << "add_R" << endl;
	update_dp(id);
	// cerr << "recalc_dp " << id << endl;
	// output(all(dp[id + 1]));
}

void calc_dp() {
	dp.resize(n);
	for (int i = 0; i < n; ++i) {
		dp[i].resize(S[i].size() + 1);
	}
	fill(all(dp[0]), 1);
	for (int i = 0; i < n - 1; ++i) {
		recalc_dp(i);
	}
	int ans = 0;
	for (int i = 0; i <= S[n - 1].size(); ++i) {
		add(ans, dp[n - 1][i]);
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	calc_dp();
}