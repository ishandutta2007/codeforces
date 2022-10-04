/*

Code for problem G by cookiedoth
Generated 22 Feb 2020 at 10.25 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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

struct edge {
	int v, cap, cost, flow;
	edge(int _v, int _cap, int _cost): v(_v), cap(_cap), cost(_cost), flow(0) {}
};

struct mincost {
	int n, s, t;
	vector<edge> e;
	vector<vector<int> > g;
	vector<int> d, p, in_queue;
	queue<int> q;

	void init(int _n, int _s, int _t) {
		n = _n;
		s = _s;
		t = _t;
		g.resize(n);
		d.resize(n);
		in_queue.resize(n);
		p.resize(n);
	}

	void add_edge(int u, int v, int cap, int cost) {
		g[u].push_back(e.size());
		e.emplace_back(v, cap, cost);
		g[v].emplace_back(e.size());
		e.emplace_back(u, 0, -cost);
	}

	int push_flow() {
		// cerr << "push_flow" << endl;
		fill(all(p), -1);
		fill(all(d), INF);
		fill(all(in_queue), 0);
		d[s] = 0;
		q.push(s);
		in_queue[s] = 1;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			in_queue[v] = 0;
			for (auto en : g[v]) {
				int v1 = e[en].v;
				if (e[en].flow < e[en].cap && chkmin(d[v1], d[v] + e[en].cost)) {
					p[v1] = en;
					// cerr << v << " -> " << v1 << endl;
					if (in_queue[v1] == 0) {
						q.push(v1);
						in_queue[v1] = 1;
					}
				}
			}
		}
		if (p[t] == -1) {
			return INF;
		}
		int v = t, res = 0;
		while (v != s) {
			int en = p[v];
			res += e[en].cost;
			e[en].flow += 1;
			e[en ^ 1].flow -= 1;
			v = e[en ^ 1].v;
		}
		return res;
	}

	vector<int> solve() {
		vector<int> res;
		while (true) {
			int cur_res = push_flow();
			if (cur_res == INF) {
				break;
			}
			res.push_back(cur_res);
		}
		return res;
	}
};

mincost solver;
int n, m;
vector<pair<ll, ll> > points;

signed main() {
	fast_io();
	cin >> n >> m;
	solver.init(n, 0, n - 1);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		solver.add_edge(a, b, 1, c);
	}
	vector<int> costs = solver.solve();
	ll C = 0;
	for (ll f = 0; f < (int)costs.size(); ++f) {
		points.emplace_back(f * costs[f] - C, costs[f]);
		C += costs[f];
	}
	ll F = costs.size();
	points.emplace_back(F * INF - C, INF);
	// cerr << "points" << endl;
	// for (auto pp : points) {
	// 	cerr << pp.first << " " << pp.second << endl;
	// }
	int q;
	cin >> q;
	cout << setprecision(10) << fixed;
	for (int i = 0; i < q; ++i) {
		ll x;
		cin >> x;
		auto it = prev(lower_bound(all(points), make_pair(x + 1, 0LL)));
		auto it1 = next(it);
		ld y = (ld)it->second + (ld)(it1->second - it->second) * (ld)((ld)x - it->first) / (ld)(it1->first - it->first);
		cout << y << "\n";
	}
}