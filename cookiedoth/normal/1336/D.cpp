/*

Code for problem D by cookiedoth
Generated 15 Apr 2020 at 07.47 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

~_^
=_=
\_()_/

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
#define y0 Y0

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

#ifdef TESTING
namespace interactor {
	int n;
	vector<int> a, a0;

	void get(int &x, int &y) {
		x = 0;
		y = 0;
		for (int i = 0; i < n; ++i) {
			x += a[i] * (a[i] - 1) * (a[i] - 2) / 6;
		}
		for (int i = 0; i <= n - 3; ++i) {
			y += a[i] * a[i + 1] * a[i + 2];
		}
		cerr << "get " << x << " " << y << endl;
	}

	void init(int &_n, int &x, int &y) {
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		a0 = a;
		get(x, y);
		_n = n;
	}

	void update(int pos, int &x, int &y) {
		a[pos]++;
		get(x, y);
	}

	void guess(vector<int> v) {
		output(all(a0));
		output(all(v));
		assert(v == a0);
	}
}
#else
namespace interactor {
	void init(int &n, int &x, int &y) {
		cin >> n;
		cin >> x >> y;
	}

	void update(int pos, int &x, int &y) {
		cout << "+ " << pos + 1 << endl;
		cin >> x >> y;
	}

	void guess(vector<int> v) {
		cout << "! ";
		for (int i = 0; i < v.size(); ++i) {
			cout << v[i] << " ";
		}
		cout << endl;
	}
}
#endif

vector<int> dx, dy;

int n, x, y, x0, y0;
vector<int> order;
vector<vector<int> > coef, iters;

void add_to_order(int x) {
	coef.push_back(coef.back());
	coef.back()[x]++;
	iters[x].push_back(order.size());
	order.push_back(x);
}

void build_order() {
	iters.resize(n);
	coef.push_back(vector<int> (n));
	add_to_order(0);
	add_to_order(1);
	add_to_order(2);
	add_to_order(0);
	for (int i = 3; i < n - 1; ++i) {
		add_to_order(i);
	}
}

void interact() {
	interactor::init(n, x, y);
	x0 = x;
	y0 = y;

	build_order();
	// cerr << "kek" << endl;
	for (int i = 0; i < n; ++i) {
		int x1, y1;
		interactor::update(order[i], x1, y1);
		dx.push_back(x1 - x);
		dy.push_back(y1 - y);
		x = x1;
		y = y1;
	}
}

vector<int> initial;

int check_y(int iter) {
	int pos = order[iter];
	for (int i = max(pos - 2, 0); i <= min(n - 1, pos + 2); ++i) {
		if (initial[i] == -1) {
			return 1;
		}
	}

	int ok = 1;
	int res = 0;
	for (int st = max(pos - 2, 0); st <= min(pos, n - 3); ++st) {
		int cur = 1;
		for (int pos1 = st; pos1 < st + 3; ++pos1) {
			if (pos1 != pos) {
				cur *= (initial[pos1] + coef[iter][pos1]);
			}
		}
		res += cur;
	}
	return (res == dy[iter]);
}

int func(int x) {
	return x * (x - 1) * (x - 2) / 6;
}

int check_x(int iter) {
	int pos = order[iter];
	return (func(initial[pos] + coef[iter][pos] + 1) - func(initial[pos] + coef[iter][pos]) == dx[iter]);
}

void bruteforce(int iter) {
	// cerr << "bruteforce " << iter << endl;
	int coord = order[iter];
	if (iter == n) {
		int cur_x = 0;
		int cur_y = 0;
		for (int i = 0; i < n; ++i) {
			cur_x += initial[i] * (initial[i] - 1) * (initial[i] - 2) / 6;
		}
		for (int i = 0; i <= n - 3; ++i) {
			cur_y += initial[i] * initial[i + 1] * initial[i + 2];
		}
		if (cur_x == x0 && cur_y == y0) {
			interactor::guess(initial);
			exit(0);
		} else {
			return;
		}
	}
	if (initial[coord] == -1) {
		for (int val = 0; val <= n; ++val) {
			initial[coord] = val;
			bruteforce(iter);
		}
	} else {
		int ok = 1;
		for (int i = max(0, coord - 2); i <= min(n - 1, coord + 2); ++i) {
			for (auto id : iters[i]) {
				ok &= check_y(id);
			}
		}
		ok &= check_x(iter);
		// cerr << "check" << endl;
		// output(all(initial));
		// cerr << "ok = " << ok << endl;
		if (ok) {
			bruteforce(iter + 1);
		}
		initial[coord] = -1;
	}
}

signed main() {
	fast_io();
	interact();
	initial.resize(n, -1);
	coef.resize(n);
	for (initial[n - 1] = 0; initial[n - 1] <= n; initial[n - 1]++) {
		bruteforce(0);
	}
}