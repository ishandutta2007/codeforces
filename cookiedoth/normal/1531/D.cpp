/*

Code for problem D by cookiedoth
Generated 30 May 2021 at 01.01 PM










(@)(@)(@)(@)(@)

^_^
~_^
z_z

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
#include <chrono>
#include <array>
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

struct Node {
	array<char, 2> clr;
	int lock;

	Node() {}

	Node(const string& s) {
		if (s == "lock") {
			lock = 1;
			clr = {{'?', '?'}};
		} else if (s == "unlock") {
			lock = 0;
			clr = {{'?', '?'}};
		} else {
			lock = -1;
			clr = {{s[0], '?'}};
		}
	}

	void print() const {
		cerr << "lock = " << lock << ", clr = " << clr[0] << ' ' << clr[1] << '\n';
	}

	friend Node operator + (const Node& lhs, const Node& rhs) {
		// cerr << "operator +\n";
		// lhs.print();
		// rhs.print();
		Node res;
		res.lock = (rhs.lock == -1 ? lhs.lock : rhs.lock);
		for (int i = 0; i < 2; ++i) {
			int midlock = (lhs.lock == -1 ? i : lhs.lock);
			char L = lhs.clr[i];
			char R = rhs.clr[midlock];
			res.clr[i] = (R == '?' ? L : R);
		}
		// cerr << "result:\n";
		// res.print();
		return res;
	}
};

vector<string> colors = {
	"red", "orange", "yellow", "green", "blue", "indigo", "violet"
};

struct st {
	vector<Node> t;
	int n;

	void build(const vector<string>& dat, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = Node(dat[tl]);
		} else {
			int tm = (tl + tr) >> 1;
			build(dat, v * 2, tl, tm);
			build(dat, v * 2 + 1, tm + 1, tr);
			t[v] = t[v * 2] + t[v * 2 + 1];
		}
	}

	st(const vector<string>& dat) {
		n = dat.size();
		t.resize(4 * n);
		build(dat, 1, 0, n - 1);
	}

	void update(int pos, const string& val, int v, int tl, int tr) {
		if (tl == tr) {
			t[v] = Node(val);
		} else {
			int tm = (tl + tr) >> 1;
			if (pos <= tm) {
				update(pos, val, v * 2, tl, tm);
			} else {
				update(pos, val, v * 2 + 1, tm + 1, tr);
			}
			t[v] = t[v * 2] + t[v * 2 + 1];
		}
	}

	void update(int pos, const string& val) {
		update(pos, val, 1, 0, n - 1);
	}

	string get() {
		if (t[1].clr[0] == '?') {
			return "blue";
		} else {
			for (const auto& clrName : colors) {
				if (clrName[0] == t[1].clr[0]) {
					return clrName;
				}
			}
			assert(0);
		}
	}
};

signed main() {
	fast_io();
	int n;
	vector<string> dat;
	cin >> n;
	dat.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> dat[i];
	}
	st T(dat);
	cout << T.get() << '\n';
	int q;
	cin >> q;
	while (q--) {
		int pos;
		string val;
		cin >> pos >> val;
		pos--;
		T.update(pos, val);
		cout << T.get() << '\n';
	}
}