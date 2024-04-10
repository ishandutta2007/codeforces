/*

Code for problem F by cookiedoth
Generated 15 Dec 2019 at 12.23 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

~_^
z_z
>_<

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

const int C = 3;
const int SUB = 1 << C;
int cap[2][C], _cap[2][C], d[SUB], _d[SUB], ans[SUB], sum_cap[C], students[SUB];

int rev_bits(int x) {
	int res = 0;
	for (int i = 0; i < C; ++i) {
		if ((x >> i) & 1) {
			res ^= (1 << (C - i - 1));
		}
	}
	return res;
}

void copy() {
	for (int i = 0; i < 2; ++i) {
		copy(cap[i], cap[i] + C, _cap[i]);
	}
	copy(d, d + SUB, _d);
}

void push_to_ans(int id, int cnt, int strict = 1) {
	for (int i = 0; i < C; ++i) {
		if ((id >> i) & 1) {
			if (strict) {
				assert(_cap[0][i] >= cnt && _cap[1][i] >= _d[id] - cnt);
			}
			_cap[0][i] -= cnt;
			_cap[1][i] -= (_d[id] - cnt);
			ans[id] = cnt;
		}
	}
	_d[id] = 0;
}

void restore() {
	push_to_ans(7, min(min(_cap[0][0], _cap[0][1]), min(_cap[0][2], d[7])));
	for (int i = 0; i < C; ++i) {
		push_to_ans(1 << i, min(d[1 << i], _cap[0][i]));
	}
}

void print_cur() {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < C; ++j) {
			cerr << _cap[i][j] << " ";
		}
		cerr << endl;
	}
}

int check(int min1, int min2) {
	// cerr << "check " << min1 << " " << min2 << endl;
	for (int i = 0; i < C; ++i) {
		if (cap[0][i] < min1) {
			return 0;
		}
		if (cap[1][i] < min2) {
			return 0;
		}
	}
	for (int i = 0; i <= d[3]; ++i) {
		// cerr << "i = " << i << endl;
		copy();
		push_to_ans(3, i, 0);
		if (_cap[0][0] < min1 || _cap[0][1] < min1 || _cap[1][0] < min2 || _cap[1][1] < min2) {
			continue;
		}
		// cerr << "alive" << endl;
		// print_cur();
		int rx = _cap[0][0] - min1;
		int lx = min2 - _cap[1][0] + d[5];
		int ry = _cap[0][1] - min1;
		int ly = min2 - _cap[1][1] + d[6];
		int rxy = _cap[0][2] - min1;
		int lxy = min2 - _cap[1][2] + d[5] + d[6];
		chkmax(lx, 0);
		chkmax(ly, 0);
		chkmax(lxy, 0);
		chkmin(rx, d[5]);
		chkmin(ry, d[6]);
		chkmin(rxy, d[5] + d[6]);
		// cerr << "segments " << lx << " " << rx << " " << ly << " " << ry << " " << lxy << " " << rxy << endl;
		if (lx > rx || ly > ry || lxy > rxy) {
			continue;
		}
		int lsum = max(lxy, lx + ly), rsum = min(rxy, rx + ry);
		if (lsum > rsum) {
			continue;
		}
		int x, y;
		if (ly + rx >= lsum) {
			y = ly;
			x = lsum - y;
		} else {
			x = rx;
			y = lsum - x;
		}
		assert(x >= lx && x <= rx && y >= ly && y <= ry && x + y == lsum);
		push_to_ans(5, x);
		push_to_ans(6, y);
		restore();
		return 1;
	}
	return 0;
}

void print_ans() {
	for (int i = 0; i < SUB - 1; ++i) {
		cout << ans[rev_bits(SUB - i - 1)] << " ";
	}
	cout << endl;
}

void solve() {
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < C; ++j) {
			cin >> cap[i][j];
		}
	}
	for (int i = 0; i < SUB - 1; ++i) {
		cin >> d[rev_bits(SUB - 1 - i)];
	}

	/*cerr << "--- solve" << endl;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < C; ++j) {
			cerr << cap[i][j] << " ";
		}
		cerr << endl;
	}
	for (int i = 0; i < SUB; ++i) {
		cerr << d[i] << " ";
	}
	cerr << endl;*/

	for (int i = 0; i < C; ++i) {
		sum_cap[i] = cap[0][i] + cap[1][i];
	}
	fill(students, students + SUB, 0);
	for (int i = 0; i < SUB; ++i) {
		for (int j = 0; j < C; ++j) {
			if ((i >> j) & 1) {
				students[j] += d[i];
			}
		}
	}
	int can = 1;
	for (int i = 0; i < C; ++i) {
		if (sum_cap[i] < students[i]) {
			can = 0;
		}
	}
	if (!can) {
		cout << -1 << endl;
		return;
	}
	for (int i = 0; i <= d[7]; ++i) {
		if (check(i, d[7] - i)) {
			print_ans();
			return;
		}
	}
	cout << -1 << endl;
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}