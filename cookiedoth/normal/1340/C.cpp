/*

Code for problem C by cookiedoth
Generated 23 Apr 2020 at 06.15 PM










(@)(@)(@)(@)(@)

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

const int mx = 1e4 + 10;
const int G = 1e3 + 10;
int n, m, d[mx], g, r;

void read() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> d[i];
	}
	sort(d, d + m);
	cin >> g >> r;
}

const int INF = 1e9 + 228;
int dist[mx][G];
deque<pair<int, int> > q;

void bfs() {
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j <= g; ++j) {
			dist[i][j] = INF;
		}
	}
	dist[0][g] = 0;
	q.push_back({0, g});
	while (!q.empty()) {
		auto pp = q.front();
		q.pop_front();
		int pos = pp.first, time = pp.second;
		if (time == 0 && chkmin(dist[pos][g], dist[pos][time] + 1)) {
			q.push_back({pos, g});
		}
		if (pos > 0) {
			int delta = d[pos] - d[pos - 1];
			if (time >= delta && chkmin(dist[pos - 1][time - delta], dist[pos][time])) {
				q.push_front({pos - 1, time - delta});
			}
		}
		if (pos < m - 1) {
			int delta = d[pos + 1] - d[pos];
			if (time >= delta && chkmin(dist[pos + 1][time - delta], dist[pos][time])) {
				q.push_front({pos + 1, time - delta});
			}
		}
	}
}

const ll BINF = 8e18;

void print_ans() {
	ll ans = BINF;
	for (int i = 0; i <= g; ++i) {
		if (dist[m - 1][i] != INF) {
			chkmin(ans, (ll)(r + g) * dist[m - 1][i] + (ll)(g - i));
		}
	}
	if (ans == BINF) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}

signed main() {
	fast_io();
	read();
	bfs();
	print_ans();
}