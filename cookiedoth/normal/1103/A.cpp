/*

Code for problem A by savkinsd2089
Generated 22 Jan 2019 at 05.29 pm
The Moon is Waning Gibbous (97% of Full)


  !











~_^
~_^
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

signed main() {
	fast_io();
	string s;
	cin >> s;
	int pos1 = 0, pos2 = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '0') {
			cout << 1 << " " << pos1 + 1 << endl;
			pos1++;
			if (pos1 == 4) {
				pos1 = 0;
			}
		}
		else {
			cout << 3 << " " << pos2 + 1 << endl;
			pos2 += 2;
			if (pos2 == 4) {
				pos2 = 0;
			}
		}
	}
}