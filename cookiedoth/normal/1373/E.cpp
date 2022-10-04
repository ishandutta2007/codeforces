/*

Code for problem E by cookiedoth
Generated 25 Jun 2020 at 05.50 PM


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

const int D = 10;

int smaller(const vector<int> &a, const vector<int> &b) {
	if (a.size() < b.size()) {
		return 1;
	}
	if (a.size() > b.size()) {
		return 0;
	}
	for (int i = (int)a.size() - 1; i >= 0; --i) {
		if (a[i] < b[i]) {
			return 1;
		}
		if (a[i] > b[i]) {
			return 0;
		}
	}
	return 0;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> opt;
	int S = k * (k + 1) / 2;
	// cerr << "S = " << S << endl;
	for (int d = 0; d < 100; ++d) {
		for (int last_digit = 0; last_digit < D; ++ last_digit) {
			int lst = last_digit + k;
			if ((lst < D) ^ (d == 0)) {
				continue;
			}
			int t = n - S + max(0, lst - D + 1) * (D - 1) * d;
			if (t % (k + 1) == 0) {
				int s = t / (k + 1);
				int sum = last_digit;
				if (d) {
					sum += (d - 1) * (D - 1);
				}
				if (s < sum) {
					continue;
				}
				vector<int> cur;
				cur.push_back(last_digit);
				for (int it = 0; it < d - 1; ++it) {
					cur.push_back(D - 1);
				}
				int maxD = (d == 0 ? D - 1 : D - 2);
				int rem = s - sum;
				while (rem) {
					int dig = min(rem, maxD);
					cur.push_back(dig);
					rem -= dig;
					maxD = D - 1;
				}
				if (cur.empty()) {
					cur = {0};
				}
				if (opt.empty() || smaller(cur, opt)) {
					opt = cur;
				}
			}
		}
	}
	if (opt.empty()) {
		cout << -1 << '\n';
	} else {
		reverse(all(opt));
		for (auto dig : opt) {
			cout << dig;
		}
		cout << '\n';
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}