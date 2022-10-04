/*

Code for problem E by cookiedoth
Generated 19 Mar 2020 at 06.08 PM


 ] 
 
Il] 


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

struct st {
	st() {}

	vector<int> sum, min_pref;
	int n;

	void init(int _n) {
		n = _n;
		sum.resize(4 * n);
		min_pref.resize(4 * n);
	}

	void update(int pos, int val, int v, int tl, int tr) {
		if (tl == tr) {
			sum[v] += val;
			min_pref[v] = min(0, sum[v]);
		} else {
			int tm = (tl + tr) >> 1;
			if (pos <= tm) {
				update(pos, val, v * 2, tl, tm);
			} else {
				update(pos, val, v * 2 + 1, tm + 1, tr);
			}
			sum[v] = sum[v * 2] + sum[v * 2 + 1];
			min_pref[v] = min(min_pref[v * 2], sum[v * 2] + min_pref[v * 2 + 1]);
		}
	}

	void add(int pos, int val) {
		// cerr << "add " << pos << " " << val << endl;
		update(pos, val, 1, 0, n - 1);
	}

	int get() {
		return (sum[1] > min_pref[1]);
	}
};

const int mx = 3e5 + 228;
int n, p[mx], q[mx], _p[mx];
st T;

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i]--;
		_p[p[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> q[i];
		q[i]--;
	}
	T.init(n);
	int res = n;
	for (int i = 0; i < n; ++i) {
		while (res && T.get() == 0) {
			T.add(_p[res - 1], 1);
			res--;
		}
		cout << res + 1 << "\n";
		T.add(q[i], -1);
	}
}