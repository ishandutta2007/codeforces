/*

Code for problem F by cookiedoth
Generated 19 May 2020 at 07.47 PM



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
const ll BINF = 1e18 + 228;

struct edge {
	int u, v;
	ll cap, cost, flow;
	edge(int _u, int _v, ll _cap, ll _cost, ll _flow): u(_u), v(_v), cap(_cap), cost(_cost), flow(_flow) {}
};

struct min_cost_max_flow {
	int n, s, t;
	ll flow = 0, cost = 0;
	queue<int> q;
	vector<vector<int> > g;
	vector<edge> e;
	vector<int> used, p;
	vector<ll> w, d;

	min_cost_max_flow() {}

	void init(int _n, int _s, int _t) {
		n = _n;
		s = _s;
		t = _t;
		g.resize(n);
		used.resize(n);
		w.resize(n);
		d.resize(n);
		p.resize(n);
	}

	void add_edge(int u, int v, ll cap, ll cost) {
		// cerr << "add_edge " << u << " " << v << " " << cap << " " << cost << endl;
		g[u].push_back(e.size());
		e.emplace_back(u, v, cap, cost, 0);
		g[v].push_back(e.size());
		e.emplace_back(v, u, 0, -cost, 0);
	}

	void ford_bellman() {
		fill(all(w), BINF);
		w[s] = 0;
		q.push(s);
		used[s] = 1;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			used[v] = 0;
			for (auto en : g[v]) {
				if (e[en].flow < e[en].cap) {
					int v1 = e[en].v;
					if (chkmin(w[v1], w[v] + e[en].cost) && !used[v1]) {
						q.push(v1);
						used[v1] = 1;
					}
				}	
			}
		}
	}

	set<pair<ll, int> > S;

	void djkstra() {
		fill(all(d), BINF);
		fill(all(used), 0);
		fill(all(p), -1);
		d[s] = 0;
		S.insert({d[s], s});
		while (!S.empty()) {
			int v = S.begin()->second;
			S.erase(S.begin());
			if (used[v]) {
				continue;
			}
			used[v] = 1;
			for (auto en : g[v]) {
				if (e[en].flow < e[en].cap) {
					int v1 = e[en].v;
					ll cost = e[en].cost + w[v] - w[v1];
					if (chkmin(d[v1], d[v] + cost)) {
						p[v1] = en;
						S.insert({d[v1], v1});
					}
				}
			}
			used[v] = 1;
		}
		for (int i = 0; i < n; ++i) {
			d[i] += w[i];
		}
	}

	vector<int> path;

	void solve() {
		ford_bellman();
		int it = 0;
		while (true) {
			djkstra();
			if (p[t] == -1) {
				break;
			}
			path.clear();
			int v = t;
			while (v != s) {
				path.push_back(p[v]);
				v = e[p[v]].u;
			}
			ll min_flow = BINF;
			for (auto en : path) {
				chkmin(min_flow, e[en].cap - e[en].flow);
			}
			for (auto en : path) {
				e[en].flow += min_flow;
				e[en ^ 1].flow -= min_flow;
				cost += min_flow * e[en].cost;
			}
			flow += min_flow;
			swap(d, w);
		}
	}
};

const int mx = 80;
int n, k, a[mx], b[mx];

void solve() {
	min_cost_max_flow solver;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}
	solver.init(k + n + 2, k + n, k + n + 1);
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			solver.add_edge(i, k + j, 1, -b[j] * (i - (k - 1)));
		}
	}
	for (int i = 0; i < k; ++i) {
		solver.add_edge(k + n, i, 1, 0);
	}
	for (int i = 0; i < n; ++i) {
		solver.add_edge(k + i, k + n + 1, 1, -a[i]);
	}
	solver.solve();
	int ptr = 0;
	vector<int> used(n), useful(k), ans;
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < n; ++j) {
			if (solver.e[ptr].flow) {
				used[j] = 1;
				useful[i] = j;
			}
			ptr += 2;
		}
	}
	for (int i = 0; i < k - 1; ++i) {
		ans.push_back(useful[i] + 1);
	}
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			ans.push_back(i + 1);
			ans.push_back(-(i + 1));
		}
	}
	ans.push_back(useful.back() + 1);
	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x << ' ';
	}
	cout << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}