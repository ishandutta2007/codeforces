/*

Code for problem A by cookiedoth
Generated 01 Apr 2019 at 08.06 P


 ] 
 
Il] 


~_^
z_z
>_<

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

int get(vector<int> &a, int l, int r) {
	int neok = 0;
	for (int i = l + 1; i <= r; ++i) {
		if (a[i] < a[i - 1]) {
			neok = 1;
			break;
		}
	}
	if (neok == 0) {
		return r - l + 1;
	}
	int mid = (l + r) >> 1;
	int v1 = get(a, l, mid);
	int v2 = get(a, mid + 1, r);
	return max(v1, v2);
}

signed main() {
	fast_io();
	int n;
	vector<int> a;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int res = get(a, 0, n - 1);
	cout << res << endl;
}