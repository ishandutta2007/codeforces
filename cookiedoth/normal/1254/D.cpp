/*

Code for problem D by cookiedoth
Generated 19 Nov 2019 at 06.45 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

o_O
^_^
~_^

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

const ll MOD = 998244353;

struct fenwick {
	vector<ll> t;
	int n;

	fenwick() {}

	void init(int _n) {
		n = _n;
		t.resize(n);
	}

	void add(int pos, ll val) {
		while (pos < n) {
			t[pos] = (t[pos] + val) % MOD;
			pos = (pos | (pos + 1));
		}
	}

	ll get(int r) {
		int res = 0;
		while (r >= 0) {
			res = (res + t[r]) % MOD;
			r = (r & (r + 1)) - 1;
		}
		return res;
	}

	ll get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

struct super_fenwick {
	fenwick f;

	super_fenwick() {}

	void init(int n) {
		f.init(n + 1);
	}

	void add(int l, int r, ll val) {
		f.add(l, val);
		f.add(r + 1, -val);
	}

	ll get(int pos) {
		return f.get(pos);
	}
};

const int mx = 15e4 + 228;
int n, q, tin[mx], tout[mx], p[mx], timer, sz[mx], up[mx];
vector<vector<int> > g, children;
super_fenwick f;
fenwick hld;

void dfs(int v, int pv) {
	p[v] = pv;
	sz[v] = 1;
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			children[v].push_back(v1);
			dfs(v1, v);
			sz[v] += sz[v1];
		}
	}
	if (!children[v].empty()) {
		int pos = 0;
		for (int i = 1; i < children[v].size(); ++i) {
			if (sz[children[v][i]] > sz[children[v][pos]]) {
				pos = i;
			}
		}
		swap(children[v][0], children[v][pos]);
	}
}

void euler_dfs(int v) {
	tin[v] = timer++;
	for (auto v1 : children[v]) {
		if (v1 == children[v][0]) {
			up[v1] = up[v];
		} else {
			up[v1] = v1;
		}
		euler_dfs(v1);
	}
	tout[v] = timer - 1;
}

void read() {
	cin >> n >> q;
	g.resize(n);
	children.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

ll mod[mx], all_mod, to_fuck[mx];

void query(int v, ll d) {
	// cerr << "query " << v << " " << d << endl;
	all_mod = (all_mod + sz[v] * d) % MOD;
	// cerr << "all_mod = " << all_mod << endl;
	// mod[v] = (mod[v] + ((ll)n - sz[v]) * d) % MOD;
	f.add(tin[v], tout[v], (((ll)n - sz[v]) * d % MOD + MOD) % MOD);
	// cerr << "subtree " << v << " " << ((ll)n - sz[v]) * d << endl;
	to_fuck[v] = (to_fuck[v] + d) % MOD;
	if (!children[v].empty()) {
		hld.add(tin[children[v][0]], ((-sz[children[v][0]] * d) % MOD + MOD) % MOD);
	}
}

ll get(int v) {
	// cerr << "get " << v << endl;
	ll res = all_mod;
	res = (res + f.get(tin[v])) % MOD;
	// cerr << "res = " << res << endl;
	while (true) {
		// cerr << "up " << v << " = " << up[v] << endl;
		res = (res + hld.get(tin[up[v]], tin[v])) % MOD;
		if (up[v] == 0) {
			break;
		}
		v = up[v];
		res = ((res - to_fuck[p[v]] * sz[v]) % MOD + MOD) % MOD;
		v = p[v];
	}
	return res;
}

ll power(ll a, ll deg) {
	ll res = 1;
	while (deg) {
		if ((deg & 1LL) == 0) {
			a = (a * a) % MOD;
			deg >>= 1;
		} else {
			res = (res * a) % MOD;
			deg -= 1;
		}
	}
	return res;
}

ll inverse(ll a) {
	return power(a, MOD - 2);
}

void process_queries() {
	ll _n = inverse(n);
	for (int i = 0; i < q; ++i) {
		int type, v;
		cin >> type >> v;
		v--;
		if (type == 1) {
			ll d;
			cin >> d;
			query(v, d);
		} else {
			ll res = get(v);
			res = (res * _n) % MOD;
			cout << res << "\n";
		}
	}
}

signed main() {
	fast_io();
	read();
	dfs(0, 0);
	euler_dfs(0);
	f.init(n);
	hld.init(n);
	process_queries();
}