/*

Code for problem G by cookiedoth
Generated 25 Aug 2020 at 06.23 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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
#include <random>
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

const int mx = 3e5 + 228;
int n, m, L[mx], R[mx];
vector<pair<int, int> > edges;
vector<vector<int> > g;

void read() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> L[i] >> R[i];
	}
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
		edges.emplace_back(u, v);
	}
}

vector<vector<vector<int> > > events;
int used[mx], val[mx], id[mx], cmp_cnt;
vector<int> last_cmp, cmp_sz, bad_masks;

void dfs(int v) {
	used[v] = 1;
	id[v] = last_cmp.size();
	last_cmp.push_back(v);
	for (auto v1 : g[v]) {
		if (used[v1] == 0) {
			dfs(v1);
		} else {
			bad_masks.emplace_back((1 << id[v]) ^ (1 << id[v1]));
		}
	}
}

void process_cmp() {
	int s = last_cmp.size();
	for (int sub = 0; sub < (1 << s); ++sub) {
		int curL = 0, curR = n;
		for (int i = 0; i < s; ++i) {
			if ((sub >> i) & 1) {
				int v = last_cmp[i];
				chkmax(curL, L[v]);
				chkmin(curR, R[v]);
			}
		}
		int ok = 1;
		for (auto mask : bad_masks) {
			if ((sub & mask) == mask) {
				ok = 0;
				break;
			}
		}
		if (!ok) {
			continue;
		}
		int k = __builtin_popcount(sub);
		if (curL <= curR) {
			events[curL].push_back({cmp_cnt, k, 1});
			events[curR + 1].push_back({cmp_cnt, k, -1});
		}
	}
}

void build_ev() {
	events.resize(n + 2);
	for (int i = 0; i < n; ++i) {
		if (used[i] == 0) {
			if (g[i].empty()) {
				val[L[i]]++;
				val[R[i] + 1]--;
				used[i] = 1;
				continue;
			}
			// cerr << "opa" << endl;
			last_cmp.clear();
			bad_masks.clear();
			dfs(i);
			cmp_sz.push_back(last_cmp.size());
			process_cmp();
			cmp_cnt++;
			// cerr << "/opa" << endl;
		}
	}
}

vector<vector<int> > poly;

void mul(vector<int> &a, const vector<int> &b) {
	vector<int> res((int)a.size() + (int)b.size() - 1);
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b.size(); ++j) {
			add(res[i + j], mul(a[i], b[j]));
		}
	}
	a = res;
}

int fact[mx], _fact[mx];

void precalc_fact() {
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fact[i] = mul(fact[i - 1], i);
	}
	for (int i = 0; i <= n; ++i) {
		_fact[i] = inverse(fact[i]);
	}
}

int C(int n, int k) {
	return (k > n ? 0 : mul(fact[n], mul(_fact[k], _fact[n - k])));
}

void scanline() {
	poly.resize(cmp_cnt);
	for (int it = 0; it < cmp_cnt; ++it) {
		poly[it].resize(cmp_sz[it] + 1);
	}
	int bal = 0;
	vector<int> cur_poly;
	int ans = 0;
	for (int i = 0; i <= n; ++i) {
		bal += val[i];
		cur_poly = {1};
		for (auto v : events[i]) {
			poly[v[0]][v[1]] += v[2];
		}
		for (int j = 0; j < poly.size(); ++j) {
			mul(cur_poly, poly[j]);
		}
		// cerr << "i, bal " << i << " " << bal << endl;
		// cerr << "cur_poly:" << endl;
		// output(all(cur_poly));
		for (int j = 0; j < cur_poly.size(); ++j) {
			if (j <= i) {
				// cerr << "C " << bal << " " << i - j << endl;
				add(ans, mul(cur_poly[j], C(bal, i - j)));
			}
		}
		// cerr << "ans = " << ans << endl;
	}
	subt(ans, 1);
	cout << ans << '\n';
}

void solve() {
	precalc_fact();
	build_ev();
	scanline();
}

signed main() {
	fast_io();
	read();
	solve();
}