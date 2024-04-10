/*

Code for problem D by cookiedoth
Generated 10 Oct 2020 at 06.24 PM


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
#include <random>
#include <utility>
#include <tuple>
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

int n, l, r, delta;
vector<int> a, _a;
vector<vector<int> > ans;

void detect() {
	_a.resize(n);
	for (int i = 0; i < n; ++i) {
		_a[a[i]] = i;
	}
	if (n >= 2 && abs(_a[1] - _a[0]) == 1) {
		l = r = _a[0];
		delta = _a[1] - _a[0];
		for (int i = 1; i < n; ++i) {
			if (_a[i] - _a[i - 1] == delta) {
				chkmin(l, _a[i]);
				chkmax(r, _a[i]);
			} else {
				break;
			}
		}
	} else {
		l = r = _a[0];
		delta = 1;
	}
}

void change(const vector<int> &len) {
	// output(all(len));
	ans.push_back(len);
	int pos = n;
	vector<int> a1;
	for (int i = length(len) - 1; i >= 0; --i) {
		pos -= len[i];
		copy(a.begin() + pos, a.begin() + pos + len[i], back_inserter(a1));
	}
	a = a1;
}

int pivot;

int update() {
	pivot = r - l + 1;
	if (pivot == n) {
		if (delta == -1) {
			change(vector<int> (n, 1));
		}
		return 1;
	}
	int pos = _a[pivot];
	vector<int> lens;
	if (pos < l) {
		if (pos) {
			lens.push_back(pos);
		}
		lens.push_back(l - pos);
		if (delta == -1) {
			for (int it = 0; it < pivot; ++it) {
				lens.push_back(1);
			}
		} else {
			lens.push_back(pivot);
		}
		if (r < n - 1) {
			lens.push_back(n - 1 - r);
		}
	}
	if (pos > r) {
		if (l) {
			lens.push_back(l);
		}
		if (delta == 1) {
			for (int it = 0; it < pivot; ++it) {
				lens.push_back(1);
			}
		} else {
			lens.push_back(pivot);
		}
		lens.push_back(pos - r);
		if (pos < n - 1) {
			lens.push_back(n - 1 - pos);
		}
	}
	change(lens);
	return 0;
}

void read() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
}

void process() {
	while (true) {
		detect();
		// cerr << "lr = " << l << " " << r << endl;
		if (update()) {
			break;
		}
	}
}

void print_ans() {
	assert(ans.size() <= n);
	cout << ans.size() << '\n';
	for (const auto &v : ans) {
		cout << v.size();
		for (auto x : v) {
			cout << ' ' << x;
		}
		cout << '\n';
	}
}

signed main() {
	fast_io();
	read();
	process();
	print_ans();
}