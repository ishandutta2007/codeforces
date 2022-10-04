/*

Code for problem C by savkinsd2089
Generated 23 Sep 2018 at 04.13 pm
The Moon is Waxing Gibbous (98% of Full)










(@)(@)(@)(@)(@)

z_z
o_O
>_<

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

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int mx = 1000;
int n, a[mx];

signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for (int pos = 0; pos < n - 1; ++pos) {
		int sum0 = 0;
		for (int i = 0; i <= pos; ++i) {
			sum0 += a[i];
		}
		int sum = 0, ok = 1;
		for (int i = pos + 1; i < n; ++i) {
			if (sum == sum0 && a[i] > 0)
				sum = 0;
			sum += a[i];
			if (sum > sum0) {
				ok = 0;
				break;
			}
		}
		if (ok && sum == sum0) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}