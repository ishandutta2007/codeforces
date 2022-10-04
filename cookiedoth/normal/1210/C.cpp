/*

Code for problem C by cookiedoth
Generated 22 Sep 2019 at 12.28 P










(@)(@)(@)(@)(@)

o_O
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

ll gcd(ll a, ll b) {
	return (b == 0 ? a : gcd(b, a % b));
}

const int mx = 1e5 + 228;
const ll MOD = 1e9 + 7;
int n, h[mx];
ll a[mx], ans;
vector<vector<int> > g;
vector<vector<pair<ll, int> > > gcds;

void dfs(int v, int pv) {
	if (v) {
		ll last_gcd = -1;
		for (auto pp : gcds[pv]) {
			ll new_p1 = gcd(pp.first, a[v]);
			if (new_p1 != last_gcd) {
				gcds[v].emplace_back(new_p1, pp.second);
				last_gcd = new_p1;
			}
		}
		if (last_gcd != a[v]) {
			gcds[v].emplace_back(a[v], h[v]);
		}
	}
	/*cerr << "gcds " << v << endl;
	for (auto pp : gcds[v]) {
		cerr << pp.first << " " << pp.second << endl;
	}*/
	for (int i = 0; i < gcds[v].size(); ++i) {
		ans += (ll)(h[v] - gcds[v][i].second + 1) * gcds[v][i].first;
		if (i < (int)gcds[v].size() - 1) {
			ans -= (ll)(h[v] - gcds[v][i + 1].second + 1) * gcds[v][i].first;
		}
		ans = (ans % MOD + MOD) % MOD;
	}
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			h[v1] = h[v] + 1;
			dfs(v1, v);
		}
	}
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	gcds.resize(n);
	gcds[0].emplace_back(a[0], 0);
	dfs(0, 0);
	cout << ans << endl;
}