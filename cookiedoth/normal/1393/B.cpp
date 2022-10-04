/*

Code for problem B by cookiedoth
Generated 07 Aug 2020 at 07.50 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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

map<int, int> mp;
int cnt2, cnt4, cnt6, cnt8;

void handle_cnt(int cnt, int mult) {
	if (cnt >= 2) {
		cnt2 += mult;
	}
	if (cnt >= 4) {
		cnt4 += mult;
	}
	if (cnt >= 6) {
		cnt6 += mult;
	}
	if (cnt >= 8) {
		cnt8 += mult;
	}
}

int get() {
	return ((cnt4 && cnt2 >= 3) || (cnt6 && cnt2 >= 2) || (cnt4 >= 2) || (cnt8 >= 1));
}

void add(int x, int delta) {
	handle_cnt(mp[x], -1);
	mp[x] += delta;
	handle_cnt(mp[x], 1);
}

signed main() {
	fast_io();
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		add(x, 1);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		char c;
		cin >> c;
		int x;
		cin >> x;
		if (c == '+') {
			add(x, 1);
		} else {
			add(x, -1);
		}
		cout << (get() ? "YES" : "NO") << '\n';
	}
}