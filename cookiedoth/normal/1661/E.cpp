/*

Code for problem E by cookiedoth
Generated 09 Apr 2022 at 11.29 AM


 ] 
 
Il] 


o_O
-_-
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
#include <utility>
#include <tuple>
#include <chrono>
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

const int MAX_N = 5e5 + 228;
const int R = 3;
int n;
vector<string> f;

struct node {
	int cmp, l[3], r[3];

	node(): cmp(-1) {}

	node(int col) {
		int ptr = 0;
		for (int i = 0; i < 3; ++i) {
			if (f[i][col] == '1') {
				l[i] = r[i] = ptr;
			} else {
				l[i] = r[i] = -1;
				if (i && f[i - 1][col] == '1') {
					ptr++;
				}
			}
		}
		cmp = 0;
	}

	int all_cmp() {
		vector<int> v;
		v.reserve(6);
		for (int i = 0; i < 3; ++i) {
			if (l[i] != -1) {
				v.push_back(l[i]);
			}
			if (r[i] != -1) {
				v.push_back(r[i]);
			}
		}
		sort(all(v));
		v.erase(unique(all(v)), v.end());
		return cmp + (int)v.size();
	}
};

int used[MAX_N * 5], used_clr;

node combine(node a, node b) {
	if (a.cmp == -1) {
		return b;
	}
	if (b.cmp == -1) {
		return a;
	}
	// cerr << "combine\n";
	int ptr = max(*max_element(a.l, a.l + 3), *max_element(a.r, a.r + 3)) + 1;
	// cerr << "ptr = " << ptr << '\n';
	for (int i = 0; i < 3; ++i) {
		if (b.l[i] != -1) {
			b.l[i] += ptr;
		}
		if (b.r[i] != -1) {
			b.r[i] += ptr;
		}
	}
	for (int i = 0; i < 3; ++i) {
		if (a.r[i] != -1 && b.l[i] != -1) {
			int from = b.l[i];
			int to = a.r[i];
			for (int j = 0; j < 3; ++j) {
				if (a.l[j] == from) {
					a.l[j] = to;
				}
				if (a.r[j] == from) {
					a.r[j] = to;
				}
				if (b.l[j] == from) {
					b.l[j] = to;
				}
				if (b.r[j] == from) {
					b.r[j] = to;
				}
			}
		}
	}
	// cerr << "here\n";
	int tot_cmp = a.cmp + b.cmp;
	used_clr++;
	for (int i = 0; i < 3; ++i) {
		// cerr << a.l[i] << ' ' << b.r[i] << '\n';
		if (a.l[i] != -1) {
			used[a.l[i]] = used_clr;
		}
		if (b.r[i] != -1) {
			used[b.r[i]] = used_clr;
		}
	}
	// cerr << "tut\n";
	for (int i = 0; i < 3; ++i) {
		if (a.r[i] > -1 && used[a.r[i]] != used_clr) {
			tot_cmp++;
			used[a.r[i]] = used_clr;
		}
		if (b.l[i] > -1 && used[b.l[i]] != used_clr) {
			tot_cmp++;
			used[b.l[i]] = used_clr;
		}
	}
	for (int i = 0; i < 3; ++i) {
		a.r[i] = b.r[i];
	}
	a.cmp = tot_cmp;
	// cerr << "done\n";
	return a;
}

node T[MAX_N * 4];

void build(int v, int tl, int tr) {
	if (tl == tr) {
		T[v] = node(tl);
	} else {
		int tm = (tl + tr) >> 1;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		T[v] = combine(T[v * 2], T[v * 2 + 1]);
	}
}

node get(int l, int r, int v, int tl, int tr) {
	if (r < tl || tr < l) {
		return node();
	}
	if (l <= tl && tr <= r) {
		return T[v];
	}
	int tm = (tl + tr) >> 1;
	node L = get(l, r, v * 2, tl, tm);
	node R = get(l, r, v * 2 + 1, tm + 1, tr);
	return combine(L, R);
}

signed main() {
	fast_io();
	cin >> n;
	f.resize(R);
	for (int i = 0; i < R; ++i) {
		cin >> f[i];
	}
	build(1, 0, n - 1);
	// cerr << "here\n";
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		node res = get(l, r, 1, 0, n - 1);
		cout << res.all_cmp() << '\n';
	}
}