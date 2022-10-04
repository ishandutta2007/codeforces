/*

Code for problem D by cookiedoth
Generated 19 Mar 2020 at 05.48 PM


  !











=_=
\_()_/
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

string s;
int n, ps, best;
vector<pair<int, int> > rest_ans;

void process_subpal(int l, int r) {
	if (l <= ps || r >= n - 1 - ps) {
		int cur_ps = min(l, n - 1 - r);
		int cur_len = 2 * cur_ps + (r - l + 1);
		if (chkmax(best, cur_len)) {
			rest_ans = {{0, cur_ps - 1}, {l, r}, {n - cur_ps, n - 1}};
		}
	}
}

void solve() {
	cin >> s;
	n = s.size();
	vector<int> d1 (n);
	int l=0, r=-1;
	for (int i=0; i<n; ++i) {
	  int k = i>r ? 1 : min (d1[l+r-i], r-i+1);
	  while (i+k < n && i-k >= 0 && s[i+k] == s[i-k])  ++k;
	  d1[i] = k;
	  if (i+k-1 > r)
	    l = i-k+1,  r = i+k-1;
	}
	vector<int> d2 (n);
	l=0, r=-1;
	for (int i=0; i<n; ++i) {
	  int k = i>r ? 0 : min (d2[l+r-i+1], r-i+1);
	  while (i+k < n && i-k-1 >= 0 && s[i+k] == s[i-k-1])  ++k;
	  d2[i] = k;
	  if (i+k-1 > r)
	    l = i-k,  r = i+k-1;
	}
	// output(all(d1));
	// output(all(d2));
	ps = 0;
	best = 0;
	rest_ans.clear();
	for (int i = 0; i < n / 2; ++i) {
		if (s[ps] == s[n - 1 - ps]) {
			ps++;
		} else {
			break;
		}
	}
	for (int i = 0; i < n; ++i) {
		process_subpal(i - d1[i] + 1, i + d1[i] - 1);
	}
	for (int i = 1; i < n; ++i) {
		if (d2[i]) {
			process_subpal(i - d2[i], i + d2[i] - 1);
		}
	}
	string ans;
	for (auto pp : rest_ans) {
		if (pp.first <= pp.second) {
			ans += s.substr(pp.first, pp.second - pp.first + 1);
		}
	}
	cout << ans << "\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}