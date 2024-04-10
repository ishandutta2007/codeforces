/*

Code for problem G by cookiedoth
Generated 31 Jul 2020 at 03.29 PM


  !
 
                                    
                          
                  




















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

const int mx = 3e5 + 228;
int n, m, k;
vector<int> spec;
ll c[mx], w[mx];
vector<vector<pair<int, ll> > > g;

void read() {
	cin >> n >> m >> k;
	spec.resize(k);
	for (int i = 0; i < k; ++i) {
		cin >> spec[i];
		spec[i]--;
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> w[i];
	}
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].emplace_back(v, w[i]);
		g[v].emplace_back(u, w[i]);
	}
}

int cmp_cnt, cmp[mx];
vector<vector<pair<int, ll> > > gt;

int timer, used[mx], tin[mx], up[mx];
vector<int> st;

void fetch_cmp(int v0) {
	while (true) {
		int v = st.back();
		st.pop_back();
		cmp[v] = cmp_cnt;
		if (v == v0) {
			break;
		}
	}
	cmp_cnt++;
}

void dfs(int v, int pv) {
	used[v] = 1;
	up[v] = tin[v] = timer++;
	st.push_back(v);
	for (auto pp : g[v]) {
		int v1 = pp.first;
		if (v1 == pv) {
			continue;
		}
		if (used[v1]) {
			chkmin(up[v], tin[v1]);
		} else {
			dfs(v1, v);
			chkmin(up[v], up[v1]);
			if (up[v1] > tin[v]) {
				fetch_cmp(v1);
			}
		}
	}
}

ll cmp_c[mx];

void build_cmp_graph() {
	gt.resize(cmp_cnt);
	// cerr << "build_cmp_graph" << endl;
	for (int i = 0; i < n; ++i) {
		for (auto pp : g[i]) {
			if (cmp[i] != cmp[pp.first]) {
				// cerr << "add_edge " << cmp[i] << " " << cmp[pp.first] << " " << pp.second << endl;
				gt[cmp[i]].emplace_back(cmp[pp.first], pp.second);
			}
		}
	}
}

void update_c() {
	for (int i = 0; i < n; ++i) {
		cmp_c[cmp[i]] += c[i];
	}
	fill(c, c + n, 0);
	copy(cmp_c, cmp_c + cmp_cnt, c);
}

int is_spec[mx];

void update_spec() {
	vector<int> new_spec;
	for (int i = 0; i < k; ++i) {
		new_spec.push_back(cmp[spec[i]]);
	}
	sort(all(new_spec));
	new_spec.erase(unique(all(new_spec)), new_spec.end());
	spec = new_spec;
	k = spec.size();
	for (auto v : spec) {
		is_spec[v] = 1;
	}
}

int root;

void build_cmp() {
	dfs(0, 0);
	fetch_cmp(0);
	build_cmp_graph();
	update_c();
	update_spec();
	root = spec[0];
}

int is_good[mx];

void dfs1(int v, int pv) {
	if (is_spec[v]) {
		is_good[v] = 1;
	}
	for (auto pp : gt[v]) {
		int v1 = pp.first;
		if (v1 != pv) {
			dfs1(v1, v);
			if (is_good[v1]) {
				is_good[v] = 1;
			}
		}
	}
}

vector<vector<pair<int, ll> > > children;
int good_par[mx], par[mx];
ll up_cost[mx];

void dfs2(int v, int pv) {
	if (is_good[v]) {
		good_par[v] = v;
	}
	for (auto pp : gt[v]) {
		int v1 = pp.first;
		if (v1 != pv) {
			up_cost[v1] = pp.second;
			good_par[v1] = good_par[v];
			par[v1] = v;
			if (is_good[v1]) {
				children[v].push_back(pp);
			}
			dfs2(v1, v);
		}
	}
}

void build_children() {
	children.resize(cmp_cnt);
	dfs2(root, root);
}

void add_good_par() {
	for (int i = 0; i < n; ++i) {
		if (!is_good[i]) {
			c[good_par[i]] += c[i];
		}
	}
}

ll sum_down_dp[mx], down_dp[mx], up_dp[mx], res[mx];

void calc_down_dp(int v) {
	if (v != root) {
		down_dp[v] = c[v] - up_cost[v];
	}
	for (auto pp : children[v]) {
		int v1 = pp.first;
		calc_down_dp(v1);
		if (v != root) {
			down_dp[v] += down_dp[v1];
		}
	}
	chkmax(down_dp[v], 0LL);
	if (v != root) {
		sum_down_dp[par[v]] += down_dp[v];
	}
}

void calc_up_dp(int v) {
	if (v != root) {
		up_dp[v] = c[par[v]] - up_cost[v];
		up_dp[v] += sum_down_dp[par[v]] - down_dp[v];
		if (par[v] != root) {
			up_dp[v] += up_dp[par[v]];
		}
		chkmax(up_dp[v], 0LL);
	}
	res[v] = c[v];
	if (v != root) {
		res[v] += up_dp[v];
	}
	for (auto pp : children[v]) {
		int v1 = pp.first;
		res[v] += down_dp[v1];
		calc_up_dp(v1);
	}
}

void print_ans() {
	for (int i = 0; i < n; ++i) {
		int v = good_par[cmp[i]];
		cout << res[v] << '\n';
	}
}

signed main() {
	fast_io();
	read();
	build_cmp();
	// cerr << "cmp" << endl;
	// output(cmp, cmp + n);
	// cerr << "is_spec" << endl;
	// output(is_spec, is_spec + cmp_cnt);
	dfs1(root, root);
	// cerr << "is_good" << endl;
	// output(is_good, is_good + cmp_cnt);
	build_children();
	add_good_par();
	// cerr << "good_par" << endl;
	// output(good_par, good_par + cmp_cnt);
	// cerr << "root = " << root << endl;
	// cerr << "c" << endl;
	// output(c, c + cmp_cnt);
	calc_down_dp(root);
	// cerr << "down_dp" << endl;
	// output(down_dp, down_dp + cmp_cnt);
	// cerr << "sum_down_dp" << endl;
	// output(sum_down_dp, sum_down_dp + cmp_cnt);
	calc_up_dp(root);
	// cerr << "up_dp" << endl;
	// output(up_dp, up_dp + cmp_cnt);
	print_ans();
}