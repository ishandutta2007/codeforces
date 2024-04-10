/*

Code for problem A by cookiedoth
Generated 27 Nov 2019 at 09.22 P


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

int n, k;
vector<pair<int, int> > ans;
string s;

void put_char(int pos, char c) {
	for (int i = pos; i < n; ++i) {
		if (s[i] == c) {
			ans.emplace_back(pos, i);
			reverse(s.begin() + pos, s.begin() + i + 1);
			return;
		}
	}
}

void solve() {
	cin >> n >> k;
	cin >> s;
	ans.clear();
	for (int i = 0; i < k - 1; ++i) {
		put_char(2 * i, '(');
		put_char(2 * i + 1, ')');
	}
	int pos = 2 * (k - 1), len = (n - pos) / 2;
	for (int i = pos; i < pos + len; ++i) {
		put_char(i, '(');
	}
	for (int i = pos + len; i < n; ++i) {
		put_char(i, ')');
	}
	cout << ans.size() << endl;
	for (auto pp : ans) {
		cout << pp.first + 1 << " " << pp.second + 1 << endl;
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