/*

Code for problem C by cookiedoth
Generated 12 Aug 2020 at 06.09 PM










(@)(@)(@)(@)(@)

-_-
z_z
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

pair<int, int> read_string() {
	pair<int, int> res = {0, 0};
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'B') {
			res.first++;
		} else {
			res.second++;
		}
	}
	return res;
}

const int INF = 1e8;
int n, minX = INF;
vector<pair<int, int> > coords;

void read() {
	cin >> n;
	coords.resize(n);
	for (int i = 0; i < n; ++i) {
		coords[i] = read_string();
		// cerr << coords[i].first << " " << coords[i].second << endl;
		chkmin(minX, coords[i].first);
	}
}



int check1(int x, int k, int &ans, int &ansX, int &ansY) {
	int L = (x == 0 ? (-k + 1) : -INF), R = INF;
	for (int i = 0; i < n; ++i) {
		int cx = coords[i].first, cy = coords[i].second;
		if (cx - x > 2 * k) {
			return 0;
		}
		int dyL = (cx - x >= k ? cx - x - k : 0);
		int dyR = (cx - x >= k ? 2 * k : k + cx - x);
		chkmax(L, cy - dyR);
		chkmin(R, cy - dyL);
		if (L > R) {
			return 0;
		}
	}
	ansX = x + k;
	ansY = L + k;
	return 1;
}

int check(int k, int &ans, int &ansX, int &ansY) {
	// cerr << "check " << k << endl;
	// for (int i = 0; i < n; ++i) {
	// 	cerr << coords[i].first << " " << coords[i].second << endl;
	// }
	for (int x = 0; x <= minX; ++x) {
		if (check1(x, k, ans, ansX, ansY)) {
			return 1;
		}
	}
	return 0;
}

void binsearch(int &ans, int &ansX, int &ansY) {
	int l = 0, r = INF;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid, ans, ansX, ansY)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	check(l, ans, ansX, ansY);
	ans = l;
}

int ans1, ansX1, ansY1;
int ans2, ansX2, ansY2;
int ans, ansX, ansY;

void flip() {
	for (int i = 0; i < n; ++i) {
		swap(coords[i].first, coords[i].second);
	}
	minX = INF;
	for (int i = 0; i < n; ++i) {
		chkmin(minX, coords[i].first);
	}
}

void process() {
	binsearch(ans1, ansX1, ansY1);
	flip();
	binsearch(ans2, ansX2, ansY2);
	flip();
	if (ans1 <= ans2) {
		ans = ans1;
		ansX = ansX1;
		ansY = ansY1;
	} else {
		ans = ans2;
		ansX = ansY2;
		ansY = ansX2;
	}
}

void print_ans() {
	cout << ans << '\n';
	for (int i = 0; i < ansX; ++i) {
		cout << 'B';
	}
	for (int i = 0; i < ansY; ++i) {
		cout << 'N';
	}
	cout << '\n';
}

void check() {
	int res = 0;
	for (int i = 0; i < n; ++i) {
		if ((coords[i].first >= ansX) ^ (coords[i].second >= ansY)) {
			chkmax(res, abs(coords[i].first - ansX) + abs(coords[i].second - ansY));
		} else {
			chkmax(res, max(abs(coords[i].first - ansX), abs(coords[i].second - ansY)));
		}
	}
	// cerr << "res = " << res << endl;
	assert(res == ans);
}

signed main() {
	fast_io();
	read();
	process();
	print_ans();
	check();
}