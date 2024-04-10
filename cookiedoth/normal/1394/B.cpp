/*

Code for problem B by cookiedoth
Generated 12 Aug 2020 at 05.47 PM


 ] 
 
Il] 


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

struct edge {
	int v, w;
};

bool operator < (const edge &a, const edge &b) {
	return a.w < b.w;
}

int n, m, k;
vector<vector<edge> > g;
vector<set<pair<int, int> > > S;

void read() {
	cin >> n >> m >> k;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		g[u].push_back({v, w});
	}
	for (int i = 0; i < n; ++i) {
		sort(all(g[i]));
	}
}

const int MAX_K = 15;
int bad[MAX_K][MAX_K][MAX_K][MAX_K];

void buildS() {
	S.resize(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < g[i].size(); ++j) {
			// cerr << "ij = " << i << " " << j << endl;
			if (S[g[i][j].v].find({g[i].size(), j}) != S[g[i][j].v].end()) {
				bad[g[i].size()][j][g[i].size()][j] = 1;
			}
			S[g[i][j].v].insert({g[i].size(), j});
		}
	}
}

void build_bad() {
	vector<pair<int, int> > vp;
	for (int i = 0; i < n; ++i) {
		vp = vector<pair<int, int> > (all(S[i]));
		for (int j1 = 0; j1 < vp.size(); ++j1) {
			for (int j2 = 0; j2 < vp.size(); ++j2) {
				if (j1 != j2) {
					// cerr << "bad " << vp[j1].first << " " << vp[j1].second << " " << vp[j2].first << " " << vp[j2].second << endl;
					bad[vp[j1].first][vp[j1].second][vp[j2].first][vp[j2].second] = 1;
				}
			}
		}
	}
}

int ans = 0;
vector<int> cur;

int increase() {
	for (int i = 0; i < k; ++i) {
		if (cur[i] < i) {
			cur[i]++;
			for (int j = 0; j < i; ++j) {
				cur[j] = 0;
			}
			return 1;
		}
	}
	return 0;
}

int check() {
	// cerr << "check" << endl;
	for (int i = 0; i < k; ++i) {
		for (int j = i; j < k; ++j) {
			// cerr << i << " " << cur[i] << " " << j << " " << cur[j] << endl;
			if (bad[i + 1][cur[i]][j + 1][cur[j]]) {
				return 0;
			}
		}
	}
	// cerr << "good" << endl;
	// output(all(cur));
	// for (int i = 0; i < n; ++i) {
	// 	cerr << g[i][cur[(int)g[i].size() - 1]].v << endl;
	// }
	return 1;
}

void process() {
	cur.resize(k);
	while (true) {
		ans += check();
		if (!increase()) {
			break;
		}
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	// cerr << "read" << endl;
	buildS();
	// cerr << "buildS" << endl;
	build_bad();
	process();
}