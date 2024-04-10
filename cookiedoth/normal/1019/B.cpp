/*

Code for problem B by savkinsd2089
Generated 11 Aug 2018 at 05.00 pm
The Moon is New










(@)(@)(@)(@)(@)

o_O
\_()_/
\_()_/

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

int n;

int sign(int x) {
	if (x < 0)
		return -1;
	if (x > 0)
		return 1;
	return 0;
}

int get(int pos) {
	int val1, val2;
	cout << "? " << pos + 1 << endl;
	cin >> val1;
	cout << "? " << pos + n / 2 + 1 << endl;
	cin >> val2;
	if (val1 == val2) {
		cout << "! " << pos + 1 << endl;
		exit(0);
	}
	return sign(val2 - val1);
}

void binsearch(int l, int r, int sl, int sr) {
	int mid = (l + r) >> 1;
	int s = get(mid);
	if (s != sl)
		binsearch(l, mid, sl, s);
	else
		binsearch(mid + 1, r, s, sr);
}

signed main() {
	cin >> n;
	if ((n >> 1) & 1) {
		cout << "! -1" << endl;
		return 0;
	}
	int vl = get(0), vr = get(n / 2 - 1);
	binsearch(0, n / 2 - 1, vl, vr);
}