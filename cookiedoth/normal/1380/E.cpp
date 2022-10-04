/*

Code for problem E by cookiedoth
Generated 12 Jul 2020 at 07.05 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

>_<
o_O
-_-

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

vector<vector<int> > lists;
vector<int> p, arr;
int n, m, ans;

void add(int pos, int sign) {
	if (pos && arr[pos] != arr[pos - 1]) {
		ans += sign;
	}
	if (pos != n - 1 && arr[pos] != arr[pos + 1]) {
		ans += sign;
	}
}

void read() {
	cin >> n >> m;
	lists.resize(m);
	p.resize(m);
	arr.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		arr[i]--;
		lists[arr[i]].push_back(i);
	}
	for (int i = 1; i < n; ++i) {
		if (arr[i] != arr[i - 1]) {
			ans++;
		}
	}
	iota(all(p), 0);
}

int get_root(int v) {
	return (p[v] == v ? v : p[v] = get_root(p[v]));
}

void join(int u, int v) {
	u = get_root(u);
	v = get_root(v);
	if (lists[u].size() > lists[v].size()) {
		swap(u, v);
	}
	for (auto x : lists[u]) {
		add(x, -1);
		arr[x] = v;
		add(x, 1);
		lists[v].push_back(x);
	}
	lists[u].clear();
	p[u] = v;
}

void process_queries() {
	cout << ans << '\n';
	for (int i = 0; i < m - 1; ++i) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		join(u, v);
		cout << ans << '\n';
	}
}

signed main() {
	fast_io();
	read();
	process_queries();
}