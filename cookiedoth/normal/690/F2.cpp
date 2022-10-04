/*

Code for problem F2 by cookiedoth
Generated 21 Mar 2021 at 09.33 PM










(@)(@)(@)(@)(@)

-_-
~_^
=_=

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

struct Hasher {
	map<vector<int>, int> dt;
	int ptr = 0;

	int getHash(const vector<int>& cur) {
		auto it = dt.find(cur);
		if (it == dt.end()) {
			return dt[cur] = ptr++;
		} else {
			return it->second;
		}
	}
};

vector<vector<vector<int>>> g;
vector<int> used, sz;
multiset<int> forests;
int n;

Hasher trees;

int hashRootedTree(int id, int v, int pv) {
	vector<int> children;
	for (auto v1 : g[id][v]) {
		if (v1 != pv) {
			children.push_back(hashRootedTree(id, v1, v));
		}
	}
	sort(all(children));
	return trees.getHash(children);
}

Hasher center;

void szDfs(int id, int v, int pv) {
	sz[v] = 1;
	for (auto v1 : g[id][v]) {
		if (v1 != pv) {
			szDfs(id, v1, v);
			sz[v] += sz[v1];
		}
	}
}

int centroid(int id, int v, int pv, int all_sz) {
	for (auto v1 : g[id][v]) {
		if (v1 == pv) {
			continue;
		}
		if (sz[v1] * 2 == all_sz) {
			vector<int> pp = {hashRootedTree(id, v, v1), hashRootedTree(id, v1, v)};
			if (pp[1] < pp[0]) {
				swap(pp[1], pp[0]);
			}
			return center.getHash(pp);
		}
		if (sz[v1] * 2 > all_sz) {
			return centroid(id, v1, v, all_sz);
		}
	}
	return center.getHash({hashRootedTree(id, v, v)});
}

int hashTree(int id, int v) {
	szDfs(id, v, v);
	int res = centroid(id, v, v, sz[v]);
	return res;
}

Hasher seq;

void printTree(int id) {
	for (int i = 0; i < n; ++i) {
		vector<int> out;
		for (auto v : g[id][i]) {
			// if (v > i) {
				out.push_back(v);
			// }
		}
		if (!out.empty()) {
			cerr << i << ":";
			for (auto v : out) {
				cerr << ' ' << v;
			}
			cerr << '\n';
		}
	}
}

int hashForest(int id) {
	// cerr << "Hash forest:" << '\n';
	// printTree(id);
	vector<int> treeHashes;
	fill(all(used), 0);
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			treeHashes.push_back(hashTree(id, i));
		}
	}
	sort(all(treeHashes));
	int h = seq.getHash(vector<int>());
	for (auto h1 : treeHashes) {
		h = seq.getHash({h, h1});
	}
	// cerr << "result = " << h << '\n';
	return h;
}

int checkGraph(int id, int pivot) {
	// cerr << "checkGraph\n";
	// printTree(id);
	multiset<int> cur = forests;
	for (int i = 0; i < n; ++i) {
		if (i != pivot) {
			for (int v = 0; v < n; ++v) {
				g[n][v].clear();
				if (v == i) {
					continue;
				}
				for (auto v1 : g[id][v]) {
					if (v1 != i) {
						g[n][v].push_back(v1);
					}
				}
			}
			int H = hashForest(n);
			// cerr << "hash = " << H << '\n';
			auto it = cur.find(H);
			if (it == cur.end()) {
				return 0;
			}
			cur.erase(it);
		}
	}
	return 1;
}

void readGraph(int id) {
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[id][u].push_back(v);
		g[id][v].push_back(u);
	}
}

int dfs(int id, int v, int pv) {
	used[v] = 1;
	for (auto v1 : g[id][v]) {
		if (used[v1] == 1 && v1 != pv) {
			return 1;
		}
		if (v1 != pv && dfs(id, v1, v)) {
			return 1;
		}
	}
	return 0;
}

int verifyGraph(int id) {
	fill(all(used), 0);
	int isolatedCnt = 0, v0 = -1, cmpCnt = 0;
	for (int i = 0; i < n; ++i) {
		if (g[id][i].empty()) {
			isolatedCnt++;
			v0 = i;
			continue;
		}
		if (used[i] == 0) {
			if (dfs(id, i, i)) {
				return -2;
			}
			cmpCnt++;
		}
	}
	if (cmpCnt == 1 && isolatedCnt == 1) {
		return v0;
	} else {
		return -1;
	}
}

void solve() {
	cin >> n >> n;
	used.resize(n);
	sz.resize(n);
	g.assign(n + 1, vector<vector<int>> (n));
	int good_graph = -1, bad = 0, pivot = -1;
	for (int it = 0; it < n; ++it) {
		readGraph(it);
		int outcome = verifyGraph(it);
		if (outcome == -2) {
			bad = 1;
		}
		if (outcome >= 0) {
			pivot = outcome;
			good_graph = it;
		}
	}
	if (bad) {
		cout << "NO\n";
		return;
	}
	// cerr << "good_graph = " << good_graph << '\n';
	for (int i = 0; i < n; ++i) {
		if (i != good_graph) {
			forests.insert(hashForest(i));
		}
	}
	// cerr << "forests\n";
	// for (auto val : forests) {
	// 	cerr << val << ' ';
	// }
	// cerr << '\n';
	int yes = 0;
	for (int i = 0; i < n; ++i) {
		if (i != pivot) {
			g[good_graph][pivot].push_back(i);
			g[good_graph][i].push_back(pivot);
			if (checkGraph(good_graph, pivot)) {
				cout << "YES\n";
				yes = 1;
				for (int j = 0; j < n; ++j) {
					for (auto j1 : g[good_graph][j]) {
						if (j1 > j) {
							cout << j + 1 << ' ' << j1 + 1 << '\n';
						}
					}
				}
				break;
			}
			g[good_graph][pivot].pop_back();
			g[good_graph][i].pop_back();
		}
	}
	if (!yes) {
		cout << "NO\n";
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}