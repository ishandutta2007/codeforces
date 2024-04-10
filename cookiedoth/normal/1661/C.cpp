/*

Code for problem C by cookiedoth
Generated 09 Apr 2022 at 10.49 AM


  !
 
                                    
                          
                  




















z_z
>_<
\_()_/

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

const int MAX_N = 3e5 + 228;
int n;
ll h[MAX_N], tot, max_h, cnt[2];

void solve() {
	cin >> n;
	cnt[0] = cnt[1] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
		cnt[h[i] % 2]++;
	}
	tot = accumulate(h, h + n, 0LL);
	max_h = *max_element(h, h + n);
	ll ans = 1e18;
	for (ll target = max_h; target <= max_h + 2 * n; ++target) {
		ll grow = target * (ll)n - tot;
		ll cnt1 = cnt[(target % 2) ^ 1];
		ll cnt2 = (grow - cnt1) / 2;
		if (cnt2 > cnt1) {
			ll to_switch = (cnt2 - cnt1 + 1) / 3;
			cnt2 -= to_switch;
			cnt1 += 2 * to_switch;
		}
		chkmin(ans, max(2 * cnt1 - 1, 2 * cnt2));
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}