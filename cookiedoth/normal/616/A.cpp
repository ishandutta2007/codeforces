/*

Code for problem A by savkinsd2089
Generated 15 Dec 2018 at 03.18 pm
The Moon is at the First Quarter


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

\_()_/
~_^
-_-

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

vector<int> v1, v2;

void read(vector<int> &v) {
	string s;
	cin >> s;
	int n = s.size();
	v.resize(n);
	for (int i = 0; i < n; ++i) {
		v[i] = s[n - 1 - i] - '0';
	}
}

signed main() {
	fast_io();
	read(v1);
	read(v2);
	int sz = max(v1.size(), v2.size());
	v1.resize(sz);
	v2.resize(sz);
	for (int i = sz - 1; i >= 0; --i) {
		if (v1[i] > v2[i]) {
			cout << ">" << endl;
			return 0;
		}
		if (v1[i] < v2[i]) {
			cout << "<" << endl;
			return 0;
		}
	}
	cout << "=" << endl;
	return 0;
}