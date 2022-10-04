/*

Code for problem C by savkinsd2089
Generated 25 Oct 2018 at 06.05 pm
The Moon is Waning Gibbous (99% of Full)


 ] 
 
Il] 


-_-
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

const int mx = 2e5 + 228;
int n, cx, cy, px[mx], py[mx], x, y;
string s;

const vector<pair<int, int> > d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
const string s0 = "UDLR";

pair<int, int> get(char c) {
	for (int i = 0; i < s0.size(); ++i) {
		if (c == s0[i]) {
			return d[i];
		}
	}
	assert(0);
	return {-1, -1};
}

int check(int len) {
	if (len == n + 1)
		return 1;
	for (int i = 0; i <= n - len; ++i) {
		int sum_x = x - (px[i + len] - px[i]);
		int sum_y = y - (py[i + len] - py[i]);
		if (abs(cx - sum_x) + abs(cy - sum_y) <= len) {
			//cerr << "ok " << len << endl;
			//cerr << i << ".." << i + len << endl;
			//cerr << sum_x << " " << sum_y << endl;
			return 1;
		}
	}
	return 0;
}

signed main() {
	cin >> n;
	cin >> s;
	cin >> cx >> cy;
	if ((abs(cx) + abs(cy)) % 2 != n % 2) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		pair<int, int> pp = get(s[i]);
		px[i + 1] = px[i] + pp.first;
		py[i + 1] = py[i] + pp.second;
	}
	x = px[n];
	y = py[n];
	//output(px, px + n + 1);
	//output(py, py + n + 1);

	int l = 0, r = n + 1;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	int ans = l;
	if (ans == n + 1)
		ans = -1;
	cout << ans << endl;
}