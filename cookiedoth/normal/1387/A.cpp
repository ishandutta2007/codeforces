/*

Code for problem  by cookiedoth
Generated 23 Jul 2020 at 06.32 PM


  !
 
                                    
                          
                  




















=_=
\_()_/
^_^

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
	int v, sum;
};

int n, m;
vector<edge> e;
vector<vector<int> > g;

void read() {
	cin >> n >> m;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v, sum;
		cin >> u >> v >> sum;
		u--;
		v--;
		sum *= 2;
		g[u].push_back(e.size());
		e.push_back({v, sum});
		g[v].push_back(e.size());
		e.push_back({u, sum});
	}
}

const int mx = 1e5 + 228;
int func[mx][2], used[mx], tin[mx], timer, have_req_x, req_x, bad, opt[mx];
ll ans;
vector<int> last_cmp;

void dfs(int v, int pv) {
	// cerr << "func " << v << " " << func[v][0] << " " << func[v][1] << endl;
	tin[v] = timer++;
	used[v] = 1;
	last_cmp.push_back(v);
	for (auto en : g[v]) {
		int v1 = e[en].v;
		int cost = e[en].sum;
		// cerr << "cost = " << cost << endl;
		if (used[v1] == 0) {
			func[v1][1] = -func[v][1];
			func[v1][0] = cost - func[v][0];
			// cerr << v << " -> " << v1 << endl;
			dfs(v1, v);
			if (bad) {
				return;
			}
		} else {
			// cerr << "got " << v << " " << v1 << endl;
			int sum_x = func[v][1] + func[v1][1];
			// cerr << "sum_x = " << sum_x << endl;
			if (sum_x == 0) {
				if (func[v][0] + func[v1][0] != cost) {
					bad = 1;
					return;
				}
			} else {
				// cerr << "!cost = " << cost << endl;
				int sum_y = cost - func[v][0] - func[v1][0];
				int new_x = sum_y / sum_x;
				// cerr << "new_x = " << new_x << endl;
				if (have_req_x == 0) {
					have_req_x = 1;
					req_x = new_x;
				} else {
					if (req_x != new_x) {
						bad = 1;
						return;
					}
				}
			}
		}
	}
}

const ll INF = 1e18;

void no() {
	cout << "NO\n";
	exit(0);
}

void solve() {
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			last_cmp.clear();
			have_req_x = 0;
			bad = 0;
			func[i][1] = 1;
			dfs(i, i);
			if (bad) {
				no();
			}
			int opt_x;
			if (have_req_x) {
				opt_x = req_x;
			} else {
				vector<int> coords;
				for (auto v : last_cmp) {
					// cerr << "func " << func[v][1] << " " << func[v][0] << endl;
					if (func[v][1] == 1) {
						coords.push_back(-func[v][0]);
					} else {
						coords.push_back(func[v][0]);
					}
				}
				sort(all(coords));
				// output(all(coords));
				opt_x = coords[(int)coords.size() / 2];
			}
			for (auto v : last_cmp) {
				opt[v] = func[v][1] * opt_x + func[v][0];
			}
		}
	}
}

void print_ans() {
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << (ld)opt[i] / 2.0 << ' ';
	}
	cout << '\n';
}

signed main() {
	fast_io();
	read();	
	solve();
	print_ans();
}