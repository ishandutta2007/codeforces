/*

Code for problem B by cookiedoth
Generated 07 Jun 2020 at 06.27 PM


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

const int mx = 510;
int n, a[mx], b[mx];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> have(2);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		have[b[i]] = 1;
	}
	if (have[0] + have[1] == 2) {
		cout << "Yes\n";
		return;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i - 1]) {
			cout << "No\n";
			return;
		}
	}
	cout << "Yes\n";
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}