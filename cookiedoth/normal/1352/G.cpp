/*

Code for problem G by cookiedoth
Generated 09 May 2020 at 07.05 PM


  !











=_=
>_<
o_O

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

int n;

void process(int x, int dx, vector<int> &ans) {
	int pos = x;
	while (pos < n) {
		ans.push_back(pos);
		pos += 2 * dx;
	}
	pos -= dx;
	if (pos >= n) {
		pos -= 2 * dx;
	}
	while (pos >= x) {
		ans.push_back(pos);
		pos -= 2 * dx;
	}
}

void process1(int x, int dx, vector<int> &ans) {
	ans.push_back(x + dx);
	ans.push_back(x);
	if (x + 2 * dx < n) {
		process(x + 2 * dx, dx, ans);
	}
}

void solve() {
	cin >> n;
	if (n <= 3) {
		cout << -1 << endl;
		return;
	}
	vector<int> v1, v2;
	process(0, 2, v1);
	process1(1, 2, v2);
	reverse(all(v2));
	for (auto x : v1) {
		v2.push_back(x);
	}
	for (auto x : v2) {
		cout << x + 1 << " ";
	}
	cout << endl;
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}