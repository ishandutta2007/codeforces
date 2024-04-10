// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

vector<int> edges;
vector<vector<pii>> graph;

int add_node() {
	graph.push_back({});
	return szof(graph) - 1;
}

void add_edge(int a, int b, int c) {
	graph[a].push_back({b, szof(edges)});
	edges.push_back(c);
	graph[b].push_back({a, szof(edges)});
	edges.push_back(0);
}

vector<int> dist, qu, vcnt;

int build_layers(int s, int t) {
	fill(dist.begin(), dist.end(), INF);
	dist[s] = 0;
	int l = 0, r = 0;
	qu[r++] = s;
	while (l < r) {
		int v = qu[l++];
		for (auto to : graph[v]) {
			if (edges[to.ss] && dist[to.ff] > dist[v] + 1) {
				dist[to.ff] = dist[v] + 1;
				qu[r++] = to.ff;
			}
		}
	}

	return dist[t] < INF;
}

int push_flow(int v, int t) {
	if (v == t) {
		return 1;
	}
	while (vcnt[v] < szof(graph[v])) {
		auto& to = graph[v][vcnt[v]];
		if (edges[to.ss] && dist[to.ff] == dist[v] + 1 && push_flow(to.ff, t)) {
			edges[to.ss]--;
			edges[to.ss ^ 1]++;
			return 1;
		}
		++vcnt[v];
	}
	return 0;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<pii, int>> inp_edges;
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		--a; --b;
		inp_edges.push_back({{a, b}, w});
	}

	int l = 0, r = INF;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		graph.clear();
		edges.clear();
		int s = add_node();
		int t = add_node();
		vector<pii> lr;
		for (int i = 0; i < n; ++i) {
			lr.push_back({add_node(), add_node()});
			add_edge(s, lr[i].ff, 1);
			add_edge(lr[i].ss, t, 1);
		}

		for (auto e : inp_edges) {
			if (e.ss <= mid) {
				add_edge(lr[e.ff.ff].ff, lr[e.ff.ss].ss, 1);
			}
		}

		dist = qu = vcnt = vector<int>(szof(graph));

		int sz = 0;
		while (build_layers(s, t)) {
			fill(vcnt.begin(), vcnt.end(), 0);
			while (true) {
				int f = push_flow(s, t);
				if (!f) {
					break;
				}
				++sz;
			}
		}

		if (sz == n) {
			r = mid;
		} else {
			l = mid;
		}
	}

	if (r == INF) {
		cout << "-1\n";
	} else {
		cout << r << "\n";
	}
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}