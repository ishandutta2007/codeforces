/*

Code for problem G by cookiedoth
Generated 19 May 2020 at 10.34 PM


  !











o_O
-_-
z_z

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

mt19937 rng(58);

int get(const vector<int> &a, const vector<int> &b) {
	cout << "? " << a.size() << " " << b.size() << endl;
	for (auto id : a) {
		cout << id + 1 << " ";
	}
	cout << endl;
	for (auto id : b) {
		cout << id + 1 << " ";
	}
	cout << endl;
	string res;
	cin >> res;
	if (res == "FIRST") {
		return 1;
	}
	if (res == "EQUAL") {
		return 0;
	}
	if (res == "SECOND") {
		return -1;
	}
	exit(0);
}

void guess(int pos) {
	cout << "! " << pos + 1 << endl;
	return;
}

vector<int> seg_vector(int l, int r) {
	vector<int> res;
	for (int i = l; i <= r; ++i) {
		res.push_back(i);
	}
	return res;
}

int n, k;

const int BIN_ITERS = 30;

void process(int l, int r) {
	while (l < r) {
		int mid = (l + r) >> 1;
		if (get(seg_vector(0, mid - l), seg_vector(l, mid)) == 0) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	guess(l);
}

void solve() {
	cin >> n >> k;
	for (int it = 0; it < BIN_ITERS; ++it) {
		int pos = 0;
		while (!pos) {
			pos = rng() % n;
		}
		if (get({0}, {pos}) == -1) {
			guess(0);
			return;
		}
	}
	int cnt = 1;
	while (2 * cnt <= n) {
		if (get(seg_vector(0, cnt - 1), seg_vector(cnt, 2 * cnt - 1)) == 0) {
			cnt *= 2;
		} else {
			break;
		}
	}
	int l = cnt, r = min(2 * cnt - 1, n - 1);
	process(l, r);
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}