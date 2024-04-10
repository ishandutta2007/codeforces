/*

Code for problem C by cookiedoth
Generated 21 Jul 2020 at 06.04 PM


 ] 
 
Il] 


-_-
z_z
=_=

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
int n, x, y, a[mx], not_present;
vector<int> b;

void no() {
	cout << "NO\n";
}

void yes() {
	cout << "YES\n";
	for (int i = 0; i < n; ++i) {
		cout << a[i] + 1 << ' ';
	}
	cout << '\n';
}

vector<vector<int> > clr_pos;
set<pair<int, int> > S;

void calc_np() {
	not_present = -1;
	for (int i = 0; i <= n; ++i) {
		if (clr_pos[i].empty()) {
			not_present = i;
			break;
		}
	}
}

void assign_x() {
	fill(a, a + n, not_present);
	S.clear();
	for (int i = 0; i <= n; ++i) {
		S.insert({clr_pos[i].size(), i});
	}
	for (int it = 0; it < x; ++it) {
		auto pp = (*prev(S.end()));
		S.erase(pp);
		// cerr << "pp " << pp.first << " " << pp.second << endl;
		int clr_id = pp.second;
		a[clr_pos[clr_id].back()] = clr_id;
		clr_pos[clr_id].pop_back();
		S.insert({clr_pos[clr_id].size(), clr_id});
	}
	// cerr << "a" << endl;
	// output(a, a + n);
}

int fetch(int clr_id) {
	int res = clr_pos[clr_id].back();
	clr_pos[clr_id].pop_back();
	return res;
}

int assign_y() {
	vector<int> color_order, q_order, Q;
	while (!S.empty()) {
		auto pp = (*prev(S.end()));
		S.erase(pp);
		if (pp.first == 0) {
			break;
		}
		color_order.push_back(pp.second);
		Q.push_back(pp.first);
		for (int it = 0; it < pp.first; ++it) {
			q_order.push_back(pp.second);
		}
	}
	// cerr << "color_order" << endl;
	// output(all(color_order));
	// cerr << "Q" << endl;
	// output(all(Q));
	// cerr << "q_order" << endl;
	// output(all(q_order));

	int delta = y - x;
	if (delta == 0) {
		return 1;
	}
	if (color_order.size() == 1) {
		return 0;
	}
	int ptr = 0;
	while (q_order[ptr] == q_order[0]) {
		ptr++;
	}
	int clr_ptr = 0;
	int C = color_order.size();
	for (int it = 0; it < delta; ++it) {
		// cerr << "it = " << it << endl;
		while (clr_ptr < C && (Q[clr_ptr] == 0 || q_order[ptr] == color_order[clr_ptr])) {
			clr_ptr++;
		}
		if (clr_ptr == C) {
			return 0;
		}
		a[fetch(q_order[ptr])] = color_order[clr_ptr];
		Q[clr_ptr]--;
		ptr = (ptr + 1) % q_order.size();
	}
	return 1;
}

void solve() {
	cin >> n >> x >> y;
	b.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		b[i]--;
	}
	if (y < x) {
		no();
		return;
	}
	clr_pos.assign(n + 1, vector<int> ());
	for (int i = 0; i < n; ++i) {
		clr_pos[b[i]].push_back(i);
	}
	calc_np();
	assign_x();
	int can = assign_y();
	if (can == 0) {
		no();
	} else {
		yes();
	}
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}