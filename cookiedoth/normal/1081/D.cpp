/*

Code for problem D by savkinsd2089
Generated 16 Dec 2018 at 05.14 pm
The Moon is Waxing Gibbous (61% of Full)










(@)(@)(@)(@)(@)

\_()_/
z_z
~_^

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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

#ifndef TESTING
	#define endl '\n'
#endif

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

struct dsu {
	vector<int> p, rnk, color;
	int n, cmp;

	dsu(int _n) {
		n = _n;
		p.resize(n);
		rnk.resize(n);
		color.resize(n);
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
		cmp = 0;
	}

	dsu() {}

	void change_color(int v, int new_color) {
		color[get_root(v)] = new_color;
		if (new_color == 1) {
			cmp++;
		}
	}

	int get_root(int v) {
		if (p[v] == v) return v;
		else return v = get_root(p[v]);
	}

	int get_color(int v) {
		return color[get_root(v)];
	}

	void join(int u, int v) {
		u = get_root(u);
		v = get_root(v);
		if (u == v) {
			return;
		}
		int new_color = max(color[u], color[v]);
		if (color[u] == 1 && color[v] == 1) {
			cmp--;
		}
		if (rnk[u] > rnk[v]) {
			p[v] = u;
			color[u] = new_color;
		}
		else {
			p[u] = v;
			color[v] = new_color;
			if (rnk[u] == rnk[v])
				rnk[v]++;
		}
	}
};

struct edge {
	int u, v, cost;
};

bool operator < (edge a, edge b) {
	return a.cost < b.cost;
}

int n, k, m, ans = 0;
vector<edge> e;

signed main() {
	cin >> n >> m >> k;

	dsu t(n);

	for (int i = 0; i < k; ++i) {
		int val;
		cin >> val;
		val--;
		t.change_color(val, 1);
	}

	for (int i = 0; i < m; ++i) {
		int u, v, cost;
		cin >> u >> v >> cost;
		u--;
		v--;
		e.push_back({u, v, cost});
	}

	sort(all(e));

	for (int i = 0; i < m; ++i) {
		t.join(e[i].u, e[i].v);
		if (t.cmp == 1) {
			ans = e[i].cost;
			break;
		}
	}
	for (int i = 0; i < k; ++i) {
		cout << ans << " ";
	}
	cout << endl;
}