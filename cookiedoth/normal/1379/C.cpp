/*

Code for problem C by cookiedoth
Generated 20 Jul 2020 at 01.50 PM


 ] 
 
Il] 


=_=
\_()_/
^_^

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
#define int long long
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
vector<pair<ll, ll> > f;
vector<ll> a, suf_sum;

void solve() {
	cin >> n >> m;
	a.clear();
	f.clear();
	for (int i = 0; i < m; ++i) {
		ll A, B;
		cin >> A >> B;
		f.emplace_back(A, B);
		a.push_back(A);
	}
	sort(all(a));
	suf_sum.assign(m + 1, 0);
	suf_sum[m - 1] = a[m - 1];
	for (int i = m - 2; i >= 0; --i) {
		suf_sum[i] = suf_sum[i + 1] + a[i];
	}
	ll ans = 0;
	for (auto pp : f) {
		int pos = upper_bound(all(a), pp.second) - a.begin();
		ll take = m - pos, sum = suf_sum[pos];
		if (pp.first > pp.second) {
			take--;
			sum -= pp.first;
		}
		if (take > n - 1) {
			continue;
		}
		chkmax(ans, sum + pp.first + (ll)(n - take - 1) * (ll)pp.second);
	}
	if (n <= m) {
		chkmax(ans, suf_sum[m - n]);
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