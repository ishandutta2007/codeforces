/*

Code for problem A by cookiedoth
Generated 03 Apr 2020 at 05.36 PM


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
int n, m, len[mx], ans[mx], res[mx];
vector<pair<int, int> > vp;

void check() {
	output(len, len + m);
	fill(res, res + n, -1);
	for (int i = 0; i < m; ++i) {
		for (int j = ans[i]; j < ans[i] + len[i]; ++j) {
			res[j] = i;
		}
	}
	output(res, res + n);
}

signed main() {
	fast_io();
	cin >> n >> m;
	vp.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> vp[i].first;
		len[i] = vp[i].first;
		vp[i].second = i;
	}
	reverse(all(vp));
	// sort(all(vp));
	int pos = n;
	for (int i = 0; i < m; ++i) {
		pos -= vp[i].first;
		chkmax(pos, m - 1 - i);
		if (pos + vp[i].first > n) {
			cout << -1 << endl;
			exit(0);
		}
		ans[vp[i].second] = pos;
	}
	if (pos > 0) {
		cout << -1 << endl;
		exit(0);
	}
	for (int i = 0; i < m; ++i) {
		cout << ans[i] + 1 << " ";
	}
	cout << "\n";
}