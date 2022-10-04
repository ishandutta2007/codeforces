/*

Code for problem E by savkinsd2089
Generated 09 Jan 2019 at 05.39 pm
The Moon is Waxing Crescent (11% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

o_O
\_()_/
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

template<class T> struct compressor {
	vector<T> v;

	void push(T x) {
		v.push_back(x);
	}

	void compress() {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}

	int get(T x) {
		return lower_bound(v.begin(), v.end(), x) - v.begin();
	}

	int size() {
		return v.size();
	}
};

const ll MOD = 998244353;
const int mx = 2e5 + 228;
int n, a[mx], pos[mx], t[mx], max_pref_pos[mx];

signed main() {
	cin >> n;
	compressor<int> c;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		c.push(a[i]);
	}

	c.compress();

	for (int i = 0; i < n; ++i) {
		a[i] = c.get(a[i]);
	}

	int sz = c.size();
	for (int i = 0; i < sz; ++i) {
		pos[i] = -1;
	}
	for (int i = n - 1; i >= 0; --i) {
		if (pos[a[i]] == -1) {
			pos[a[i]] = i;
		}
	}
	for (int i = 0; i < n; ++i) {
		t[i] = pos[a[i]];
	}

	for (int i = 1; i <= n; ++i) {
		max_pref_pos[i] = max(max_pref_pos[i - 1], t[i - 1]);
	}

	ll ans = 1;
	for (int i = 0; i < n - 1; ++i) {
		if (max_pref_pos[i + 1] <= i) {
			ans = (ans + ans) % MOD;
		}
	}

	cout << ans << endl;
}