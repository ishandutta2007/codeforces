/*

Code for problem C by savkinsd2089
Generated 08 Aug 2018 at 08.14 pm
The Moon is Waning Crescent (11% of Full)










(@)(@)(@)(@)(@)

o_O
^_^
=_=

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

signed main() {
	int n;
	cin >> n;
	int block;
	for (int i = 1; i <= n; ++i) {
		if (i * i >= n) {
			block = i;
			break;
		}
	}
	vector<int> res;
	for (int i = 0; i < n; i += block) {
		int r = min(n - 1, i + block - 1);
		for (int j = r; j >= i; --j) {
			res.push_back(j);
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << res[i] + 1 << " ";
	}
	cout << endl;
}