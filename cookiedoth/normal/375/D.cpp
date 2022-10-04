/*

Code for problem D by cookiedoth
Generated 11 Feb 2020 at 12.35 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

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

mt19937 rng(58);

struct node {
	int x, y, cnt, sz;
	node *l, *r;
	node(int _x): x(_x), y(rng()), cnt(1), sz(1), l(null), r(null) {}
};

int get_sz(node *t) {
	return (t ? t->sz : 0);
}

void upd_sz(node *t) {
	t->sz = t->cnt + get_sz(t->l) + get_sz(t->r);
}

void split(node *t, int x, node *&l, node *&r) {
	if (!t) {
		l = null;
		r = null;
		return;
	}
	if (x < t->x) {
		split(t->l, x, l, t->l);
		r = t;
	} else {
		split(t->r, x, t->r, r);
		l = t;
	}
	upd_sz(t);
}

node* merge(node *l, node *r) {
	if (!l) return r;
	if (!r) return l;
	if (l->y < r->y) {
		l->r = merge(l->r, r);
		upd_sz(l);
		return l;
	} else {
		r->l = merge(l, r->l);
		upd_sz(r);
		return r;
	}
}

void insert(node *&t, int x) {
	node *l, *m, *r;
	split(t, x - 1, l, t);
	split(t, x, m, r);
	if (!m) {
		m = new node(x);
	} else {
		m->cnt++;
		m->sz++;
	}
	t = merge(merge(l, m), r);
}

void erase(node *&t, int x) {
	node *l, *m, *r;
	split(t, x - 1, l, t);
	split(t, x, m, r);
	assert(m);
	if (m) {
		if (m->cnt == 1) {
			m = null;
		} else {
			m->cnt--;
			m->sz--;
		}
	}
	t = merge(merge(l, m), r);
}

void print(node *t) {
	if (t) {
		print(t->l);
		cerr << t->x << " " << t->cnt << endl;
		print(t->r);
	}
}

typedef pair<map<int, int>*, node*> base;

const int mx = 1e5 + 228;
int n, m, c[mx], sz[mx], ans[mx];
vector<vector<int> > g;
vector<vector<pair<int, int> > > q;

base merge(base a, base b) {
	if (a.first->size() < b.first->size()) {
		swap(a, b);
	}
	for (auto pp : (*b.first)) {
		if (a.first->find(pp.first) != a.first->end()) {
			erase(a.second, (*a.first)[pp.first]);
		}
		(*a.first)[pp.first] += pp.second;
		insert(a.second, (*a.first)[pp.first]);
	}
	return a;
}

base dfs(int v, int pv) {
	base cur;
	cur.first = new map<int, int> ();
	(*cur.first)[c[v]] = 1;
	insert(cur.second, 1);
	for (auto v1 : g[v]) {
		if (v1 != pv) {
			cur = merge(cur, dfs(v1, v));
		}
	}
	// cerr << "map for vertex " << v << ":" << endl;
	// for (auto pp : (*cur.first)) {
	// 	cerr << pp.first << " " << pp.second << endl;
	// }
	// cerr << "treap:" << endl;
	// print(cur.second);
	for (auto pp : q[v]) {
		node *l, *r;
		split(cur.second, pp.first - 1, l, r);
		ans[pp.second] = get_sz(r);
		cur.second = merge(l, r);
	}
	return cur;
}

signed main() {
	fast_io();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
		c[i]--;
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
	q.resize(n);
	for (int i = 0; i < m; ++i) {
		int v, k;
		cin >> v >> k;
		v--;
		q[v].emplace_back(k, i);
	}
	dfs(0, 0);
	for (int i = 0; i < m; ++i) {
		cout << ans[i] << "\n";
	}
}