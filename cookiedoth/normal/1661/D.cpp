/*

Code for problem D by cookiedoth
Generated 09 Apr 2022 at 11.02 AM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

z_z
>_<
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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll __int128
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

istream& operator >> (istream &is, __int128 &x) {
	long long a;
	is >> a;
	x = (__int128)a;
	return is;
}

ostream& operator << (ostream &os, const __int128 &x) {
	os << (long long)x;
	return os;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

struct SegmentTree {
	ll* arr;
	int n;
	vector<ll> ta, tb;

	SegmentTree(ll* _arr, int _n): arr(_arr), n(_n) {
		ta.resize(4 * n);
		tb.resize(4 * n);
	}

	void update(int l, int r, ll a, ll b, int v, int tl, int tr) {
		if (r < tl || tr < l) {
			return;
		}
		if (l <= tl && tr <= r) {
			ta[v] += a + b * (ll)(tl - l);
			tb[v] += b;
			return;
		}
		int tm = (tl + tr) >> 1;
		update(l, r, a, b, v * 2, tl, tm);
		update(l, r, a, b, v * 2 + 1, tm + 1, tr);
	}

	void update(int l, int r, ll a, ll b) {
		// cerr << "update " << l << ' ' << r << ' ' << a << ' ' << b << '\n';
		update(l, r, a, b, 1, 0, n - 1);
	}

	ll get(int pos, int v, int tl, int tr) {
		if (tl == tr) {
			return arr[pos] + ta[v];
		} else {
			int tm = (tl + tr) >> 1;
			if (pos <= tm) {
				return get(pos, v * 2, tl, tm) + ta[v] + tb[v] * (ll)(pos - tl);
			} else {
				return get(pos, v * 2 + 1, tm + 1, tr) + ta[v] + tb[v] * (ll)(pos - tl);
			}
		}
	}

	ll get(int pos) {
		ll res = get(pos, 1, 0, n - 1);
		// cerr << "get " << pos << ' ' << res << '\n';
		return res;
	}
};

const int MAX_N = 3e5 + 228;
int n;
ll a[MAX_N], k;

signed main() {
	fast_io();
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	SegmentTree T(a, n);
	ll ans = 0;
	for (int i = n - 1; i >= k - 1; --i) {
		ll op = max((T.get(i) + k - 1) / k, (ll)0);
		T.update(i - k + 1, i, -op, -op);
		ans += op;
	}
	ll last_op = 0;
	for (int i = 0; i < k - 1; ++i) {
		chkmax(last_op, (T.get(i) + i) / (ll)(i + 1));
	}
	ans += last_op;
	cout << ans << '\n';
}