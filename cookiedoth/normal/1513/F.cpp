/*

Code for problem F by cookiedoth
Generated 11 Apr 2021 at 06.23 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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

struct st {
	st() {}

	vector<int> lo, hi;
	int n;

	void build(int *arr, int v, int tl, int tr) {
		if (tl == tr) {
			lo[v] = hi[v] = arr[tl];
		} else {
			int tm = (tl + tr) >> 1;
			build(arr, v * 2, tl, tm);
			build(arr, v * 2 + 1, tm + 1, tr);
			lo[v] = min(lo[v * 2], lo[v * 2 + 1]);
			hi[v] = max(hi[v * 2], hi[v * 2 + 1]);
		}
	}

	st(int *arr, int _n): n(_n) {
		lo.resize(4 * n);
		hi.resize(4 * n);
		build(arr, 1, 0, n - 1);
	}

	int leftSmaller(int pos, int val, int v, int tl, int tr) {
		if (tl == tr) {
			return tl - (lo[v] >= val);
		}
		int tm = (tl + tr) >> 1, res = tm;
		if (pos >= tm + 1 && lo[v * 2 + 1] < val) {
			res = leftSmaller(pos, val, v * 2 + 1, tm + 1, tr);
		}
		return (res != tm ? res : leftSmaller(pos, val, v * 2, tl, tm));
	}

	int leftSmaller(int pos, int val) {
		return leftSmaller(pos, val, 1, 0, n - 1);
	}

	int rightGreater(int pos, int val, int v, int tl, int tr) {
		if (tl == tr) {
			return tl + (hi[v] <= val);
		}
		int tm = (tl + tr) >> 1, res = tm + 1;
		if (pos <= tm && hi[v * 2] > val) {
			res = rightGreater(pos, val, v * 2, tl, tm);
		}
		return (res != tm + 1 ? res : rightGreater(pos, val, v * 2 + 1, tm + 1, tr));
	}

	int rightGreater(int pos, int val) {
		return rightGreater(pos, val, 1, 0, n - 1);
	}
};

const int mx = 2e5 + 228;
int n, a[mx], b[mx], decr;
vector<pair<int, int>> coords;

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		coords.emplace_back(a[i], i);
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		coords.emplace_back(b[i], i + n);
	}
	sort(all(coords));
	for (int i = 0; i < n; ++i) {
		a[i] = lower_bound(all(coords), make_pair(a[i], i)) - coords.begin();
		b[i] = lower_bound(all(coords), make_pair(b[i], i + n)) - coords.begin();
	}
}

const int INF = 1e9;
int match[2 * mx];
st T1, T2;

void setMatch(int def) {
	fill(match, match + 2 * n + 1, def);
	for (int i = 0; i < n; ++i) {
		if (a[i] < b[i]) {
			match[b[i]] = a[i];
		}
	}
}

void setMatch2(int def) {
	fill(match, match + 2 * n + 1, def);
	for (int i = 0; i < n; ++i) {
		if (b[i] < a[i]) {
			match[a[i]] = b[i];
		}
	}
}

void setMatch3(int def) {
	fill(match, match + 2 * n + 1, def);
	for (int i = 0; i < n; ++i) {
		if (b[i] < a[i]) {
			match[b[i]] = a[i];
		}
	}
}

void solve() {
	setMatch(INF);
	for (int i = 2 * n - 1; i >= 0; --i) {
		chkmin(match[i], match[i + 1]);
	}
	for (int i = 0; i < n; ++i) {
		if (b[i] < a[i] && match[a[i] + 1] < b[i]) {
			chkmax(decr, coords[a[i]].first - coords[b[i]].first);
		}
	}
	setMatch2(INF);
	T1 = st(match, 2 * n);
	// cerr << "match\n";
	// output(match, match + 2 * n);
	setMatch3(-INF);
	T2 = st(match, 2 * n);
	for (int i = 0; i < n; ++i) {
		if (a[i] < b[i]) {
			// cerr << "opa " << i << '\n';
			// cerr << "leftSmaller " << b[i] - 1 << " " << a[i] << '\n';
			int p1 = T1.leftSmaller(b[i] - 1, a[i]);
			if (p1 > a[i]) {
				chkmax(decr, coords[p1].first - coords[a[i]].first);
			}
			int p2 = T2.rightGreater(a[i] + 1, b[i]);
			if (p2 < b[i]) {
				chkmax(decr, coords[b[i]].first - coords[p2].first);
			}
		}
	}
}

void supersolve() {
	// cerr << "ab\n";
	solve();
	// cerr << "decr = " << decr << '\n';
	swap(a, b);
	// output(a, a + n);
	// output(b, b + n);
	solve();
	// cerr << "decr = " << /decr << '\n';
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += abs(coords[a[i]].first - coords[b[i]].first);
	}
	ans -= (ll)2 * (ll)decr;
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	supersolve();
}