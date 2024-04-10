/*

Code for problem E by savkinsd2089
Generated 11 Jan 2019 at 05.53 pm
The Moon is Waxing Crescent (25% of Full)


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

~_^
~_^
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

int max_x, max_y, n;

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		int w, h;
		cin >> c >> w >> h;
		if (w > h) {
			swap(w, h);
		}
		if (c == '+') {
			chkmax(max_x, w);
			chkmax(max_y, h);
		}
		else {
			if (w >= max_x && h >= max_y) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}