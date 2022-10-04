/*

Code for problem B by cookiedoth
Generated 21 Jul 2020 at 05.54 PM



10%

30%

50%

70%

100%

z_z
=_=
\_()_/

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

const int mx = 2010;
int n;
vector<int> p;

bitset<mx> B;

void solve() {
	cin >> n;
	p.resize(2 * n);
	for (int i = 0; i < 2 * n; ++i) {
		cin >> p[i];
		p[i]--;
	}
	vector<int> lens;
	int prev_max = p[0], prev_max_pos = 0;
	for (int i = 1; i < 2 * n; ++i) {
		if (p[i] > prev_max) {
			lens.push_back(i - prev_max_pos);
			prev_max = p[i];
			prev_max_pos = i;
		}
	}
	lens.push_back(2 * n - prev_max_pos);
	B.reset();
	B[0] = 1;
	for (auto l : lens) {
		B |= (B << l);
	}
	cout << (B[n] ? "YES" : "NO") << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}