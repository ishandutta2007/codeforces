/*

Code for problem D by cookiedoth
Generated 19 Apr 2021 at 05.01 PM


 ] 
 
Il] 


^_^
~_^
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

const int mx = 3e5 + 228;
int n, q, arr[mx], dom[4 * mx];
vector<vector<int>> pos;

void init_vectors() {
	pos.resize(n);
	for (int i = 0; i < n; ++i) {
		pos[arr[i]].push_back(i);
	}
}

int get(int l, int r, int val) {
	int res = upper_bound(all(pos[val]), r) - lower_bound(all(pos[val]), l);
	// cerr << "get " << l << ' ' << r << ' ' << val << ' ' << res << '\n';
	return res;
}

void build(int v, int tl, int tr) {
	// cerr << "into " << v << ' ' << tl << ' ' << tr << '\n';
	if (tl == tr) {
		dom[v] = arr[tl];
	} else {
		int tm = (tl + tr) >> 1;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		// cerr << "calc\n";
		int cnt1 = get(tl, tr, dom[v * 2]);
		// cerr << "cnt = " << cnt << '\n';
		int cnt2 = get(tl, tr, dom[v * 2 + 1]);
		dom[v] = (cnt1 > cnt2 ? dom[v * 2] : dom[v * 2 + 1]);
		// cerr << "dom " << tl << ' ' << tr << ' ' << dom[v] << '\n';
	}
}

int get(int l, int r, int v, int tl, int tr) {
	if (r < tl || tr < l) {
		return 0;
	}
	if (l <= tl && tr <= r) {
		return get(l, r, dom[v]);
	}
	int tm = (tl + tr) >> 1;
	int res_l = get(l, r, v * 2, tl, tm);
	int res_r = get(l, r, v * 2 + 1, tm + 1, tr);
	return max(res_l, res_r);
}

void read() {
	cin >> n >> q;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		arr[i]--;
	}
	init_vectors();
	// cerr << "done\n";
	build(1, 0, n - 1);
	// cerr << "built\n";
}

void process_queries() {
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		int cnt = get(l, r, 1, 0, n - 1);
		int cnt2 = r - l + 1 - cnt;
		cout << max(1, cnt - cnt2) << '\n';
	}
}

signed main() {
	fast_io();
	read();
	process_queries();
}