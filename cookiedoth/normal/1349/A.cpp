/*

Code for problem A by cookiedoth
Generated 12 May 2020 at 03.36 PM


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
int n, a[mx];
map<int, vector<int> > mp;

void factor(int x) {
	for (int i = 2; i * i <= x; ++i) {
		int cnt = 0;
		while (x % i == 0) {
			cnt++;
			x /= i;
		}
		if (cnt) {
			mp[i].push_back(cnt);
		}
	}
	if (x > 1) {
		mp[x].push_back(1);
	}
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		factor(a[i]);
	}
	ll ans = 1;
	for (auto pp : mp) {
		vector<int> v = pp.second;
		int p = pp.first;
		sort(all(v));
		int cnt = 0;
		if (v.size() == n - 1) {
			cnt = v[0];
		}
		if (v.size() == n) {
			cnt = v[1];
		}
		for (int it = 0; it < cnt; ++it) {
			ans *= p;
		}
	}
	cout << ans << endl;
}