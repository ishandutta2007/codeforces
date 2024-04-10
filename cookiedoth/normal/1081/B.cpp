/*

Code for problem B by savkinsd2089
Generated 16 Dec 2018 at 05.14 pm
The Moon is Waxing Gibbous (61% of Full)


 ] 
 
Il] 


z_z
~_^
>_<

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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

#ifndef TESTING
	#define endl '\n'
#endif

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
int n, a[mx], ptr;
vector<int> pos[mx];

signed main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int val;
		cin >> val;
		pos[val].push_back(i);
	}

	for (int i = 0; i < n; ++i) {
		int sz = pos[i].size(), block_sz = n - i;
		if (sz % block_sz != 0) {
			cout << "Impossible\n";
			return 0;
		}
		for (int j = 0; j < sz; j += block_sz) {
			for (int x = j; x < j + block_sz; ++x) {
				a[pos[i][x]] = ptr;
			}
			ptr++;
		}
	}

	cout << "Possible\n";
	for (int i = 0; i < n; ++i) {
		cout << a[i] + 1 << " ";
	}
	cout << endl;
}