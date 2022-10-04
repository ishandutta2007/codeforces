/*

Code for problem F by cookiedoth
Generated 09 Mar 2019 at 06.38 P



10%

30%

50%

70%

100%

o_O
^_^
~_^

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
		t.resize(n);
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

	int operator [] (int pos) {
		return get(pos, pos);
	}
};

struct segment {
	int l, r, clr;
	segment(int _l, int _r, int _clr): l(_l), r(_r), clr(_clr) {}
};

bool operator < (segment a, segment b) {
	return a.l < b.l;
}

const int INF = 1e9;
const int mx = 2e5 + 228;
const int lg = 20;
int n, q, timer, ptr;
int sz[mx], tin[mx], tout[mx], h[mx], euler[mx], par[mx], p[2 * mx], _p[2 * mx], link[mx], up[mx][lg];
vector<int> g[mx], children[mx];
set<segment> s;
fenwick f, f0;

int pos[mx], deg[mx];

void build_order() {
	set<pair<int, int> > burn;
	for (int i = 0; i < n; ++i) {
		deg[i] = g[i].size();
		pos[i] = -1;
		if (deg[i] == 1) {
			burn.insert({p[i], i});
		}
	}
	for (int i = 0; i < n; ++i) {
		int v = burn.begin()->second;
		burn.erase(burn.begin());
		pos[v] = i;
		for (auto v1 : g[v]) {
			deg[v1]--;
			if (deg[v1] == 1) {
				burn.insert({p[v1], v1});
			}
		}
	}
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

int distance(int u, int v) {
	return h[u] + h[v] - 2 * h[lca(u, v)];
}

void update_way(int high, int low, int include, vector<pair<int, int> > &res) {
	while (true) {
		if (low == high && !include) {
			break;
		}
		int tlow = tin[low];
		if (upper(link[tlow], high)) {
			if (include) {
				res.push_back({tin[high], tlow});
			}
			else {
				res.push_back({tin[high] + 1, tlow});
			}
			break;
		}
		res.push_back({tin[link[tlow]], tlow});
		low = par[link[tlow]];
	}
}

vector<pair<int, int> > get_way(int u, int v) {
	vector<pair<int, int> > res;
	int e = lca(u, v);
	update_way(e, u, 1, res);
	update_way(e, v, 0, res);
	return res;
}

void seg_update_color(int l, int r, int clr_id) {
	while (true) {
		auto seg = *prev(s.upper_bound({r, INF, INF}));
		s.erase(seg);
		f.update(seg.clr, -(seg.r - seg.l + 1));
		if (seg.clr == 0) {
			int L = max(l, seg.l), R = min(r, seg.r);
			for (int i = L; i <= R; ++i) {
				f0.update(pos[euler[i]], -1);
			}
		}
		if (seg.r > r) {
			s.insert({r + 1, seg.r, seg.clr});
			f.update(seg.clr, seg.r - r);
		}
		if (seg.l < l) {
			s.insert({seg.l, l - 1, seg.clr});
			f.update(seg.clr, l - seg.l);
		}
		if (seg.l <= l) {
			break;
		}
	}
	s.insert({l, r, clr_id});
	f.update(clr_id, r - l + 1);
}

void update_color(int u, int v, int clr_id) {
	vector<pair<int, int> > segs = get_way(u, v);
	for (auto pp : segs) {
		seg_update_color(pp.first, pp.second, clr_id);
	}
}

void up_query(int v) {
	int u = _p[ptr - 1];
	update_color(u, v, ptr - 1);
	update_color(v, v, ptr);
	p[v] = ptr;
	_p[ptr] = v;
	ptr++;
}

int when_query(int v) {
	int clr = prev(s.upper_bound({tin[v], INF, INF}))->clr;
	int res = f.get(clr - 1);
	if (clr != 0) {
		res += distance(v, _p[clr]);
	}
	else {
		res += f0.get(pos[v] - 1);
	}
	return res;
}

int compare_query(int u, int v) {
	if (when_query(u) < when_query(v)) {
		return u;
	}
	else {
		return v;
	}
}

void build_hld() {
	f.init(n + q + 1);
	f0.init(n);
	int cur_link = 0;
	for (int i = 1; i < n; ++i) {
		if (children[par[euler[i]]][0] != euler[i]) {
			cur_link = euler[i];
		}
		link[i] = cur_link;
	}
	for (int i = 0; i < n; ++i) {
		f0.update(i, 1);
	}
	s.insert({0, n - 1, 0});
	f.update(0, n);
}

void hang(int v, int pv) {
	par[v] = pv;
	sz[v] = 1;
	vector<pair<int, int> > vp;
	int id = 0;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			children[v].push_back(v1);
			hang(v1, v);
			vp.push_back({sz[v1], id++});
			sz[v] += sz[v1];
		}
	}
	if (!vp.empty()) {
		int id = max_element(all(vp)) - vp.begin();
		swap(children[v][0], children[v][id]);
	}
}

void timer_dfs(int v) {
	up[v][0] = par[v];
	for (int i = 1; i < lg; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	tin[v] = timer++;
	euler[tin[v]] = v;
	for (auto v1 : children[v]) {
		h[v1] = h[v] + 1;
		timer_dfs(v1);
	}
	tout[v] = timer - 1;
}

void read_tree() {
	cin >> n >> q;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void fill_p() {
	iota(p, p + n, 0);
	iota(_p, _p + n, 0);
	ptr = n;
}

void process_queries() {
	for (int i = 0; i < q; ++i) {
		string type;
		cin >> type;
		int v, u;
		if (type == "up") {
			cin >> v;
			v--;
			up_query(v);
		}
		if (type == "when") {
			cin >> v;
			v--;
			cout << when_query(v) + 1 << '\n';
		}
		if (type == "compare") {
			cin >> u >> v;
			u--;
			v--;
			cout << compare_query(u, v) + 1 << '\n';
		}
	}
}

signed main() {
	fast_io();
	read_tree();
	hang(0, 0);
	timer_dfs(0);
	fill_p();
	build_hld();
	build_order();

	/*cerr << "euler" << endl;
	output(euler, euler + n);
	cerr << "link" << endl;
	output(link, link + n);*/

	process_queries();
}