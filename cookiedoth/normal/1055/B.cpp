/*

Code for problem B by savkinsd2089
Generated 10 Nov 2018 at 05.41 pm
The Moon is Waxing Crescent (9% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

\_()_/
~_^
^_^

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
#include <numeric>
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

const int mx = 1e5 + 228;
ll n, m, l, a[mx], b[mx], ans = 0;

void make1(int i) {
	int cnt1 = 0;
	if (i > 0 && b[i - 1] == 1)
		cnt1++;
	if (i < n - 1 && b[i + 1] == 1)
		cnt1++;
	b[i] = 1;
	if (cnt1 == 0)
		ans++;
	if (cnt1 == 2)
		ans--;
}

signed main() {
	cin >> n >> m >> l;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] > l) {
			make1(i);
		}
	}
	for (int i = 0; i < m; ++i) {
		int type;
		cin >> type;
		if (type == 0) {
			cout << ans << endl;
		}
		else {
			int pos, val;
			cin >> pos >> val;
			pos--;
			if (a[pos] <= l && a[pos] + val > l) {
				make1(pos);
			}
			a[pos] += val;
		}
	}
}