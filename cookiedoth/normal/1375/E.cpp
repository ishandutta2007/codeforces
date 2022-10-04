/*

Code for problem E by cookiedoth
Generated 04 Jul 2020 at 06.37 PM


  !











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

const int mx = 1010;
int n, a[mx];
vector<pair<int, int> > vp;

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		vp.emplace_back(a[i], i);
	}
	sort(all(vp));
}

vector<pair<int, int> > ans;

int used[mx];

void solve() {
	for (auto pp : vp) {
		int id = pp.second;
		used[id] = 1;
		for (int i = n - 1; i > id; --i) {
			if (used[i]) {
				ans.emplace_back(id, i);
			}
		}
	}
	cout << ans.size() << endl;
	for (auto pp : ans) {
		cout << pp.first + 1 << ' ' << pp.second + 1 << '\n';
	}
}

signed main() {
	fast_io();
	read();
	solve();
}