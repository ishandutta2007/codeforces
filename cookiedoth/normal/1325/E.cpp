/*

Code for problem E by cookiedoth
Generated 14 Mar 2020 at 06.55 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

^_^
~_^
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

const int INF = 1e9 + 228;
const int mx = 1e5 + 228;
const int C = 1e6 + 228;
const int SQ = 1e3 + 10;
int n, a[mx];
vector<vector<int> > g;
set<int> S;
vector<pair<int, int> > e;
set<pair<int, int> > se;

void add_edge(int u, int v) {
	assert(u < SQ || v < SQ);
	// cerr << "add_edge " << u << " " << v << endl;
	if (u > v) {
		swap(u, v);
	}
	g[u].push_back(v);
	g[v].push_back(u);
	e.emplace_back(u, v);
}

void factor(int x) {
	map<int, int> mp;
	for (int i = 2; i * i <= x; ++i) {
		while (x % i == 0) {
			mp[i]++;
			x /= i;
		}
	}
	if (x > 1) {
		mp[x]++;
	}
	vector<int> odd;
	for (auto pp : mp) {
		if (pp.second % 2 == 1) {
			odd.push_back(pp.first);
		}
	}
	if (odd.empty()) {
		cout << 1 << endl;
		exit(0);
	}
	if (odd.size() == 2) {
		add_edge(odd[0], odd[1]);
	} else {
		add_edge(odd[0], 0);
	}
}

int ans, d1[C], d2[C], p1[C], p2[C];

void relax(int s) {
	fill(d1, d1 + C, INF);
	fill(d2, d2 + C, INF);
	fill(p1, p1 + C, -1);
	fill(p2, p2 + C, -1);
	queue<int> q;
	d1[s] = 0;
	for (auto v : g[s]) {
		d1[v] = 1;
		p1[v] = v;
		q.push(v);
	}
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto v1 : g[v]) {
			if (v1 == s) {
				continue;
			}
			if (chkmin(d1[v1], d1[v] + 1)) {
				p1[v1] = p1[v];
				q.push(v1);
			}
		}
	}

	for (auto pp : e) {
		if (pp.first != s && pp.second != s && p1[pp.first] != p1[pp.second] && p1[pp.first] != -1 && p1[pp.second] != -1) {
			chkmin(ans, d1[pp.first] + d1[pp.second] + 1);
		}
	}
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	ans = n + 1;
	g.resize(C);
	for (int i = 0; i < n; ++i) {
		factor(a[i]);
	}
	sort(all(e));
	for (int i = 0; i < (int)e.size() - 1; ++i) {
		if (e[i] == e[i + 1]) {
			cout << 2 << endl;
			exit(0);
		}
	}
	for (int i = 0; i < SQ; ++i) {
		if (!g[i].empty()) {
			relax(i);
		}
	}
	if (ans == n + 1) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}