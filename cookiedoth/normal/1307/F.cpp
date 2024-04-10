/*

Code for problem F by cookiedoth
Generated 19 Feb 2020 at 02.40 P










(@)(@)(@)(@)(@)

z_z
>_<
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

struct dsu {
	int n;
	vector<int> p;

	dsu() {}

	void init(int _n) {
		n = _n;
		p.resize(n);
		iota(all(p), 0);
	}

	int get_root(int v) {
		return (v == p[v] ? v : p[v] = get_root(p[v]));
	}

	void join(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		p[u] = v;
	}
};

const int INF = 1e9 + 228;
const int mx = 4e5 + 228;
const int lg = 20;
int n, k, r, cmp[mx], d[mx], up[mx][lg], tin[mx], tout[mx], h[mx], timer;
dsu T;
vector<vector<int> > g;

void read() {
	cin >> n >> k >> r;
	g.resize(2 * n);
	int m = n - 1;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(n);
		g[n].push_back(u);
		g[v].push_back(n);
		g[n].push_back(v);
		n++;
	}
}

void build_cmp() {
	fill(cmp, cmp + n, -1);
	fill(d, d + n, INF);
	queue<int> q;
	for (int i = 0; i < r; ++i) {
		int v;
		cin >> v;
		v--;
		d[v] = 0;
		cmp[v] = i;
		q.push(v);
	}
	T.init(n);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (d[v] == k) {
			break;
		}
		for (auto v1 : g[v]) {
			if (cmp[v1] == -1) {
				cmp[v1] = cmp[v];
				d[v1] = d[v] + 1;
				q.push(v1);
			} else {
				T.join(cmp[v], cmp[v1]);
			}
		}
	}
}

void dfs(int v, int pv) {
	tin[v] = timer++;
	up[v][0] = pv;
	for (int i = 1; i < lg; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			h[v1] = h[v] + 1;
			dfs(v1, v);
		}
	}
	tout[v] = timer - 1;
}

int upper(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
	if (upper(u, v)) return u;
	if (upper(v, u)) return v;
	for (int i = lg - 1; i >= 0; --i) {
		if (!upper(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

int la(int u, int dh) {
	for (int i = lg - 1; i >= 0; --i) {
		if (dh >= (1 << i)) {
			u = up[u][i];
			dh -= (1 << i);
		}
	}
	return u;
}

int distance(int u, int v) {
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

int move_towards(int u, int v, int len, int e, int dist) {
	if (h[u] - h[e] >= len) {
		return la(u, len);
	} else {
		return la(v, dist - len);
	}
}

int solve(int u, int v) {
	int e = lca(u, v);
	int dist = distance(u, v);
	if (dist <= 2 * k) {
		return 1;
	} else {
		int _u = move_towards(u, v, k, e, dist);
		int _v = move_towards(v, u, k, e, dist);
		if (cmp[_u] == -1 || cmp[_v] == -1) {
			return 0;
		}
		return T.get_root(cmp[_u]) == T.get_root(cmp[_v]);
	}
}

void process() {
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		int res = solve(u, v);
		cout << (res ? "YES" : "NO") << "\n";
	}
}

signed main() {
	fast_io();
	read();
	build_cmp();
	dfs(0, 0);
	process();
}