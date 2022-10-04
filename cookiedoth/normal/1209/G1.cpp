/*

Code for problem G1 by cookiedoth
Generated 14 Sep 2019 at 05.16 P



10%

30%

50%

70%

100%

>_<
o_O
-_-

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

const int mx = 2e5 + 228;
int n, a[mx], l[mx], r[mx], val[mx];

signed main() {
	fast_io();
	int q;
	cin >> n >> q;
	for (int i = 0; i < mx; ++i) {
		l[i] = n;
		r[i] = -1;
	}
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		chkmin(l[a[i]], i);
		chkmax(r[a[i]], i);
	}
	for (int i = 0; i < mx; ++i) {
		if (l[i] <= r[i]) {
			val[l[i]]++;
			val[r[i]]--;
		}
	}
	int L = 0, sum = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		sum += val[i];
		if (sum == 0) {
			//cerr << "segment " << L << " " << i << endl;
			map<int, int> mp;
			for (int j = L; j <= i; ++j) {
				mp[a[j]]++;
			}
			int val = 0;
			for (auto pp : mp) {
				chkmax(val, pp.second);
			}
			ans += (i - L + 1 - val);
			L = i + 1;
		}
	}
	cout << ans << endl;
}