/*

Code for problem E by cookiedoth
Generated 18 Sep 2022 at 07.13 PM
The Moon is Waning Crescent (41% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

^_^
-_-
z_z

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
#include <array>
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

const int MOD = 998244353;

int mul(int a, int b) {
	return (1LL * a * b) % MOD;
}

int diff(int a, int b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
	return a;
}

void subt(int &a, const int &b) {
	a -= b;
	if (a < 0) {
		a += MOD;
	}
}

int sum(int a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
	return a;
}

void add(int &a, const int &b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int power(int a, int deg) {
	int res = 1;
	for (; deg; a = mul(a, a), deg >>= 1) {
		if (deg & 1) {
			res = mul(res, a);
		}
	}
	return res;
}

int inverse(int a) {
	return power(a, MOD - 2);
}

int divide(int a, int b) {
	return mul(a, inverse(b));
}


const int MAX_N = 2e5 + 228;
const int LG = 20;
int n, a[MAX_N], timer, up[MAX_N][LG], tin[MAX_N], tout[MAX_N], w[MAX_N], h[MAX_N], ans;
vector<int> ps[MAX_N], g[MAX_N];

int binom3(ll x) {
	return x * (x - 1) * (x - 2) / 6 % MOD;
}

int upper(int u, int v) {
	return tin[u] <= tin[v] && tout[v] <= tout[u];
}

int lca(int u, int v) {
	if (upper(u, v)) return u;
	if (upper(v, u)) return v;
	for (int i = LG - 1; i >= 0; --i) {
		if (!upper(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

void dfs(int v, int pv) {
	up[v][0] = pv;
	for (int i = 1; i < LG; ++i) {
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

void build_ps() {
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		for (int j = 2; j * j <= x; ++j) {
			if (x % j == 0) {
				ps[j].push_back(i);
				while (x % j == 0) {
					x /= j;
				}
			}
		}
		if (x > 1) {
			ps[x].push_back(i);
		}
	}
}

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(0, 0);
	build_ps();
}

void solve(int p) {
	if (ps[p].empty()) {
		return;
	}
	vector<int> nodes;
	for (auto v : ps[p]) {
		nodes.push_back(v);
	}
	// cerr << "solve " << p << '\n';
	// output(all(nodes));
	sort(all(nodes), [] (int a, int b) { return tin[a] < tin[b]; });
	int ns = nodes.size();
	for (int i = 0; i < ns - 1; ++i) {
		nodes.push_back(lca(nodes[i], nodes[i + 1]));
	}
	sort(all(nodes), [] (int a, int b) { return tin[a] < tin[b]; });
	nodes.erase(unique(all(nodes)), nodes.end());
	vector<pair<int, int>> edges;
	vector<int> st;
	for (auto v : nodes) {
		while (!st.empty() && !upper(st.back(), v)) {
			st.pop_back();
		}
		if (!st.empty()) {
			edges.emplace_back(st.back(), v);
		}
		st.push_back(v);
	}
	for (auto v : ps[p]) {
		w[v] = 1;
	}
	for (int i = (int)edges.size() - 1; i >= 0; --i) {
		w[edges[i].first] += w[edges[i].second];
	}
	int res = 0;
	for (auto [u, v] : edges) {
		add(res, mul(diff(binom3(ps[p].size()), sum(binom3(w[v]), binom3((int)ps[p].size() - w[v]))), h[v] - h[u]));
	}
	for (auto v : nodes) {
		w[v] = 0;
	}
	add(ans, res);
}

void solve() {
	for (int p = 2; p < MAX_N; ++p) {
		solve(p);
	}
}

signed main() {
	fast_io();
	read();
	// cerr << "here\n";
	solve();
	cout << ans << '\n';
}