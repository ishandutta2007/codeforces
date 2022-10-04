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
const int INF = 1e9 + 228;
int n, m, path_len, d[mx];
vector<vector<int> > g, rev_g;
vector<int> path;

void bfs(int v0) {
	queue<int> q;
	fill(d, d + n, INF);
	d[v0] = 0;
	q.push(v0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto v1 : rev_g[v]) {
			if (d[v1] == INF) {
				d[v1] = d[v] + 1;
				q.push(v1);
			}
		}
	}
}

signed main() {
	fast_io();
	cin >> n >> m;
	g.resize(n);
	rev_g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		rev_g[v].push_back(u);
	}
	cin >> path_len;
	path.resize(path_len);
	for (int i = 0; i < path_len; ++i) {
		cin >> path[i];
		path[i]--;
	}
	bfs(path.back());
	int min_ch = 0, max_ch = 0;
	for (int i = 0; i < path_len - 1; ++i) {
		assert(d[path[i + 1]] >= d[path[i]] - 1);
		if (d[path[i + 1]] != d[path[i]] - 1) {
			min_ch++;
		}
		int ok = 0;
		for (auto v : g[path[i]]) {
			if (d[v] == d[path[i]] - 1) {
				ok = 1;
			}
			if (v != path[i + 1] && d[v] == d[path[i]] - 1) {
				max_ch++;
				break;
			}
		}
		assert(ok);
	}
	cout << min_ch << " " << max_ch << endl;
}