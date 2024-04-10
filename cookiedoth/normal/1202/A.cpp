/*

Code for problem A by cookiedoth
Generated 08 Aug 2019 at 07.38 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

o_O
^_^
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

void solve() {
	string s1, s2;
	cin >> s1 >> s2;
	reverse(all(s1));
	reverse(all(s2));
	int p1 = -1, p2 = -1;
	for (int i = 0; i < s2.size(); ++i) {
		if (s2[i] == '1') {
			p2 = i;
			break;
		}
	}
	for (int i = p2; i < s1.size(); ++i) {
		if (s1[i] == '1') {
			p1 = i;
			break;
		}
	}
	if (p1 == -1) {
		cout << s1.size() << endl;
	}
	else {
		cout << p1 - p2 << endl;
	}
}

int T;

signed main() {
	fast_io();
	cin >> T;
	for (int i = 0; i < T; ++i) {
		solve();
	}
}