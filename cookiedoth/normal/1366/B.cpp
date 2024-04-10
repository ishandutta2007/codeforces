/*

Code for problem B by cookiedoth
Generated 11 Jun 2020 at 09.25 PM


  !











z_z
=_=
\_()_/

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

int n, m, x;
vector<pair<int, int> > seg;

void insert_seg(int l, int r) {
	vector<pair<int, int> > new_seg;
	for (auto pp : seg) {
		if (pp.second < l || pp.first > r) {
			new_seg.push_back(pp);
		} else {
			chkmin(l, pp.first);
			chkmax(r, pp.second);
		}
	}
	new_seg.emplace_back(l, r);
	sort(all(new_seg));
	seg = new_seg;
}

void solve() {
	cin >> n >> x >> m;
	seg = {{x, x}};
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		auto it = lower_bound(all(seg), make_pair(l, 0));
		if ((it != seg.end() && it->first <= r) || (it != seg.begin() && prev(it)->second >= l)) {
			insert_seg(l, r);
		}
	}
	int ans = 0;
	for (auto pp : seg) {
		ans += pp.second - pp.first + 1;
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}