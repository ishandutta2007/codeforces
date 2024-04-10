/*

Code for problem D by cookiedoth
Generated 12 Jul 2020 at 06.37 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

o_O
^_^
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
// #define int long long
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

int n, m;
int x, y, k;
vector<int> a, b;
map<int, int> arg_a;

void read() {
	cin >> n >> m;
	cin >> x >> k >> y;
	a.resize(n);
	b.resize(m);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i < n; ++i) {
		arg_a[a[i]] = i;
	}
}

void no() {
	cout << -1 << '\n';
	exit(0);
}

vector<int> pos;

void build_pos() {
	int lst_pos = -1;
	pos.push_back(-1);
	for (int i = 0; i < m; ++i) {
		auto it = arg_a.find(b[i]);
		if (it != arg_a.end()) {
			int new_pos = it->second;
			if (new_pos > lst_pos) {
				lst_pos = new_pos;
				pos.push_back(new_pos);
			} else {
				no();
			}
		} else {
			no();
		}
	}
	pos.push_back(n);
}

int get(int pos) {
	return (pos >= 0 && pos < n ? a[pos] : -1);
}

const ll INF = 1e18;

void solve() {
	build_pos();
	ll ans = 0;
	for (int i = 1; i < pos.size(); ++i) {
		ll F = INF;
		int L = pos[i - 1], R = pos[i];
		int len = R - L - 1;
		if (len == 0) {
			continue;
		}
		int maxEl = (*max_element(a.begin() + L + 1, a.begin() + R));
		// cerr << "len = " << len << endl;
		if (maxEl < max(get(L), get(R))) {
			chkmin(F, 1LL * y * len);
		} else {
			if (len >= k) {
				chkmin(F, (ll)x + 1LL * y * (len - k));
			}
		}
		if (len >= k) {
			chkmin(F, 1LL * x * (len / k) + 1LL * y * (len % k));
		}
		if (F == INF) {
			no();
		}
		ans += F;
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	solve();
}