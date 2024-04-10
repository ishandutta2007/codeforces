/*

Code for problem G by cookiedoth
Generated 31 Mar 2020 at 04.55 PM


 ] 
 
Il] 


\_()_/
^_^
-_-

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

const int INF = 1e9 + 228;
const int mx = 2e5 + 228;
int n, q, a[mx];

void read() {
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
}

int left_diff[mx], right_diff[mx];

void calc_diff() {
	left_diff[0] = -1;
	for (int i = 1; i < n; ++i) {
		if (a[i] != a[i - 1]) {
			left_diff[i] = i - 1;
		} else {
			left_diff[i] = left_diff[i - 1];
		}
	}
	right_diff[n - 1] = n;
	for (int i = n - 2; i >= 0; --i) {
		if (a[i] != a[i + 1]) {
			right_diff[i] = i + 1;
		} else {
			right_diff[i] = right_diff[i + 1];
		}
	}
}

struct st {
	vector<int> t;
	int n;

	st(int _n) {
		n = 1;
		while (n < _n) {
			n <<= 1;
		}
		t.resize(2 * n);
	}

	void update(int pos, int val) {
		pos += n;
		t[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			t[pos] = max(t[pos * 2], t[pos * 2 + 1]);
		}
	}

	int descent(int pos, int val, int v, int tl, int tr) {
		if (tl == tr) {
			if (t[v] >= val) {
				return tl;
			} else {
				return tl + 1;
			}
		}
		int tm = (tl + tr) >> 1;
		if (pos <= tm && t[v * 2] >= val) {
			int res = descent(pos, val, v * 2, tl, tm);
			if (res != tm + 1) {
				return res;
			}
		}
		return descent(pos, val, v * 2 + 1, tm + 1, tr);
	}

	int closest_bigger(int pos, int val) {
		int res = descent(pos, val, 1, 0, n - 1);
		return res;
	}
};

int rs[mx], lb[mx];

void build4_1(vector<vector<int> > &vp) {
	vector<int> stack;
	for (int i = 0; i < n; ++i) {
		while (!stack.empty() && a[stack.back()] <= a[i]) {
			stack.pop_back();
		}
		lb[i] = (stack.empty() ? -1 : stack.back());
		stack.push_back(i);
	}
	stack.clear();
	for (int i = n - 1; i >= 0; --i) {
		while (!stack.empty() && a[stack.back()] >= a[i]) {
			stack.pop_back();
		}
		rs[i] = (stack.empty() ? n : stack.back());
		stack.push_back(i);
	}
	st solver(n);
	vector<vector<int> > ev(n);
	for (int i = 0; i < n; ++i) {
		if (lb[i] != -1) {
			ev[lb[i]].push_back(i);
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (rs[i] < n - 1) {
			int pos = solver.closest_bigger(rs[i] + 1, a[i]);
			if (pos < n) {
				vector<int> cur = {i, pos, rs[i], lb[pos]};
				sort(all(cur));
				vp.push_back(cur);
			}
		}
		for (auto x : ev[i]) {
			solver.update(x, a[x]);
		}
	}
}

vector<vector<int> > vp, _vp;
vector<pair<int, int> > best;

void build4() {
	build4_1(vp);
	reverse(a, a + n);
	build4_1(_vp);
	for (auto &v : _vp) {
		reverse(all(v));
		for (auto &x : v) {
			x = n - 1 - x;
		}
		vp.push_back(v);
	}
	best.resize(n, make_pair(INF, -1));
	for (int i = 0; i < vp.size(); ++i) {
		vector<int> v = vp[i];
		chkmin(best[v[0]], make_pair(v.back(), i));
	}
	for (int i = n - 2; i >= 0; --i) {
		chkmin(best[i], best[i + 1]);
	}
}

int right_bigger[mx], right_smaller[mx];

void calc_not_monotone() {
	right_bigger[n - 1] = n;
	right_smaller[n - 1] = n;
	for (int i = n - 2; i >= 0; --i) {
		if (a[i + 1] > a[i]) {
			right_bigger[i] = i;
		} else {
			right_bigger[i] = right_bigger[i + 1];
		}
		if (a[i + 1] < a[i]) {
			right_smaller[i] = i;
		} else {
			right_smaller[i] = right_smaller[i + 1];
		}
	}
}

vector<int> solve(int l, int r) {
	if (best[l].first <= r) {
		return vp[best[l].second];
	}
	int pos = max(right_bigger[l], right_smaller[l]);
	if (pos < r) {
		return {left_diff[pos], pos, pos + 1};
	} else {
		return {};
	}
}

void process() {
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		vector<int> res = solve(l, r);
		cout << res.size() << "\n";
		for (auto x : res) {
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
}

signed main() {
	fast_io();
	read();
	calc_diff();
	calc_not_monotone();
	build4();
	process();
}