/*

Code for problem C by cookiedoth
Generated 23 Jul 2020 at 02.27 PM










(@)(@)(@)(@)(@)

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
#define ll long long
#define ull unsigned long long
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

int G0, G, n, m;
vector<vector<int> > singleMut;
vector<vector<pair<int, int> > > doubleMut;

int newGene() {
	singleMut.push_back(vector<int> ());
	doubleMut.push_back(vector<pair<int, int> > ());
	return G++;
}

vector<vector<int> > C;

void read() {
	cin >> G0 >> n >> m;
	G = G0;
	singleMut.resize(G);
	doubleMut.resize(G);
	for (int i = 0; i < n; ++i) {
		int a, k;
		cin >> a >> k;
		if (k == 1) {
			int b;
			cin >> b;
			singleMut[a].push_back(b);
		} else {
			for (int j = 0; j < k - 2; ++j) {
				int a1 = newGene();
				int b;
				cin >> b;
				doubleMut[a].emplace_back(b, a1);
				a = a1;
			}
			int b1, b2;
			cin >> b1 >> b2;
			doubleMut[a].emplace_back(b1, b2);
		}
	}
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		vector<int> cur(k);
		for (int j = 0; j < k; ++j) {
			cin >> cur[j];
		}
		C.push_back(cur);
	}
}

const int K = 2;
const int mx = 55;
const int maxG = 205;
int V, go[mx][K], link[mx], term[mx];

int new_vertex() {
	for (int it = 0; it < K; ++it) {
		go[V][it] = -1;
	}
	return (V++);
}

void init() {
	new_vertex();
}

void add_string(vector<int> s) {
	// cerr << "add_string" << endl;
	// output(all(s));
	int v = 0;
	for (auto c : s) {
		if (go[v][c] == -1) {
			go[v][c] = new_vertex();
		}
		v = go[v][c];
	}
	term[v] = 1;
}

void bfs() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		if (term[link[v]]) {
			term[v] = 1;
		}
		for (int c = 0; c < K; ++c) {
			if (go[v][c] == -1) {
				go[v][c] = (v == 0 ? 0 : go[link[v]][c]);
			} else {
				q.push(go[v][c]);
				link[go[v][c]] = (v == 0 ? 0 : go[link[v]][c]);
			}
		}
	}

	// std::cerr << "automaton" << std::endl;
	// std::cerr << "ptr = " << V << std::endl;
	// for (int i = 0; i < V; ++i) {
	// 	std::cerr << "vertex " << i << ", term = " << term[i] << ", go =";
	// 	for (int j = 0; j < K; ++j) {
	// 		cerr << " " << go[i][j];
	// 	}
	// 	cerr << endl;
	// }
}

void build() {
	init();
	for (auto s : C) {
		add_string(s);
	}
	bfs();
}

vector<vector<int> > rev_single;
vector<vector<pair<int, int> > > rev_double_l, rev_double_r;

void prepare_aux() {
	rev_single.resize(G);
	rev_double_l.resize(G);
	rev_double_r.resize(G);
	for (int i = 0; i < G; ++i) {
		for (auto v : singleMut[i]) {
			rev_single[v].push_back(i);
		}
		for (auto pp : doubleMut[i]) {
			rev_double_l[pp.first].emplace_back(pp.second, i);
			rev_double_r[pp.second].emplace_back(pp.first, i);
		}
	}
}

struct Achievement {
	ull t;
	int geneId, from, to;
};

bool operator < (const Achievement &a, const Achievement &b) {
	return a.t < b.t;
}

const ull INF = (ull)1 << 63;
multiset<Achievement> S;
ull dist[maxG][mx][mx];
int used[maxG][mx][mx];

void djkstra() {
	for (int i = 0; i < G; ++i) {
		for (int from = 0; from < V; ++from) {
			for (int to = 0; to < V; ++to) {
				dist[i][from][to] = INF;
			}
		}
	}
	for (int i = 0; i < V; ++i) {
		for (int it = 0; it < K; ++it) {
			if (!term[i] && !term[go[i][it]]) {
				S.insert({1, it, i, go[i][it]});
				dist[it][i][go[i][it]] = 1;
			}
		}
	}
	while (!S.empty()) {
		Achievement cur = (*S.begin());
		S.erase(S.begin());
		int gene = cur.geneId;
		int from = cur.from;
		int to = cur.to;
		ull t = cur.t;
		if (used[gene][from][to]) {
			continue;
		}
		for (auto v1 : rev_single[gene]) {
			if (chkmin(dist[v1][from][to], t)) {
				S.insert({dist[v1][from][to], v1, from, to});
			}
		}
		for (auto pp : rev_double_l[gene]) {
			int v1 = pp.first, v2 = pp.second;
			for (int final = 0; final < V; ++final) {
				if (!term[final] && chkmin(dist[v2][from][final], t + dist[v1][to][final])) {
					S.insert({dist[v2][from][final], v2, from, final});
				}
			}
		}
		for (auto pp : rev_double_r[gene]) {
			int v1 = pp.first, v2 = pp.second;
			for (int start = 0; start < V; ++start) {
				if (!term[start] && chkmin(dist[v2][start][to], dist[v1][start][from] + t)) {
					S.insert({dist[v2][start][to], v2, start, to});
				}
			}
		}
	}
}

void print_ans() {
	for (int i = 2; i < G0; ++i) {
		ull opt = INF;
		for (int j = 0; j < V; ++j) {
			if (!term[j]) {
				chkmin(opt, dist[i][0][j]);
			}
		}
		if (opt == INF) {
			cout << "YES\n";
		} else {
			cout << "NO " << opt << '\n';
		}
	}
}

signed main() {
	fast_io();
	read();
	build();
	prepare_aux();
	djkstra();
	print_ans();
}