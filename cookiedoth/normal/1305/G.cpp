/*

Code for problem G by cookiedoth
Generated 04 Mar 2020 at 04.15 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

\_()_/
^_^
-_-

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

const int mx = (1 << 18);
int p[mx], rnk[mx];

void init() {
	iota(p, p + mx, 0);
}

int get_root(int v) {
	return (p[v] == v ? v : p[v] = get_root(p[v]));
}

int join(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (u != v) {
		if (rnk[u] > rnk[v]) {
			swap(u, v);
		}
		p[u] = v;
		if (rnk[u] == rnk[v]) {
			rnk[v]++;
		}
		return 1;
	} else {
		return 0;
	}
}

ll ans = 0;
int n, cnt[mx], conn[mx];

signed main() {
	fast_io();
	init();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		ans -= val;
		cnt[val]++;
	}
	cnt[0]++;
	for (int e = mx - 1; e >= 0; --e) {
		for (int i = e; true; i = ((i - 1) & e)) {
			if (cnt[i] && cnt[e ^ i] && join(i, e ^ i)) {
				ans += 1LL * (cnt[i] + cnt[e ^ i] - 1) * e;
				cnt[i] = 1;
				cnt[e ^ i] = 1;
			}
			if (i == 0 || (i ^ e) > i) {
				break;
			}
		}
	}
	cout << ans << endl;
}