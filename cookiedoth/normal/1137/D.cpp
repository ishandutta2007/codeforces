/*

Code for problem D by cookiedoth
Generated 09 Mar 2019 at 12.34 P



10%

30%

50%

70%

100%

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

const int D = 10;

vector<int> get(vector<int> v) {
	cout << "next";
	for (auto x : v) {
		cout << " " << x;
	}
	cout << endl;
	vector<int> res(D);
	int k;
	cin >> k;
	for (int i = 0; i < k; ++i) {
		string s;
		cin >> s;
		for (auto c : s) {
			res[c - '0'] = i;
		}
	}
	return res;
}

void go1() {
	while (true) {
		get({0, 1});
		vector<int> v = get({0});
		if (v[0] == v[1]) {
			break;
		}
	}
}

void go2() {
	while (true) {
		vector<int> v(10);
		iota(all(v), 0);
		vector<int> res = get(v);
		int ok = 1;
		for (int i = 1; i < D; ++i) {
			if (res[i] != res[i - 1]) {
				ok = 0;
			}
		}
		if (ok) {
			break;
		}
	}
	cout << "done" << endl;
}

signed main() {
	fast_io();
	go1();
	go2();
}