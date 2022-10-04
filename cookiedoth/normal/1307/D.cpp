/*

Code for problem D by cookiedoth
Generated 17 Feb 2020 at 06.47 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

^_^
~_^
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

struct vertex {
	int s, t, id;
};

bool operator < (vertex a, vertex b) {
	return make_pair(a.s, a.t) < make_pair(b.s, b.t);
}

const int mx = 2e5 + 228;
const int INF = 1e9 + 228;
int n, m, k, a[mx], is_good[mx], good_edge;
vector<vector<int> > g;

void bfs(int s, int *d) {
	queue<int> q;
	fill(d, d + n, INF);
	q.push(s);
	d[s] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto v1 : g[v]) {
			if (d[v1] == INF) {
				d[v1] = d[v] + 1;
				q.push(v1);
			}
		}
	}
}

vector<vertex> v1, v2;

int check(int x) {
	int ptr = k - 1;
	int max1 = -INF, id1 = -1;
	int max2 = -INF, id2 = -1;
	for (int i = 0; i < k; ++i) {
		while (ptr >= 0 && v1[i].s + v2[ptr].s >= x) {
			if (v2[ptr].t > max1) {
				max2 = max1;
				id2 = id1;
				max1 = v2[ptr].t;
				id1 = v2[ptr].id;
			} else {
				if (v2[ptr].t > max2) {
					max2 = v2[ptr].t;
					id2 = v2[ptr].id;
				}
			}
			ptr--;
		}
		int cur_max = v1[i].t + (id1 == v1[i].id ? max2 : max1);
		if (cur_max >= x) {
			return 1;
		}
	}
	return 0;
}

int s[mx], t[mx];

signed main() {
	fast_io();
	cin >> n >> m >> k;
	for (int i = 0; i < k; ++i) {
		cin >> a[i];
		a[i]--;
		is_good[a[i]] = 1;
	}
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		if (is_good[u] && is_good[v]) {
			good_edge = 1;
		}
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(0, s);
	bfs(n - 1, t);
	int dist0 = s[n - 1];
	if (good_edge) {
		cout << dist0 << endl;
		exit(0);
	}
	for (int i = 0; i < k; ++i) {
		v1.push_back({s[a[i]], t[a[i]], i});
		v2.push_back({t[a[i]], s[a[i]], i});
	}
	sort(all(v1));
	sort(all(v2));
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid + 1)) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	int ans = min(dist0, l + 1);
	cout << ans << endl;
}