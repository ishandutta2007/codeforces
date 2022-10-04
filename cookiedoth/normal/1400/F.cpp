/*

Code for problem F by cookiedoth
Generated 25 Aug 2020 at 07.39 PM


  !











o_O
-_-
~_^

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
#include <random>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

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

string s;
int x;

void read() {
	cin >> s;
	cin >> x;
}

const int MAX_X = 20;
const int D = 10;
const int mx = (1 << (MAX_X - 1));
int trc[mx], trans[mx][D], ok[mx];

void build_trc() {
	vector<int> prefixes;
	for (int sub = 0; sub < (1 << (x - 1)); ++sub) {
		trc[sub] = sub;
		prefixes.clear();
		for (int i = 0; i < x - 1; ++i) {
			if ((sub >> i) & 1) {
				prefixes.push_back(i + 1);
			}
		}
		ok[sub] = x + 1;
		for (int i = 0; i < prefixes.size(); ++i) {
			int bad = 0;
			if (x % prefixes[i] == 0) {
				bad = 1;
			}
			for (int j = 0; j < i; ++j) {
				if (x % (prefixes[i] - prefixes[j]) == 0) {
					bad = 1;
				}
			}
			if (bad) {
				int val = prefixes[i];
				trc[sub] = sub & ((2 << val) - 1);
				ok[sub] = val;
				break;
			}
		}
		// if (ok[sub]) {
		// 	output(all(prefixes));
		// }
		// cerr << "trc " << sub << " = " << sub << endl;
		// for (int i = 0; i < x - 1; ++i) {
		// 	if ((sub >> i) & 1 && x % (i + 1) == 0) {
		// 		trc[sub] = sub & ((2 << i) - 1);
		// 		ok[sub] = 1;
		// 		break;
		// 	}
		// }
	}
}

void build_trans() {
	for (int sub = 0; sub < (1 << (x - 1)); ++sub) {
		if (trc[sub] != sub) {
			continue;
		}
		// cerr << "sub = " << sub << endl;
		for (int d = 1; d <= D - 1; ++d) {
			// cerr << "d = " << d << endl;
			// cerr << ((sub >> (x - d - 1)) & 1) << endl;
			if (d == x || (ok[sub] > x - d && (sub >> (x - d - 1)) & 1 && x % d != 0)) {
				// cerr << "cant " << sub << " " << d << endl;
				trans[sub][d] = -1;
			} else {
				int new_mask = ((sub << d) ^ (1 << (d - 1))) & ((1 << (x - 1)) - 1);
				// cerr << "new_mask = " << new_mask << endl;
				trans[sub][d] = trc[new_mask];
			}
		}
	}
}

int _trans[mx][D], state_cnt, id[mx];

void compress_trans() {
	queue<int> q;
	q.push(0);
	fill(id, id + (1 << (x - 1)), -1);
	id[0] = 0;
	state_cnt = 1;
	while (!q.empty()) {
		int mask = q.front();
		q.pop();
		for (int d = 1; d <= D - 1; ++d) {
			if (trans[mask][d] == -1) {
				_trans[id[mask]][d] = -1;
			} else {
				if (id[trans[mask][d]] == -1) {
					q.push(trans[mask][d]);
					id[trans[mask][d]] = state_cnt++;
				}
				_trans[id[mask]][d] = id[trans[mask][d]];
			}
		}
	}
	swap(trans, _trans);
}

void build() {
	build_trc();
	build_trans();
	// cerr << trans[0][1] << endl;
	// cerr << trans[1][3] << endl;
	// cerr << trans[0][5] << endl;
	// cerr << trans[16][3] << endl;
	// cerr << trc[160] << endl;
	// cerr << trans[0][2] << endl;
	// cerr << trans[2][6] << endl;
	// cerr << trans[160][6] << endl;
	// cerr << trans[0][2] << endl;
	// cerr << trans[2][1] << endl;
	compress_trans();
	// cerr << trans[0][4] << endl;
	// cerr << trans[0][9] << endl;
	// cerr << trans[0][2] << endl;
	// cerr << trans[2][1] << endl;
	// cerr << "x = " << x << endl;
	// cerr << "trans" << endl;
	// cerr << "state_cnt = " << state_cnt << endl;
	// for (int i = 0; i < state_cnt; ++i) {
	// 	cerr << "state " << i << ":";
	// 	for (int j = 1; j <= D - 1; ++j) {
	// 		cerr << ' ' << trans[i][j];
	// 	}
	// 	cerr << '\n';
	// }
}

const int INF = 1e9 + 228;
int dp[mx], _dp[mx];

void init_dp() {
	fill(dp, dp + state_cnt, -INF);
	dp[0] = 0;
}

void recalc_dp(int digit) {
	copy(dp, dp + state_cnt, _dp);
	for (int i = 0; i < state_cnt; ++i) {
		if (trans[i][digit] != -1) {
			chkmax(_dp[trans[i][digit]], dp[i] + 1);
		}
	}
	swap(dp, _dp);
	// cerr << "recalc_dp " << digit << endl;
	// output(dp, dp + state_cnt);
}

void calc_dp() {
	init_dp();
	for (auto c : s) {
		recalc_dp(c - '0');
	}
	int opt = (*max_element(dp, dp + state_cnt));
	cout << (int)s.size() - opt << '\n';
}

signed main() {
	fast_io();
	read();
	build();
	calc_dp();
	// cerr << "state_cnt = " << state_cnt << endl;
}