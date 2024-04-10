/*

Code for problem E by cookiedoth
Generated 07 May 2020 at 05.43 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

=_=
>_<
o_O

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

const int mx = 1e5 + 228;
int n, m;
ll up_len[mx], total_len[mx], last_child[mx];
vector<vector<int> > children;
vector<vector<ll> > trains_by_dest;

void calc_total_len(int v) {
	for (auto v1 : children[v]) {
		total_len[v1] = total_len[v] + up_len[v1];
		calc_total_len(v1);
	}
}

void read() {
	cin >> n >> m;
	children.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		u--;
		v--;
		last_child[u] = v;
		up_len[v] = d;
		children[u].push_back(v);
	}
	calc_total_len(0);
	trains_by_dest.resize(n);
	for (int i = 0; i < m; ++i) {
		int s, t;
		cin >> s >> t;
		s--;
		trains_by_dest[s].push_back((ll)t + total_len[s]);
	}
}

struct ModSet : set<ll> {
	ll mod = 0;
};

const ll INF = 1e18;

void print(ModSet *p) {
	for (auto x : *p) {
		cerr << x + p->mod << " ";
	}
	cerr << endl;
}

ModSet* merge(ModSet *a, ModSet *b, set<ll> &coords) {
	if (a->size() > b->size()) {
		swap(a, b);
	}
	// a -> b
	ll last_lb = -1;
	for (auto x : (*a)) {
		ll y = x + a->mod - b->mod;
		auto it = b->lower_bound(y);
		ll new_lb = (it == b->end() ? INF : (*it));
		if (new_lb != last_lb) {
			if (it != b->begin()) {
				coords.insert(x + a->mod);
			}
			if (new_lb != INF) {
				coords.insert(new_lb + b->mod);
			}
			last_lb = new_lb;
		}
		b->insert(y);
	}
	return b;
}

vector<vector<ll> > events;

void addSegment(ll l, ll r) {
	// cerr << "addSegment " << l << " " << r << endl;
	events.push_back({l, 1, r});
	events.push_back({r, -1, l});
}

ModSet* dfs(int v) {
	set<ll> coords;
	ModSet *cur = new ModSet();
	ll minimal = INF;
	int minimal_color = -1;
	for (auto v1 : children[v]) {
		ModSet *ch = dfs(v1);
		if (!ch->empty() && chkmin(minimal, *(ch->begin()) + ch->mod)) {
			minimal_color = v1;
		}
		cur = merge(cur, ch, coords);
	}
	// cerr << "vertex " << v << endl;
	if (minimal_color != last_child[v] && minimal != INF) {
		addSegment(0, minimal);
	}
	// print(cur);
	for (auto x : coords) {
		auto it = cur->lower_bound(x - cur->mod);
		if (it != cur->begin()) {
			addSegment((*prev(it)) + cur->mod, x);
		}
	}
	for (auto t : trains_by_dest[v]) {
		cur->insert(t - cur->mod);
	}
	cur->mod -= up_len[v];
	return cur;
}

void scanline() {
	sort(all(events));
	multiset<ll> rbounds;
	ll survive = INF;
	for (int i = 0; i < events.size(); ++i) {
		if (events[i][1] == 1) {
			rbounds.insert(events[i][2]);
		} else {
			if (rbounds.find(events[i][0]) != rbounds.end()) {
				survive = events[i][0];
				break;
			}
		}
		if (i < (int)events.size() - 1) {
			for (ll j = 0; j < events[i + 1][0] - events[i][0]; ++j) {
				if (rbounds.empty()) {
					break;
				}
				rbounds.erase(rbounds.begin());
			}
		}
	}
	int cnt = 0;
	for (auto ev : events) {
		if (ev[1] == -1 && ev[0] < survive) {
			cnt++;
		}
	}
	if (survive == INF) {
		survive = -1;
	}
	cout << survive << " " << cnt << endl;
}

signed main() {
	fast_io();
	read();
	dfs(0);
	scanline();
}