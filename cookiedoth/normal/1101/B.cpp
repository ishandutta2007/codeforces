/*

Code for problem B by savkinsd2089
Generated 11 Jan 2019 at 05.39 pm
The Moon is Waxing Crescent (25% of Full)


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

^_^
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

string s;
int n, lpos, rpos;

signed main() {
	cin >> s;
	n = s.size();
	lpos = n;
	rpos = -1;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '[') {
			lpos = i;
			break;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (s[i] == ']') {
			rpos = i;
			break;
		}
	}

	if (lpos > rpos) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> d2;
	for (int i = lpos + 1; i < rpos; ++i) {
		if (s[i] == ':') {
			d2.push_back(i);
		}
	}

	if (d2.size() <= 1) {
		cout << -1 << endl;
		return 0;
	}

	int ans = 4;
	for (int i = d2[0] + 1; i < d2.back(); ++i) {
		if (s[i] == '|') {
			ans++;
		}
	}

	cout << ans << endl;
}