/*

Code for problem B by cookiedoth
Generated 15 Apr 2020 at 05.45 PM



10%

30%

50%

70%

100%

^_^
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

const ll INF = 8e18;
const int ARR = 3;
vector<vector<pair<int, int> > > a;
ll ans;

ll sqr(ll x) {
	return x * x;
}

void relax(ll v1, ll v2, ll v3) {
	chkmin(ans, sqr(v1 - v2) + sqr(v1 - v3) + sqr(v2 - v3));
}

void solve() {
	vector<int> cnt(ARR);
	for (int i = 0; i < ARR; ++i) {
		cin >> cnt[i];
	}
	a.assign(ARR, vector<pair<int, int> > ());
	for (int i = 0; i < ARR; ++i) {
		for (int j = 0; j < cnt[i]; ++j) {
			int val;
			cin >> val;
			a[i].emplace_back(val, i);
		}
		sort(all(a[i]));
	}
	ans = INF;
	for (int a1 = 0; a1 < ARR; ++a1) {
		for (int a2 = a1 + 1; a2 < ARR; ++a2) {
			int a3 = -1;
			for (int i = 0; i < ARR; ++i) {
				if (i != a1 && i != a2) {
					a3 = i;
				}
			}
			assert(a3 != -1);
			vector<pair<int, int> > res(a[a1].size() + a[a2].size());
			merge(all(a[a1]), all(a[a2]), res.begin());
			for (int i = 0; i < (int)res.size() - 1; ++i) {
				if (res[i].second != res[i + 1].second) {
					int v1 = res[i].first, v2 = res[i + 1].first;
					int pos = lower_bound(all(a[a3]), make_pair((v1 + v2) / 2, 0)) - a[a3].begin();
					if (pos != a[a3].size()) {
						relax(v1, v2, a[a3][pos].first);
					}
					if (pos != 0) {
						relax(v1, v2, a[a3][pos - 1].first);
					}
				}
			}
		}
	}
	cout << ans << "\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}