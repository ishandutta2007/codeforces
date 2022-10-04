/*

Code for problem C by savkinsd2089
Generated 11 Jan 2019 at 05.44 pm
The Moon is Waxing Crescent (25% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

\_()_/
\_()_/
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

struct segment {
	int l, r, id;
};

bool operator < (segment a, segment b) {
	return a.l < b.l;
}

const int mx = 2e5 + 228;
int n, ans[mx];
vector<segment> s;

void solve_one() {
	cin >> n;
	s.clear();
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		s.push_back({l, r, i});
	}

	int max_r = -1, ok = 0;
	sort(all(s));
	for (int i = 0; i < n - 1; ++i) {
		chkmax(max_r, s[i].r);
		if (max_r < s[i + 1].l) {
			for (int j = 0; j < n; ++j) {
				if (j <= i) {
					ans[s[j].id] = 1;
				}
				else {
					ans[s[j].id] = 2;
				}
			}
			ok = 1;
			break;
		}
	}
	if (ok) {
		output(ans, ans + n, cout);
	}
	else {
		cout << -1 << endl;
	}
}

signed main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		solve_one();
	}
}