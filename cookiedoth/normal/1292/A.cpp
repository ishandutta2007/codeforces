/*

Code for problem A by cookiedoth
Generated 19 Jan 2020 at 04.36 P


 ] 
 
Il] 


~_^
=_=
\_()_/

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

const int mx = 1e5 + 228;
int n, q, a[2][mx], cnt;

void add(int x1, int y1, int x2, int y2, int mod) {
	cnt += (a[x1][y1] & a[x2][y2]) * mod;
}

void handle(int x, int y, int mod) {
	if (y > 0) {
		add(x, y, x ^ 1, y - 1, mod);
	}
	add(x, y, x ^ 1, y, mod);
	if (y < n - 1) {
		add(x, y, x ^ 1, y + 1, mod);
	}
}

signed main() {
	fast_io();
	cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		int r, c;
		cin >> r >> c;
		r--;
		c--;
		handle(r, c, -1);
		a[r][c] ^= 1;
		handle(r, c, 1);
		cout << (cnt ? "No" : "Yes") << "\n";
	}
}