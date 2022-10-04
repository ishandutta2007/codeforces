/*

Code for problem E by cookiedoth
Generated 29 Dec 2019 at 05.26 P


 ] 
 
Il] 


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

const int mx = 1e5 + 228;
int n, x[mx], y[mx];

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
	}
	for (int i = 1; i < n; ++i) {
		x[i] -= x[0];
		y[i] -= y[0];
	}
	x[0] = 0;
	y[0] = 0;
	while (true) {
		int have_odd = 0;
		for (int i = 0; i < n; ++i) {
			if (x[i] % 2 || y[i] % 2) {
				have_odd = 1;
				break;
			}
		}
		if (!have_odd) {
			for (int i = 0; i < n; ++i) {
				x[i] /= 2;
				y[i] /= 2;
			}
		} else {
			break;
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if ((x[i] + y[i]) % 2) {
			ans.push_back(i);
		}
	}
	if (!ans.empty()) {
		cout << ans.size() << endl;
		for (auto x : ans) {
			cout << x + 1 << " ";
		}
		cout << endl;
		exit(0);
	}
	for (int i = 0; i < n; ++i) {
		if (x[i] % 2) {
			ans.push_back(i);
		}
	}
	cout << ans.size() << endl;
	for (auto x : ans) {
		cout << x + 1 << " ";
	}
	cout << endl;
}