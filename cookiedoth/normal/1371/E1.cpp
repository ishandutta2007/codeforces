/*

Code for problem E by cookiedoth
Generated 01 Jul 2020 at 05.53 PM


  !











\_()_/
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
int n, p, a[mx], x0, delta[mx], bad[mx], bound;

void read() {
	cin >> n >> p;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	x0 = (*max_element(a, a + n)) - (n - 1);
	for (int i = 0; i < n; ++i) {
		a[i] = max(0, a[i] - x0);
		delta[a[i]]++;
	}
	// cerr << "p = " << p << endl;
	// cerr << "x0 = " << x0 << endl;
	// output(delta, delta + n);
}

void solve() {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += delta[i];
		int id = ((i - sum) % p + p) % p;
		if (id <= i) {
			bad[id] = 1;
		}
	}
	bound = (((n - 1) - sum) % p + p) % p;
	// cerr << "bound = " << bound << endl;
	vector<int> ans;
	for (int i = 0; i < bound; ++i) {
		if (bad[i] == 0) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x + x0 << ' ';
	}
	cout << '\n';
}

signed main() {
	fast_io();
	read();
	solve();
}