/*

Code for problem B by cookiedoth
Generated 30 May 2021 at 12.37 PM


  !











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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

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

int n;
map<int, int> cnt;
map<pair<int, int>, int> cnt2;

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int w, h;
		cin >> w >> h;
		if (h > w) {
			swap(h, w);
		}
		cnt[w]++;
		cnt[h]++;
		cnt2[{h, w}]++;
	}
	ll ans = 0;
	for (auto [_, a] : cnt) {
		ans += (ll)a * (ll)(a - 1) / 2;
	}
	// cerr << "ans = " << ans << '\n';
	for (auto [pp, a] : cnt2) {
		if (pp.first != pp.second) {
			ans -= (ll)a * (ll)(a - 1) / 2;
		} else {
			ll others = cnt[pp.first] - 2 * a;
			ans -= 3 * (ll)a * (ll)(a - 1) / 2 + a + others * a;
		}
	}
	cout << ans << '\n';
}