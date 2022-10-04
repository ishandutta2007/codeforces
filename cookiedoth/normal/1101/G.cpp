/*

Code for problem G by savkinsd2089
Generated 11 Jan 2019 at 06.35 pm
The Moon is Waxing Crescent (26% of Full)


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

^_^
-_-
>_<

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

const int lg = 31;

int first1(int x) {
	if (x == 0)
		return -1;
	int z = __builtin_clz(x);
	return lg - z;
}

vector<int> get(vector<int> a) {
	vector<int> res;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		for (int j = 0; j < res.size(); ++j) {
			if (first1(x) == first1(res[j])) {
				x ^= res[j];
			}
		}
		if (x != 0)
			res.push_back(x);
		sort(res.rbegin(), res.rend());
	}
	return res;
}

int n;
vector<int> a, pref;

signed main() {
	cin >> n;
	a.resize(n);
	pref.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	pref[0] = a[0];
	for (int i = 1; i < n; ++i) {
		pref[i] = pref[i - 1] ^ a[i];
	}

	if (pref.back() == 0) {
		cout << -1 << endl;
		return 0;
	}
	reverse(all(pref));

	vector<int> res = get(pref);
	cout << res.size() << endl;
}