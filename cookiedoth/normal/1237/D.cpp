/*

Code for problem D by cookiedoth
Generated 16 Oct 2019 at 06.28 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

\_()_/
^_^
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

const int NEUTRAL = 1e9 + 228;

struct fast_min_rmq {
	vector<int> t;
	int n;

	void build(vector<int> &a, int v, int tl, int tr) {
		if (tl == tr)
			t[v] = a[tl];
		else {
			int tm = ((tl + tr) >> 1);
			build(a, v * 2, tl, tm);
			build(a, v * 2 + 1, tm + 1, tr);
			t[v] = min(t[v * 2], t[v * 2 + 1]);
		}
	}

	fast_min_rmq(vector<int> _a) {
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
				t[pos] = min(t[pos * 2], t[pos * 2 + 1]);
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
				chkmin(res, t[l]);
				l++;
				continue;
			}
			if ((r & 1) == 0) {
				chkmin(res, t[r]);
				r--;
				continue;
			}
			l >>= 1;
			r >>= 1;
		}
		return res;
	}
};

const int INF = 1e9;
int n;
vector<int> a;

signed main() {
	fast_io();
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < 3 * n + 5; ++i) {
		a.push_back(a[i]);
	}
	fast_min_rmq t(a);
	vector<int> dead(3 * n);
	for (int i = 0; i < n; ++i) {
		int value = (a[i] - 1) / 2;
		int l = 0, r = 3 * n;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (t.get(i + 1, i + mid + 1) > value) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		dead[i] = (i + l);
		dead[i + n] = (i + n + l);
		dead[i + n * 2] = (i + n * 2 + l);
	}
	int lowest = (*min_element(dead.begin() + n, dead.end()));
	vector<int> ans(n);
	for (int i = n - 1; i >= 0; --i) {
		chkmin(lowest, dead[i]);
		int res = lowest - i + 1;
		if (res >= 2 * n) {
			res = -1;
		}
		ans[i] = res;
	}
	output(all(ans), cout);
}