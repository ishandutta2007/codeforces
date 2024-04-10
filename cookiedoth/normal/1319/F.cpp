#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <queue>
#include <deque>
#include <numeric>
#include <random>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(const T &x, ostream &out = cerr) {
	output(all(x), out);
}

template<class T> int chkmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmax(T &a, const T &b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int mx = 2e5 + 228;
const int lg = 20;
int n, up[mx][lg], tin[mx], tout[mx], h[mx], timer;
vector<vector<int> > g;

void dfs(int v, int pv) {
	up[v][0] = pv;
	for (int i = 1; i < lg; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	tin[v] = timer++;
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
	// cerr << "lca " << u << " " << v << endl;
	for (int i = lg - 1; i >= 0; --i) {
		if (!upper(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

void read() {
	cin >> n;
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0);
}

bool tin_cmp(int u, int v) {
	return tin[u] < tin[v];
}

int k, m, virus_type[mx];
vector<pair<int, int> > viruses;
vector<int> important;
vector<vector<pair<int, int> > > edges;

void add_edge(int u, int v, int len) {
	// cerr << "add_edge " << u << " " << v << " " << len << endl;
	edges[u].emplace_back(v, len);
	edges[v].emplace_back(u, len);
}

int id_ptr;

struct event {
	ll timestamp;
	int city, type, overflow, id;
};

bool operator < (event a, event b) {
	return make_pair(a.timestamp, a.id) < make_pair(b.timestamp, b.id);
}

set<event> S;

ll ceil_div(ll a, ll b) {
	return (a + b - 1) / b;
}

void infect(event ev) {
	// cerr << "event " << ev.timestamp << " " << ev.city << " " << ev.type << " " << ev.overflow << endl;
	if (virus_type[ev.city] != -1) {
		return;
	}
	virus_type[ev.city] = ev.type;
	for (auto pp : edges[ev.city]) {
		// cerr << "to " << pp.first << endl;
		ll len = pp.second - ev.overflow;
		// cerr << "len = " << len << endl;
		ll speed = viruses[ev.type].second;
		ll cnt = max(0LL, ceil_div(len, speed));
		// cerr << "cnt = " << cnt << endl;
		event to_add = {ev.timestamp + (ll)k * cnt, pp.first, ev.type, (int)(speed * cnt - len), id_ptr++};
		S.insert(to_add);
	}
}

void process() {
	while (!S.empty()) {
		auto ev = (*S.begin());
		S.erase(S.begin());
		infect(ev);
	}
}

void solve() {
	viruses.clear();
	important.clear();
	cin >> k >> m;
	viruses.resize(k);
	important.resize(m);
	vector<int> subv;
	for (int i = 0; i < k; ++i) {
		cin >> viruses[i].first >> viruses[i].second;
		viruses[i].first--;
		subv.push_back(viruses[i].first);
	}
	for (int i = 0; i < m; ++i) {
		cin >> important[i];
		important[i]--;
		subv.push_back(important[i]);
	}
	sort(all(subv), tin_cmp);
	subv.erase(unique(all(subv)), subv.end());
	vector<int> to_add;
	for (int i = 0; i < (int)subv.size() - 1; ++i) {
		to_add.push_back(lca(subv[i], subv[i + 1]));
	}
	for (auto v : to_add) {
		subv.push_back(v);
	}
	sort(all(subv), tin_cmp);
	subv.erase(unique(all(subv)), subv.end());
	vector<int> st;
	for (auto v : subv) {
		while (!st.empty() && !upper(st.back(), v)) {
			st.pop_back();
		}
		if (!st.empty()) {
			add_edge(st.back(), v, h[v] - h[st.back()]);
		}
		st.push_back(v);
	}
	for (int i = 0; i < k; ++i) {
		infect({i, viruses[i].first, i, viruses[i].second, id_ptr++});
	}
	process();
	for (int i = 0; i < m; ++i) {
		cout << virus_type[important[i]] + 1 << " ";
	}
	cout << "\n";
	for (auto v : subv) {
		edges[v].clear();
		virus_type[v] = -1;
	}
}

signed main() {
	fast_io();
	read();
	edges.resize(n);
	fill(virus_type, virus_type + n, -1);
	// cerr << "kke" << endl;
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		solve();
	}
}