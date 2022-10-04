/*

Code for problem B by savkinsd2089
Generated 27 Aug 2018 at 07.40 pm
The Moon is Waning Gibbous (99% of Full)


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

o_O
-_-
~_^

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

const int LEN = 1000;

signed main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < LEN; ++i) {
		cout << 9;
	}
	for (int i = 0; i < LEN - 1; ++i) {
		cout << 0;
	}
	cout << 1 << endl;
	for (int i = 0; i < LEN; ++i) {
		cout << 9;
	}
	cout << endl;
}