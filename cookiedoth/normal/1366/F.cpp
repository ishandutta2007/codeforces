/*

Code for problem F by cookiedoth
Generated 11 Jun 2020 at 09.55 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

\_()_/
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
	int u, v, w;
};

const int INF = 2e9 + 228;
int n, m, q;
vector<vector<pair<int, int> > > g;
vector<edge> e;

void read() {
	cin >> n >> m >> q;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
		e.push_back({u, v, w});
		g[u].emplace_back(v, w);
		g[v].emplace_back(u, w);
	}
}

const int mx = 2010;
int dp[mx][mx], max_path[mx];

const ll BINF = 1e18;
ll coeff[mx];

void calc_dp() {
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = -INF;
		}
	}
	dp[0][0] = 0;
	for (int it = 0; it <= n; ++it) {
		for (int v = 0; v < n; ++v) {
			chkmax(max_path[it], dp[it][v]);
			if (it < n) {
				for (auto pp : g[v]) {
					chkmax(dp[it + 1][pp.first], dp[it][v] + pp.second);
				}
			}
		}
	}
}

void calc_coeff() {
	for (int i = 0; i < m; ++i) {
		coeff[i] = -BINF;
		for (int len = 0; len <= n; ++len) {
			chkmax(coeff[i], (ll)(max(dp[len][e[i].u], dp[len][e[i].v]) - len * e[i].w));
		}
	}
}

struct line {
	ld k, b, x;
};

// when b is better than a
ld better(line a, line b) {
	if (a.k == b.k) {
		return (a.b >= b.b ? BINF : -BINF);
	} else {
		return -(a.b - b.b) / (a.k - b.k);
	}
}

const ll MOD = 1e9 + 7;
const ld EPS = 1e-9;

struct cht {
	vector<line> st;
	ll base;

	cht() {}

	void insert(ll k, ll b) {
		// cerr << "insert " << k << " " << b << endl;
		line l = {(ld)k, (ld)b, 0};
		while (!st.empty() && (l.x = better(st.back(), l)) < st.back().x) {
			st.pop_back();
		}
		if (st.empty()) {
			l.x = base;
		}
		st.push_back(l);
	}

	void solve(vector<pair<ll, ll> > lines, ll _base) {
		base = _base;
		sort(all(lines));
		for (auto pp : lines) {
			insert(pp.first, pp.second);
		}
		// cerr << "st" << endl;
		// for (auto l : st) {
		// 	cerr << l.k << " " << l.b << " " << l.x << endl;
		// }
	}

	ll sum(ll R) {
		ll res = 0;
		int S = st.size();
		vector<ll> sp(S);
		sp[0] = base;
		for (int i = 1; i < st.size(); ++i) {
			sp[i] = ceil(st[i].x);
		}
		for (int i = 0; i < st.size(); ++i) {
			ll l = sp[i];
			ll r = R;
			if (i < (int)st.size() - 1) {
				chkmin(r, sp[i + 1] - 1);
			}
			if (l > r) {
				continue;
			}
			ll a = (ll)st[i].k * l + (ll)st[i].b;
			ll d = (ll)st[i].k;
			ll len = (r - l + 1);
			res += (a % MOD * len % MOD + len * (len - 1) / 2 % MOD * d % MOD) % MOD;
			res %= MOD;
		}
		return res;
	}
};

cht T;

void get_ans() {
	ll ans = 0;
	if (q > n) {
		vector<pair<ll, ll> > vp;
		for (int i = 0; i < m; ++i) {
			if (coeff[i] > -BINF) {
				vp.emplace_back(e[i].w, coeff[i]);
			}
		}
		T.solve(vp, n + 1);
		ans = T.sum(q);
	}
	for (int i = 0; i <= min(q, n); ++i) {
		ans += max_path[i];
	}
	ans %= MOD;
	cout << ans << '\n';
}

signed main() {
	fast_io();
	cerr << setprecision(4) << fixed;
	read();
	calc_dp();
	calc_coeff();
	get_ans();
}