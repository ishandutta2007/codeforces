/*

Code for problem B by cookiedoth
Generated 15 Dec 2019 at 02.05 P


 ] 
 
Il] 


-_-
z_z
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

const int mx = 300;
int n, a[mx];
vector<int> op;

void make_op(int pos) {
	a[pos] ^= 1;
	a[pos + 1] ^= 1;
	op.push_back(pos);
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		if (c == 'B') {
			a[i] = 1;
		}
	}
	for (int i = n - 1; i > 0; --i) {
		if (a[i]) {
			make_op(i - 1);
		}
	}
	if (a[0]) {
		if (n % 2 == 0) {
			cout << -1 << endl;
			exit(0);
		} else {
			for (int i = 1; i < n; i += 2) {
				make_op(i);
			}
		}
	}
	cout << op.size() << endl;
	for (auto x : op) {
		cout << x + 1 << " ";
	}
	cout << endl;
}