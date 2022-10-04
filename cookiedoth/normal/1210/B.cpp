/*

Code for problem B by cookiedoth
Generated 22 Sep 2019 at 12.18 P



10%

30%

50%

70%

100%

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

const ll mx = 7010;
int n;
ll a[mx], b[mx];
map<ll, int> cnt;
vector<ll> useful;

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	for (auto pp : cnt) {
		if (pp.second >= 2) {
			useful.push_back(pp.first);
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (cnt[a[i]] >= 2) {
			ans += b[i];
		}
		else {
			for (auto x : useful) {
				if ((a[i] | x) == x) {
					ans += b[i];
					break;
				}
			}
		}
	}
	cout << ans << endl;
}