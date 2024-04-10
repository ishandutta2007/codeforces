/*

Code for problem E by cookiedoth
Generated 25 Aug 2019 at 06.07 P










(@)(@)(@)(@)(@)

^_^
~_^
=_=

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

const ll NEUTRAL = -1e9 - 228;

struct fast_max_rmq {
	vector<int> t;
	int n;

	void build(vector<int> &a, int v, int tl, int tr) {
		if (tl == tr)
			t[v] = a[tl];
		else {
			int tm = ((tl + tr) >> 1);
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = max(t[v * 2], t[v * 2 + 1]);
		}
	}

	fast_max_rmq(vector<int> _a) {
		n = 1;
		while (n < (int)_a.size()) {
			n <<= 1;
		}
		_a.resize(n);
		t.resize(2 * n);
		build(_a, 1, 0, n - 1);
	}

	void update(int pos, int val) {
		pos += n;
		t[pos] = val;
		while (true) {
			pos >>= 1;
			if (pos > 0)
				t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
			else
				break;
		}
	}

	int get(int l, int r) {
		l += n;
		r += n;
		int res = NEUTRAL;
		while (l <= r) {
			if (l & 1) {
				chkmax(res, t[l]);
				l++;
				continue;
			}
			if ((r & 1) == 0) {
				chkmax(res, t[r]);
				r--;
				continue;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};

const int mx = 1e6 + 228;
int n, m;
vector<vector<int> > arr;
ll ans[mx], max_ans;

void read() {
	cin >> n >> m;
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		int k;
		cin >> k;
		arr[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> arr[i][j];
		}
	}
}

void solve_arr(int id) {
	/*cerr << "solve_arr: ";
	output(all(arr[id]));*/
	fast_max_rmq t(arr[id]);
	vector<int> good_pos;
	int len = arr[id].size();
	for (int i = 0; i < len - 1; ++i) {
		good_pos.push_back(i);
	}
	for (int i = max(len - 1, m - len + 1); i < m; ++i) {
		good_pos.push_back(i);
	}
	int max_value = (*max_element(all(arr[id])));
	if (m > len) {
		chkmax(max_value, 0);
	}
	for (auto pos : good_pos) {
		int r = min(len - 1, pos);
		int l = max(0, len - (m - pos));
		int cur_value = t.get(l, r);
		//cerr << "cur_value = " << cur_value << endl;
		if (pos + len < m) {
			chkmax(cur_value, 0);
		}
		if (pos >= len) {
			chkmax(cur_value, 0);
		}
		//cerr << pos << " " << l << ".." << r << endl;
		ans[pos] += (ll)(cur_value) - (ll)(max_value);
		//cerr << "cur_value = " << cur_value << endl;
	}
	max_ans += (ll)max_value;
}

void calc_and_print() {
	for (int i = 0; i < m; ++i) {
		ans[i] += max_ans;
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

signed main() {
	fast_io();
	read();
	for (int i = 0; i < n; ++i) {
		solve_arr(i);
	}
	calc_and_print();
}