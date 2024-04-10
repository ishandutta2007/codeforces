/*

Code for problem B by savkinsd2089
Generated 08 Aug 2018 at 08.09 pm
The Moon is Waning Crescent (11% of Full)


 ] 
 
Il] 


^_^
^_^
=_=

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

ll n, cnt[4];
string s1, s2;

signed main() {
	cin >> n >> s1 >> s2;
	for (int i = 0; i < n; ++i) {
		int val = (s1[i] - '0') * 2 + (s2[i] - '0');
		cnt[val]++;
	}
	ll ans = cnt[0] * (cnt[2] + cnt[3]) + cnt[1] * cnt[2];
	cout << ans << endl;
}