/*

Code for problem D by cookiedoth
Generated 20 Jul 2020 at 02.24 PM


 ] 
 
Il] 


~_^
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

int n, h, m, k, P;
vector<pair<int, int> > fr;

void read() {
	cin >> n >> h >> m >> k;
	P = m / 2;
	for (int i = 0; i < n; ++i) {
		int th, tm;
		cin >> th >> tm;
		fr.emplace_back(tm % P, i);
	}
	sort(all(fr));
	// cerr << "fr" << endl;
	// for (auto pp : fr) {
	// 	cerr << pp.first << '\n';
	// }
	// cerr << "/fr" << endl;
}

int dist(int x, int y) {
	return (y - x + P) % P;
}

void solve() {
	int len = 0, best = n + 1, opt = -1;
	for (int i = 0; i < n; ++i) {
		len = max(len - 1, 0);
		if (fr[i].first == fr[(i + 1) % n].first) {
			continue;
		}
		// cerr << "start from " << i << " " << len << endl;
		while (len < n && fr[(i + len) % n].first - fr[i].first + ((i + len) % n < i ? P : 0) < k) {
			len++;
		}
		// cerr << i << " " << len << endl;
		if (chkmin(best, len - 1)) {
			opt = (fr[i].first + k) % P;
		}
	}
	if (best == n + 1) {
		cout << 0 << ' ' << fr[0].first << '\n';
		cout << '\n';
		exit(0);
	}
	cout << best << ' ' << opt << '\n';
	int mda = 0;
	for (int i = 0; i < n; ++i) {
		int d = dist(fr[i].first, opt);
		if (d >= 1 && d < k) {
			mda++;
			cout << fr[i].second + 1 << ' ';
		}
	}
	assert(mda == best);
	cout << '\n';
}

signed main() {
	fast_io();
	read();
	solve();
}