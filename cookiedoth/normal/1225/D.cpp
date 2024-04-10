/*

Code for problem D by cookiedoth
Generated 26 Oct 2019 at 02.24 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

>_<
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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

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

int n, k;

void factor(int x, vector<int> &p, vector<int> &deg) {
	for (int i = 2; i * i <= x; ++i) {
		int cnt = 0;
		while (x % i == 0) {
			cnt++;
			x /= i;
		}
		if (cnt % k) {
			p.push_back(i);
			deg.push_back(cnt % k);
		}
	}
	if (x > 1) {
		p.push_back(x);
		deg.push_back(1);
	}
}

const int mx = 1e5 + 228;
int a[mx];
ll ans;

void solve_bucket(vector<vector<int> > bucket) {
	int len = bucket[0].size();
	ll sz = bucket.size();
	map<vector<int>, int> cnt;
	for (auto v : bucket) {
		cnt[v]++;
	}
	ll div2 = 0;
	for (auto pp : cnt) {
		vector<int> v1(len);
		for (int i = 0; i < len; ++i) {
			v1[i] = k - pp.first[i];
		}
		if (v1 == pp.first) {
			ans += (ll)pp.second * ((ll)pp.second - 1) / 2;
		}
		else {
			div2 += (ll)pp.second * (ll)cnt[v1];
		}
	}
	ans += div2 / 2;
}

map<vector<int>, vector<vector<int> > > buckets;

signed main() {
	fast_io();

	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		vector<int> p, deg;
		factor(a[i], p, deg);
		buckets[p].push_back(deg);
	}

	for (auto pp : buckets) {
		solve_bucket(pp.second);
	}

	cout << ans << endl;
}