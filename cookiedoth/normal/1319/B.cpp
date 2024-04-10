#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <queue>
#include <deque>
#include <numeric>
#include <random>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(const T &x, ostream &out = cerr) {
	output(all(x), out);
}

template<class T> int chkmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmax(T &a, const T &b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int n;
map<int, ll> mp;

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		ll val;
		cin >> val;
		mp[i - val] += val;
	}
	ll ans = 0;
	for (auto pp : mp) {
		chkmax(ans, pp.second);
	}
	cout << ans << endl;
}