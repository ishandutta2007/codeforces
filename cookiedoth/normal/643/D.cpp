/*

Code for problem D by cookiedoth
Generated 11 Dec 2020 at 08.12 PM


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

const int mx = 1e5 + 228;
int n, q;
ll t[mx], give[mx], rem[mx], setVal[mx];
int par[mx], sub[mx];
vector<multiset<ll>> sets;
multiset<ll> global_max, global_min;

void formula(int v, ll &give_v, ll &rem_v) {
	give_v = t[v] / (sub[v] + 2);
	rem_v = t[v] - give_v * (sub[v] + 1);
}

void insert_to_global(int v);

void read() {
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> t[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> par[i];
		par[i]--;
		sub[par[i]]++;
	}
	for (int i = 0; i < n; ++i) {
		formula(i, give[i], rem[i]);
		setVal[i] += rem[i];
		setVal[par[i]] += give[i];
	}
	sets.resize(n);
	for (int i = 0; i < n; ++i) {
		sets[par[i]].insert(setVal[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (!sets[i].empty()) {
			insert_to_global(i);
		}
	}
}

void remove_from_global(int v) {
	if (!sets[v].empty()) {
		global_min.erase(global_min.find((*sets[v].begin()) + give[v]));
		global_max.erase(global_max.find((*prev(sets[v].end())) + give[v]));
	}
}

void insert_to_global(int v) {
	if (!sets[v].empty()) {
		global_max.insert((*prev(sets[v].end())) + give[v]);
		global_min.insert((*sets[v].begin()) + give[v]);
	}
}

void modify(int v, ll delta) {
	// cerr << "modify " << v << " " << delta << '\n';
	remove_from_global(par[v]);
	sets[par[v]].erase(sets[par[v]].find(setVal[v]));
	setVal[v] += delta;
	sets[par[v]].insert(setVal[v]);
	insert_to_global(par[v]);
}

void rehang(int u, int v, int w) {
	if (v == w) {
		return;
	}
	remove_from_global(v);
	remove_from_global(w);
	sets[v].erase(sets[v].find(setVal[u]));
	sets[w].insert(setVal[u]);
	ll new_give, new_rem;
	sub[v]--;
	formula(v, new_give, new_rem);
	ll delta_give_v = new_give - give[v];
	ll delta_rem_v = new_rem - rem[v];
	give[v] = new_give;
	rem[v] = new_rem;
	sub[w]++;
	formula(w, new_give, new_rem);
	ll delta_give_w = new_give - give[w];
	ll delta_rem_w = new_rem - rem[w];
	give[w] = new_give;
	rem[w] = new_rem;
	insert_to_global(v);
	insert_to_global(w);
	par[u] = w;
	modify(v, delta_rem_v - give[u]);
	modify(par[v], delta_give_v);
	modify(w, delta_rem_w + give[u]);
	modify(par[w], delta_give_w);
}

ll get(int v) {
	return setVal[v] + give[par[v]];
}

void get(ll &min, ll &max) {
	min = *global_min.begin();
	max = *prev(global_max.end());
}

void process_queries() {
	for (int i = 0; i < q; ++i) {
		int type;
		cin >> type;
		if (type == 1) {
			int u, w;
			cin >> u >> w;
			u--;
			w--;
			rehang(u, par[u], w);
		} else if (type == 2) {
			int v;
			cin >> v;
			v--;
			ll ans = get(v);
			cout << ans << '\n';
		} else if (type == 3) {
			ll min, max;
			get(min, max);
			cout << min << ' ' << max << '\n';
		}
	}
}

signed main() {
	fast_io();
	read();
	process_queries();
}