/*

Code for problem C by savkinsd2089
Generated 18 Oct 2018 at 07.44 pm
The Moon is Waxing Gibbous (68% of Full)


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

>_<
>_<
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

const int mx = 1228;
int n, l[mx], r[mx], a[mx], l1[mx], r1[mx];
vector<pair<int, int> > v;

signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> l[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> r[i];
	}
	for (int i = 0; i < n; ++i) {
		v.push_back({l[i] + r[i], i});
	}
	sort(v.begin(), v.end());
	vector<int> coords;
	for (int i = 0; i < n; ++i) {
		coords.push_back(v[i].first);
	}
	sort(all(coords));
	coords.erase(unique(all(coords)), coords.end());
	for (int i = 0; i < n; ++i) {
		a[i] = lower_bound(all(coords), l[i] + r[i]) - coords.begin();
		a[i] = n - a[i];
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[j] > a[i]) {
				l1[i]++;
			}
		}
		for (int j = i + 1; j < n; ++j) {
			if (a[j] > a[i]) {
				r1[i]++;
			}
		}
	}
	/*output(a, a + n);
	output(l1, l1 + n);
	output(r1, r1 + n);*/
	for (int i = 0; i < n; ++i) {
		if (l[i] != l1[i] || r[i] != r1[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; ++i) {
		cout << a[i] << " ";
	}
	cout << endl;
}