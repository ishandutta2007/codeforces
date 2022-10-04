/*

Code for problem F by cookiedoth
Generated 13 Feb 2020 at 06.18 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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

const int INF = 1e9;
const int mx = 1010;
const int K = 45;
int n, m, k, a[mx][mx], d[K][mx][mx];
vector<pair<int, int> > have_clr[K];
deque<pair<int, int> > q;

void add_edge(int id, pair<int, int> u, pair<int, int> v, int cost) {
	if (chkmin(d[id][v.first][v.second], d[id][u.first][u.second] + cost)) {
		if (cost == 0) {
			q.push_front(v);
		} else {
			q.push_back(v);
		}
	}
}

vector<pair<int, int> > dir = {
	{0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

void bfs(pair<int, int> s, int id) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			d[id][i][j] = INF;
		}
	}
	for (int i = 0; i < k; ++i) {
		d[id][n][i] = INF;
	}
	d[id][s.first][s.second] = 0;
	q.push_back(s);
	while (!q.empty()) {
		auto v = q.front();
		q.pop_front();
		if (v.first == n) {
			for (auto pp : have_clr[v.second]) {
				add_edge(id, v, pp, 0);
			}
		} else {
			for (auto pp : dir) {
				int x = v.first + pp.first, y = v.second + pp.second;
				if (x >= 0 && x < n && y >= 0 && y < m) {
					add_edge(id, v, {x, y}, 1);
				}
			}
			add_edge(id, v, {n, a[v.first][v.second]}, 1);
		}
	}
}

void read() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			a[i][j]--;
			have_clr[a[i][j]].emplace_back(i, j);
		}
	}
}

void build() {
	for (int i = 0; i < k; ++i) {
		bfs({n, i}, i);
	}
}

void process() {
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		x2--;
		y2--;
		int res = abs(x1 - x2) + abs(y1 - y2);
		for (int j = 0; j < k; ++j) {
			chkmin(res, d[j][x1][y1] + d[j][x2][y2] + 1);
		}
		cout << res << "\n";
	}
}

signed main() {
	fast_io();
	read();
	build();
	process();
}