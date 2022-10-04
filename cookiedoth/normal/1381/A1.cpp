/*

Code for problem A by cookiedoth
Generated 21 Jul 2020 at 05.40 PM


  !
 
                                    
                          
                  




















o_O
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

const int mx = 1e5 + 228;
int n, a[mx], b[mx];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	for (int i = 0; i < n; ++i) {
		char c;
		cin >> c;
		b[i] = c - '0';
	}
	vector<int> ans;
	int flips = 0;
	for (int i = n - 1; i >= 0; --i) {
		int curVal = a[0];
		if ((curVal ^ 1) != b[i]) {
			ans.push_back(1);
		}
		a[0] ^= 1;
		ans.push_back(i + 1);
		for (int j = 0; j <= i; ++j) {
			a[j] ^= 1;
		}
		reverse(a, a + i + 1);
		flips++;
	}
	cout << ans.size();
	for (auto x : ans) {
		cout << ' ' << x;
	}
	cout << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}