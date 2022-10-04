/*

Code for problem D by savkinsd2089
Generated 15 Dec 2018 at 03.35 pm
The Moon is at the First Quarter


  !











=_=
=_=
^_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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

#ifndef TESTING
	#define endl '\n'
#endif

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

const int MX = 1e6 + 228;

int cnt[MX], cnt_diff;

void add(int pos, int val) {
	if (cnt[pos] > 0) {
		cnt_diff--;
	}
	cnt[pos] += val;
	if (cnt[pos] > 0) {
		cnt_diff++;
	}
}

const int mx = 5e5 + 228;
int n, k, a[mx], len, l, r;

signed main() {
	fast_io();
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ptr = 0;
	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			add(a[i - 1], -1);
		}
		while (cnt_diff <= k && ptr < n) {
			add(a[ptr], 1);
			ptr++;
		}
		if (cnt_diff <= k) {
			if (chkmax(len, ptr - i)) {
				l = i;
				r = ptr - 1;
			}
		}
		else {
			if (chkmax(len, ptr - i - 1)) {
				l = i;
				r = ptr - 2;
			}
		}
	}

	cout << l + 1 << " " << r + 1 << endl;
}