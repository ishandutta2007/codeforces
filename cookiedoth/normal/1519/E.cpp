/*
 
Code for problem E by cookiedoth
Generated 29 Apr 2021 at 06.24 PM
 
 
  !
 
                                    
                          
                  



















 
^_^
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
#include <chrono>
#define ll __int128
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
 
istream& operator >> (istream &is, __int128 &x) {
	long long a;
	is >> a;
	x = (__int128)a;
	return is;
}
 
ostream& operator << (ostream &os, const __int128 &x) {
	os << (long long)x;
	return os;
}
 
 
const int mx = 2e5 + 228;
pair<ll, ll> from[mx], to[mx];
vector<pair<ll, ll>> vert;
int n;
 
bool ratioCmp(const pair<ll, ll>& P, const pair<ll, ll>& Q) {
	return (__int128)P.first * Q.second < (__int128)P.second * Q.first;
}
 
bool Eq(pair<ll, ll> P, pair<ll, ll> Q) {
	return (__int128)P.first * Q.second == (__int128)P.second * Q.first;
}
 
int V;
vector<pair<int, int>> ans;
 
struct edge {
	int u, v, id;
	bool used;
};
 
vector<vector<pair<int, int>>> g;
int used[2 * mx], tin[2 * mx], timer;
 
void add_edge(int u, int v, int id) {
	// cerr << "add_edge " << u << ' ' << v << ' ' << id << '\n';
	g[u].emplace_back(v, id);
	g[v].emplace_back(u, id);
}

int dfs(int v, int pv) {
	int cache = -1;
	used[v] = 1;
	tin[v] = timer++;
	for (auto [v1, id] : g[v]) {
		if (used[v1] == 0) {
			int id1 = dfs(v1, v);
			if (id1 != -1) {
				if (cache == -1) {
					cache = id1;
				} else {
					ans.emplace_back(cache, id1);
					cache = -1;
				}
			}
		} else {
			if (v1 != pv && tin[v1] < tin[v]) {
				if (cache == -1) {
					cache = id;
				} else {
					ans.emplace_back(cache, id);
					cache = -1;
				}
			}
		}
	}
	for (auto [v1, id] : g[v]) {
		if (v1 == pv) {
			if (cache == -1) {
				cache = id;
			} else {
				ans.emplace_back(cache, id);
				cache = -1;
			}
		}
	}
	return cache;
}

void solve() {
	for (int i = 0; i < V; ++i) {
		if (!used[i]) {
			dfs(i, i);
		}
	}
	cout << ans.size() << '\n';
	for (auto [u, v] : ans) {
		cout << u + 1 << ' ' << v + 1 << '\n';
	}
}
 
void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		from[i] = {b * c, d * (a + b)};
		to[i] = {(c + d) * b, a * d};
		vert.push_back(from[i]);
		vert.push_back(to[i]);
	}
	sort(all(vert), ratioCmp);
	vert.erase(unique(vert.begin(), vert.end(), Eq), vert.end());
	V = vert.size();
	g.resize(V);
	// cerr << "V = " << V << '\n';
	for (int i = 0; i < n; ++i) {
		int x1 = lower_bound(all(vert), from[i], ratioCmp) - vert.begin();
		int x2 = lower_bound(all(vert), to[i], ratioCmp) - vert.begin();
		assert(Eq(vert[x1], from[i]));
		assert(Eq(vert[x2], to[i]));
		// cerr << "x1, x2 = " << x1 << ' ' << x2 << '\n';
		add_edge(x1, x2, i);
	}
	// cout << ans.size() << '\n';
	// for (auto [u, v] : ans) {
	// 	cout << u + 1 << ' ' << v + 1 << '\n';
	// }
}
 
signed main() {
	fast_io();
	read();
	solve();
}