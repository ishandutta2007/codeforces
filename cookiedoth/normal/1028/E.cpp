/*

Code for problem E by savkinsd2089
Generated 27 Aug 2018 at 08.44 pm
The Moon is Waning Gibbous (99% of Full)










(@)(@)(@)(@)(@)

o_O
=_=
o_O

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

const int mx = 2e5;
int n, start_pos;
ll a[mx], a1[mx], b[mx], b1[mx], is_max[mx];

signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ll max_val = (*max_element(a, a + n));
	for (int i = 0; i < n; ++i) {
		is_max[i] = (a[i] == max_val);
	}
	start_pos = -1;
	for (int i = 0; i < n; ++i) {
		if (is_max[i] && (!is_max[(i - 1 + n) % n]))
			start_pos = (i + 1) % n;
	}
	if (start_pos == -1) {
		if (a[0] == 0) {
			cout << "YES" << endl;
			for (int i = 0; i < n; ++i) {
				cout << 1 << " ";
			}
			cout << endl;
			return 0;
		}
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		a1[i] = a[(i + start_pos) % n];
	}
	//cerr << "start_pos = " << start_pos << endl;
	//output(a1, a1 + n);
	b1[n - 1] = a1[n - 1];
	if (a1[n - 2] == 0) {
		b1[n - 2] = b1[n - 1] * 2;
	}
	else {
		b1[n - 2] = b1[n - 1] + a1[n - 2];
	}
	for (int i = n - 3; i >= 0; --i) {
		b1[i] = b1[i + 1] + a1[i];
	}
	//output(b1, b1 + n);
	for (int i = 0; i < n; ++i) {
		b[(i + start_pos) % n] = b1[i];
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		cout << b[i] << " ";
	}
	cout << endl;
}