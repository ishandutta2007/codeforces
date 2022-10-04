/*

Code for problem C by cookiedoth
Generated 02 Feb 2020 at 05.31 P


 ] 
 
Il] 


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

const int mx = 3e5 + 228;
int n, k, ans, edge[2][mx], a[mx], p[mx], up_mod[mx], cmp_sz[mx][2], forced_cmp[mx], rnk[mx];

int get_root(int v, int &mod) {
	mod ^= up_mod[v];
	return (v == p[v] ? v : get_root(p[v], mod));
}

int get_ans(int v) {
	return (forced_cmp[v] == -1 ? min(cmp_sz[v][0], cmp_sz[v][1]) : cmp_sz[v][forced_cmp[v]]);
}

void join(int u, int v, int type) {
	// cerr << "join " << u << " " << v << " " << type << endl;
	int mod_u = 0, mod_v = 0;
	u = get_root(u, mod_u);
	v = get_root(v, mod_v);
	if (u == v) {
		return;
	}
	if (rnk[u] > rnk[v]) {
		swap(u, v);
		swap(mod_u, mod_v);
	}
	ans -= get_ans(u);
	ans -= get_ans(v);
	up_mod[u] = (mod_u ^ mod_v ^ type);
	p[u] = v;
	if (forced_cmp[u] != -1) {
		forced_cmp[v] = (forced_cmp[u] ^ up_mod[u]);
	}
	for (int i = 0; i < 2; ++i) {
		cmp_sz[v][i] += cmp_sz[u][i ^ up_mod[u]];
	}
	ans += get_ans(v);
	if (rnk[u] == rnk[v]) {
		rnk[v]++;
	}
}

void force(int v, int type) {
	// cerr << "force " << v << " " << type << endl;
	int mod = type;
	v = get_root(v, mod);
	ans -= get_ans(v);
	forced_cmp[v] = mod;
	ans += get_ans(v);
}

void init() {
	// cerr << "init" << endl;
	iota(p, p + k, 0);
	for (int i = 0; i < k; ++i) {
		cmp_sz[i][0] = 1;
		cmp_sz[i][1] = 0;
	}
	fill(forced_cmp, forced_cmp + k, -1);
}

signed main() {
	fast_io();
	cin >> n >> k;
	fill(edge[0], edge[0] + n, -1);
	fill(edge[1], edge[1] + n, -1);
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for (int i = 0; i < k; ++i) {
		int len;
		cin >> len;
		for (int j = 0; j < len; ++j) {
			int pos;
			cin >> pos;
			pos--;
			for (int it = 0; it < 2; ++it) {
				if (edge[it][pos] == -1) {
					// cerr << "edge " << it << " " << pos << " = " << i << endl;
					edge[it][pos] = i;
					break;
				}
			}
		}
	}
	init();
	for (int i = 0; i < n; ++i) {
		if (edge[0][i] == -1) {
			cout << ans << "\n";
			continue;
		}
		if (edge[1][i] == -1) {
			force(edge[0][i], a[i]);
			cout << ans << "\n";
			continue;
		}
		join(edge[0][i], edge[1][i], a[i] ^ 1);
		cout << ans << "\n";
	}
}