/*

Code for problem D by cookiedoth
Generated 17 May 2020 at 01.18 PM


 ] 
 
Il] 


>_<
o_O
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

struct st {
	st() {}

	vector<int> t;
	int n;

	void init(int _n) {
		n = 1;
		while (n < _n) {
			n <<= 1;
		}
		t.resize(2 * n);
	}

	void insert(int x) {
		x += n;
		while (x >= 1) {
			t[x]++;
			x >>= 1;
		}
	}

	void remove_kth(int k) {
		int v = 1;
		while (true) {
			t[v]--;
			if (v >= n) {
				break;
			}
			if (t[v * 2] > k) {
				v = v * 2;
			} else {
				k -= t[v * 2];
				v = v * 2 + 1;
			}
		}
	}

	int get_any() {
		int v = 1;
		if (t[v] == 0) {
			return -1;
		}
		while (v < n) {
			if (t[v * 2]) {
				v = v * 2;
			} else {
				v = v * 2 + 1;
			}
		}
		return v - n;
	}
};

st T;
int n, q;

signed main() {
	fast_io();
	cin >> n >> q;
	T.init(n);
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		val--;
		T.insert(val);
	}
	for (int i = 0; i < q; ++i) {
		int x;
		cin >> x;
		if (x < 0) {
			T.remove_kth(-x - 1);
		} else {
			T.insert(x - 1);
		}
	}
	int res = T.get_any();
	cout << res + 1 << '\n';
}