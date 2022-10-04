/*

Code for problem C by cookiedoth
Generated 08 May 2022 at 08.19 PM


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

const int MAX_N = 1e5 + 228;
int n, ca[MAX_N], cb[MAX_N], par[MAX_N];
bool used[MAX_N];

int dfs(int v) {
	used[v] = true;
	if (used[par[v]]) {
		return 1;
	} else {
		return 1 + dfs(par[v]);
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> ca[i];
		ca[i]--;
	}
	for (int i = 0; i < n; ++i) {
		cin >> cb[i];
		cb[i]--;
	}
	for (int i = 0; i < n; ++i) {
		par[ca[i]] = cb[i];
	}
	fill(used, used + n, false);
	int odd_c = 0;
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			int cycle_sz = dfs(i);
			odd_c += cycle_sz % 2;
		}
	}
	int pm = (n - odd_c) / 2;
	ll ans = 0;
	for (int i = 1; i <= pm; ++i) {
		ans -= 2 * i;
	}
	for (int i = n - pm + 1; i <= n; ++i) {
		ans += 2 * i;
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}