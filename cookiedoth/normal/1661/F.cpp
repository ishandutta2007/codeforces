/*

Code for problem F by cookiedoth
Generated 09 Apr 2022 at 11.58 AM










(@)(@)(@)(@)(@)

o_O
-_-
~_^

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

ll cost(ll len, ll k) {
	ll quo = len / k;
	ll ext = len - quo * k;
	return ext * (quo + 1) * (quo + 1) + (k - ext) * quo * quo;
}

ll cost_diff(ll len, ll k) {
	return cost(len, k) - cost(len, k + 1);
}

const int MAX_N = 2e5 + 228;
int n;
ll a[MAX_N], m, rem;
map<int, int> mp;

void read() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		mp[a[i] - a[i - 1]]++;
	}
	cin >> m;
	for (int i = 1; i <= n; ++i) {
		m -= (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
	}
	if (m >= 0) {
		cout << 0 << '\n';
		exit(0);
	} else {
		rem = -m;
	}
}

ll val[MAX_N], ptr[MAX_N], cnt[MAX_N];
priority_queue<pair<ll, int>> q;

void solve() {
	int cnt_diff = 0;
	for (auto [key, occ] : mp) {
		val[cnt_diff] = key;
		ptr[cnt_diff] = 1;
		cnt[cnt_diff] = occ;
		// cerr << "found " << key << ' ' << occ << '\n';
		if (val[cnt_diff] > 1) {
			q.push({cost_diff(key, 1), cnt_diff});
		}
		cnt_diff++;
	}
	ll ans = 0;
	while (!q.empty()) {
		auto [cd, pos] = q.top();
		q.pop();
		// cerr << "got " << cd << ' ' << pos << '\n';
		ll l = ptr[pos], r = val[pos] - 1;
		while (l < r) {
			ll mid = (l + r) >> 1;
			if (cost_diff(val[pos], mid + 1) == cd) {
				l = mid + 1;
			} else {
				r = mid;
			}
		}
		ll have = cnt[pos] * (l - ptr[pos] + 1);
		if (rem <= have * cd) {
			ans += (rem + cd - 1) / cd;
			cout << ans << '\n';
			exit(0);
		} else {
			ans += have;
			rem -= have * cd;
			ptr[pos] = l + 1;
			if (ptr[pos] < val[pos]) {
				q.push({cost_diff(val[pos], ptr[pos]), pos});
			}
		}
	}
	assert(0);
}

signed main() {
	fast_io();
	read();
	solve();
}