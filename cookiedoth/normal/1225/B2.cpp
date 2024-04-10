/*

Code for problem B by cookiedoth
Generated 26 Oct 2019 at 02.09 P


 ] 
 
Il] 


z_z
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

const int mx = 1e6 + 228;
int cnt[mx], cnt_diff;

void add(int val) {
	if (cnt[val] == 0) {
		cnt_diff++;
	}
	cnt[val]++;
}

void remove(int val) {
	if (cnt[val] == 1) {
		cnt_diff--;
	}
	cnt[val]--;
}

int get() {
	return cnt_diff;
}

void solve() {
	int n, k, d;
	cin >> n >> k >> d;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = k;
	for (int i = 0; i < d; ++i) {
		add(a[i]);
	}
	chkmin(ans, get());
	for (int i = d; i < n; ++i) {
		add(a[i]);
		remove(a[i - d]);
		chkmin(ans, get());
	}
	cout << ans << "\n";
	for (auto x : a) {
		cnt[x] = 0;
	}
	cnt_diff = 0;
}

int t;

signed main() {
	fast_io();
	cin >> t;
	for (int i = 0; i < t; ++i) {
		solve();
	}
}