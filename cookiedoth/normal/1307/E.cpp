/*

Code for problem E by cookiedoth
Generated 17 Feb 2020 at 07.21 P



10%

30%

50%

70%

100%

>_<
o_O
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

int mul(int a, int b) {
	return (1ll * a * b) % MOD;
}

int power(int a, int deg) {
	int res = 1;
	while (deg) {
		if (deg & 1) {
			res = mul(res, a);
			deg--;
		}
		a = mul(a, a);
		deg >>= 1;
	}
	return res;
}

int inverse(int x) {
	return power(x, MOD - 2);
}

const int mx = 5005;
int n, m, clr[mx], cow_l_id[mx], cow_r_id[mx], f[mx], h[mx], L[mx], R[mx], flip[mx];
vector<int> front[mx], back[mx];
int C = mx * mx;

void read() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> clr[i];
		clr[i]--;
		front[clr[i]].push_back(i);
	}
	for (int i = n - 1; i >= 0; --i) {
		back[clr[i]].push_back(i);
	}
	for (int i = 0; i < m; ++i) {
		cin >> f[i] >> h[i];
		f[i]--;
	}
}

void calc_ptrs() {
	fill(cow_l_id, cow_l_id + n, -1);
	fill(cow_r_id, cow_r_id + n, -1);
	fill(flip, flip + n, -1);
	for (int i = 0; i < m; ++i) {
		L[i] = (h[i] > front[f[i]].size() ? n : front[f[i]][h[i] - 1]);
		R[i] = (h[i] > back[f[i]].size() ? -1 : back[f[i]][h[i] - 1]);
		if (L[i] != n) {
			cow_l_id[L[i]] = i;
		}
		if (R[i] != -1) {
			cow_r_id[R[i]] = i;
		}
		if (L[i] != n && R[i] != -1) {
			flip[L[i]] = R[i];
			flip[R[i]] = L[i];
		}
	}
}

int cur_l, cur_r;
int c1[mx], c2[mx], c3[mx], mult, diff;

void init() {
	// cerr << "init" << endl;
	for (int i = 0; i < n; ++i) {
		c1[i] = 0;
		c2[i] = 0;
		c3[i] = 0;
	}
	mult = 1;
	cur_l = 0, cur_r = n - 1;
	diff = 0;
}

int get_diff_color(int id) {
	int res = 0;
	if (c1[id]) {
		res++;
	}
	if (c2[id]) {
		res++;
	}
	if (c1[id] == 1 && c2[id] == 1 && c3[id] == 1) {
		res--;
	}
	return res;
}

int get_ways(int id) {
	if (c1[id] == 1 && c2[id] == 1 && c3[id] == 1) {
		return 2;
	} else {
		int res = (max(c1[id], 1) * max(c2[id], 1)) - c3[id];
		// cerr << "res = " << res << endl;
		return res;
	}
}

void remove_color(int id) {
	int diff_delta = get_diff_color(id);
	diff -= diff_delta;
	if (diff_delta) {
		mult = mul(mult, inverse(get_ways(id)));
	}
}

void add_color(int id) {
	int diff_delta = get_diff_color(id);
	diff += diff_delta;
	if (diff_delta) {
		mult = mul(mult, get_ways(id));
	}
}

void add_left(int pos) {
	if (cow_l_id[pos] != -1) {
		int cow_id = cow_l_id[pos];
		remove_color(clr[pos]);
		c1[clr[pos]]++;
		if (R[cow_id] > cur_r) {
			c3[clr[pos]]++;
		}
		add_color(clr[pos]);
	}
	cur_l = pos + 1;
}

void add_right(int pos) {
	if (cow_r_id[pos] != -1) {
		int cow_id = cow_r_id[pos];
		remove_color(clr[pos]);
		// cerr << "remove " << clr[pos] << " " << mult << endl;
		c2[clr[pos]]++;
		if (L[cow_id] < cur_l) {
			c3[clr[pos]]++;
		}
		add_color(clr[pos]);
		// cerr << "added mult = " << mult << endl;
	}
	cur_r = pos - 1;
}

void remove_right(int pos) {
	if (cow_r_id[pos] != -1) {
		int cow_id = cow_r_id[pos];
		remove_color(clr[pos]);
		// cerr << "remove " << clr[pos] << " " << mult << endl;
		c2[clr[pos]]--;
		if (L[cow_id] < cur_l) {
			c3[clr[pos]]--;
		}
		add_color(clr[pos]);
		// cerr << "added mult = " << mult << endl;
	}
	cur_r = pos;
}

int ans1, ans2;

void upd_pair(int _ans1, int _ans2) {
	// cerr << "upd " << _ans2 << endl;
	if (_ans1 > ans1) {
		ans1 = _ans1;
		ans2 = _ans2;
	} else {
		if (_ans1 == ans1) {
			ans2 = (ans2 + _ans2) % MOD;
		}
	}
}

void subt_pair(int _ans1, int _ans2) {
	// cerr << "subt " << _ans2 << endl;
	assert(_ans1 <= ans1);
	if (_ans1 == ans1) {
		ans2 = (ans2 - _ans2 + MOD) % MOD;
	}
}

pair<int, int> got[mx][2];

void calc() {
	// cerr << "=======go " << cur_l << " " << cur_r << " = " << diff << " " << mult << endl;
	// cerr << c1[0] << " " << c2[0] << " " << c3[0] << endl;
	// got[cur_l][cur_r + 1] = {diff, mult};
	if (cur_r == cur_l - 1) {
		got[cur_l][0] = {diff, mult};
	}
	if (cur_r == cur_l) {
		got[cur_l][1] = {diff, mult};
	}
}

void solve() {
	init();
	for (int i = n - 1; i >= 0; --i) {
		add_right(i);
	}
	for (int i = 0; i <= n; ++i) {
		calc();
		if (i < n) {
			remove_right(i);
			calc();
		}
		add_left(i);
	}
	// for (int i = 0; i <= n; ++i) {
	// 	init();
	// 	for (int j = 0; j < i; ++j) {
	// 		add_left(j);
	// 	}
	// 	for (int j = n - 1; j >= i - 1; --j) {
	// 		calc();
	// 		if (j != i - 1) {
	// 			add_right(j);
	// 		}
	// 	}
	// }
}

void calc_ans() {
	for (int i = 0; i <= n; ++i) {
		upd_pair(got[i][0].first, got[i][0].second);
	}
	for (int i = 0; i < n; ++i) {
		subt_pair(got[i][1].first, got[i][1].second);
	}
}

signed main() {
	fast_io();
	// precalc_inv();
	read();
	calc_ptrs();
	solve();
	calc_ans();
	cout << ans1 << " " << ans2 << endl;
	// cerr << mul(2 * 3 * 5 * 7, inv[2 * 3 * 5 * 7]) << endl;
	// cerr << mul(100, inv[100]) << endl;
}