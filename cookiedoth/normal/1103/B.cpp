/*

Code for problem B by savkinsd2089
Generated 22 Jan 2019 at 05.47 pm
The Moon is Waning Gibbous (97% of Full)


 ] 
 
Il] 


\_()_/
>_<
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

int a;

int get(int x, int y) {
	cout << "? " << x << " " << y << endl;
	char c;
	cin >> c;
	if (c == 'x') {
		return 1;
	}
	else {
		return 0;
	}
	/*if ((x % a) >= (y % a)) {
		return 1;
	}
	else {
		return 0;
	}*/
}

void go() {
	int l = 1, r = 2;
	for (int i = 0; i < 29; ++i) {
		int res = get(l, r);
		if (res) {
			break;
		}
		else {
			l <<= 1;
			r <<= 1;
		}
	}

	if (l != 1) {
		l++;
	}

	while (r - l > 1) {
		int mid = ((l + r) >> 1);
		mid -= mid % 2;
		int res = get(mid / 2, mid);
		if (res) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	if (l == r) {
		cout << "! " << l << endl;
	}
	else {
		int res = get(l - 1, l);
		if (res) {
			cout << "! " << l << endl;
		}
		else {
			cout << "! " << r << endl;
		}
	}
}

signed main() {
	fast_io();
	string s;
	while (cin >> s) {
		if (s == "start") {
			//cin >> a;
			go();
		}
		else {
			break;
		}
	}
}