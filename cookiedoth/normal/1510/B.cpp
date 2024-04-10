/*

Code for problem B by cookiedoth
Generated 08 Apr 2021 at 09.43 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

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

struct edge {
	int v, cap, cost, flow;
};

struct MinCostMaxFlow {
	vector<edge> e;
	vector<vector<int>> g;
	int n, s, t;
	vector<int> dist, par;
	vector<bool> in_queue;

	MinCostMaxFlow(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
		g.resize(n);
		dist.resize(n);
		par.resize(n);
		in_queue.resize(n);
	}

	void addEdge(int u, int v, int cap, int cost) {
		// cerr << "addEdge " << u << ' ' << v << ' ' << cap << ' ' << cost << '\n';
		g[u].push_back(e.size());
		e.push_back({v, cap, cost, 0});
		g[v].push_back(e.size());
		e.push_back({u, 0, -cost, 0});
	}

	int cost = 0, flow = 0;

	bool fb() {
		// cerr << "fb\n";
		fill(all(dist), INF);
		queue<int> q;
		dist[s] = 0;
		q.push(s);
		in_queue[s] = true;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			in_queue[v] = false;
			for (auto en : g[v]) {
				if (e[en].flow < e[en].cap) {
					int v1 = e[en].v;
					if (chkmin(dist[v1], dist[v] + e[en].cost)) {
						par[v1] = en;
						if (in_queue[v1] == false) {
							q.push(v1);
							in_queue[v1] = true;
						}
					}
				}
			}
		}
		if (dist[t] == INF) {
			return false;
		}
		int v = t;
		while (true) {
			cost += e[par[v]].cost;
			e[par[v]].flow++;
			e[par[v] ^ 1].flow--;
			v = e[par[v] ^ 1].v;
			if (v == s) {
				break;
			}
		}
		flow++;
		return true;
	}

	void solve() {
		while (fb()) {}
	}
	
	vector<int> find_cycle() {
		// cerr << "find_cycle" << '\n';
		int v = 0;
		vector<int> order;
		while (true) {
			order.push_back(v);
			for (auto en : g[v]) {
				if (e[en].flow <= 0) {
					continue;
				}
				int v1 = e[en].v;
				if (v1 == s || v1 == t) {
					continue;
				}
				e[en].flow--;
				// e[en ^ 1].flow++; // ?
				v = v1;
				break;
			}
			if (v == 0) {
				break;
			}
		}
		// output(all(order));
		return order;
	}

	void printAnswer() {
		// cerr << "printAnswer \n";
		assert(flow == g[s].size());
		vector<int> ans;
		while (true) {
			vector<int> cycle = find_cycle();
			if (cycle.size() == 1) {
				break;
			}
			for (int i = 0; i < (int)cycle.size() - 1; ++i) {
				if (cycle[i] % 2 == 1 && cycle[i + 1] % 2 == 0) {
					int mask1 = cycle[i] / 2;
					int mask2 = cycle[i + 1] / 2;
					int xr = (mask1 ^ mask2);
					ans.push_back(31 - __builtin_clz(xr));
				}
			}
			ans.push_back(-1);
		}
		ans.pop_back();
		cout << ans.size() << '\n';
		for (auto x : ans) {
			if (x == -1) {
				cout << 'R';
			} else {
				cout << x;
			}
			cout << ' ';
		}
		cout << '\n';
	}
};

int n, d;
vector<int> masks;

signed main() {
	fast_io();
	cin >> d >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int mask = 0;
		for (int j = 0; j < d; ++j) {
			if (s[j] == '1') {
				mask ^= (1 << j);
			}
		}
		masks.push_back(mask);
	}
	int V = (1 << d);
	MinCostMaxFlow solver(2 * V + 2, 2 * V, 2 * V + 1);
	for (int i = 0; i < V; ++i) {
		solver.addEdge(2 * i, 2 * i + 1, INF, 0);
	}
	for (int i = 0; i < V; ++i) {
		for (int j = 0; j < d; ++j) {
			if (((i >> j) & 1) == 0) {
				solver.addEdge(2 * i + 1, 2 * (i ^ (1 << j)), INF, 1);
			}
		}
	}
	for (int i = 0; i < V; ++i) {
		solver.addEdge(2 * i + 1, 0, INF, 1);
	}
	for (auto mask : masks) {
		solver.addEdge(2 * V, 2 * mask + 1, 1, 0);
		solver.addEdge(2 * mask, 2 * V + 1, 1, 0);
	}
	solver.solve();
	for (auto mask : masks) {
		solver.e[mask * 2].flow++;
		// solver.e[mask * 2 + 1].flow--;
	}
	solver.printAnswer();
}