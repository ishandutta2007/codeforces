/*

Code for problem A by cookiedoth
Generated 12 Jul 2020 at 05.49 PM










(@)(@)(@)(@)(@)

>_<
\_()_/
^_^

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
#define rall(a) a.rbegin(), a.rend()
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

const int mx = 1e5 + 228;
int n, p[mx];
pair<int, int> pref_min[mx], suf_min[mx];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}
	pref_min[0] = {p[0], 0};
	for (int i = 1; i < n; ++i) {
		pref_min[i] = min(pref_min[i - 1], {p[i], i});
	}
	suf_min[n - 1] = {p[n - 1], n - 1};
	for (int i = n - 2; i >= 0; --i) {
		suf_min[i] = min(suf_min[i + 1], {p[i], i});
	}
	for (int i = 1; i < n - 1; ++i) {
		if (p[i] > pref_min[i - 1].first && p[i] > suf_min[i + 1].first) {
			cout << "YES\n";
			cout << pref_min[i - 1].second + 1 << " " << i + 1 << " " << suf_min[i + 1].second + 1 << '\n';
			return;
		}
	}
	cout << "NO\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}