/*

Code for problem F_slow by cookiedoth
Generated 04 Jan 2020 at 06.42 P



10%

30%

50%

70%

100%

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

struct fenwick {
	vector<int> t;
	int n;

	fenwick() {}

	void init(int _n) {
		n = _n;
		t.assign(n, 0);
	}

	void update(int pos, int val) {
		while (pos < n) {
			t[pos] += val;
			pos = (pos | (pos + 1));
		}
	}

	int get(int r) {
		int res = 0;
		while (r >= 0) {
			res += t[r];
			r = (r & (r + 1)) - 1;
		}
		return res;
	}

	int get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

struct superfenwick {
	fenwick f;

	superfenwick() {}

	void init(int _n) {
		f.init(_n + 1);
	}

	void update(int l, int r) {
		// cerr << "update " << l << " " << r << endl;
		f.update(l, 1);
		f.update(r + 1, -1);
	}

	int get(int pos) {
		// cerr << "get " << pos << endl;
		return f.get(pos);
	}
};

const int mx = 3e5 + 228;
const int lg = 20;
int n, up[mx][lg], tin[mx], tout[mx], h[mx], timer;
vector<vector<int> > children, g1, g2;
superfenwick F;

void read_graph(vector<vector<int> > &g) {
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void hang(int v, int pv) {
	up[v][0] = pv;
	for (auto v1 : g1[v]) {
		if (v1 != pv) {
			children[v].push_back(v1);
			hang(v1, v);
		}
	}
}

void precalc_lca(int v) {
	// cerr << "precalc_lca " << v << endl;
	for (int i = 1; i < lg; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	tin[v] = timer++;
	for (auto v1 : children[v]) {
		h[v1] = h[v] + 1;
		precalc_lca(v1);
	}
	tout[v] = timer - 1;
}

int upper(int u, int v) {
	return (tin[u] <= tin[v] && tout[v] <= tout[u]);
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

int ascend(int u, int dh) {
	for (int i = lg - 1; i >= 0; --i) {
		if (dh >= (1 << i)) {
			u = up[u][i];
			dh -= (1 << i);
		}
	}
	return u;
}

void update(int u) {
	// cerr << "update " << u << endl;
	F.update(tin[u], tout[u]);
}

int get(int u, int v) {
	return F.get(tin[u]) - F.get(tin[v]);
}

int sum_on_path(int u, int v, int e, int len) {
	// cerr << "sum_on_path " << u << " " << v << " " << e << " " << len << endl;
	int LEN = h[u] + h[v] - 2 * h[e], first_len = h[u] - h[e], res = 0;
	if (len > first_len) {
		res = get(u, e) + get(ascend(v, LEN - len), e);
	} else {
		res = get(u, ascend(u, len));
	}
	// cerr << "res = " << res << endl;
	return res;
}

void handle(int u, int v, int low) {
	// cerr << "-----low = " << low << endl;
	cout << low + 1 << " " << up[low][0] + 1 << " " << u + 1 << " " << v + 1 << "\n";
	update(low);
}

void find_path(int u, int v) {
	// cerr << "-----find_path " << u << " " << v << endl;
	int e = lca(u, v);
	int len = h[u] + h[v] - 2 * h[e];
	// cerr << "e = " << e << endl;
	// cerr << "len = " << len << endl;
	int l = 0, r = len;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (sum_on_path(u, v, e, mid + 1) == mid + 1) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	assert(l < len);
	int first_len = h[u] - h[e];
	if (l < first_len) {
		handle(u, v, ascend(u, l));
	} else {
		handle(u, v, ascend(v, len - l - 1));
	}
}

void dfs(int v, int pv) {
	for (auto v1 : g2[v]) {
		if (v1 != pv) {
			dfs(v1, v);
			find_path(v1, v);
		}
	}
}

signed main() {
	fast_io();
	cin >> n;
	F.init(n);
	read_graph(g1);
	read_graph(g2);
	children.resize(n);
	hang(0, 0);
	precalc_lca(0);
	cout << n - 1 << endl;
	dfs(0, 0);
}