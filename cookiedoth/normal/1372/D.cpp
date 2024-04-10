/*

Code for problem D by cookiedoth
Generated 11 Jul 2020 at 07.06 PM


  !
 
                                    
                          
                  




















\_()_/
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

const ll INF = 1e18;
const int mx = 2e5 + 228;
int n;
vector<int> a, v;

void solve() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	v.clear();
	int pos = 0;
	for (int i = 0; i < 2 * n; ++i) {
		v.push_back(a[pos]);
		pos = (pos + 2) % n;
	}
	vector<ll> pref(2 * n + 1);
	for (int i = 0; i < 2 * n; ++i) {
		pref[i + 1] = pref[i] + v[i];
	}
	ll sum = accumulate(all(a), 0LL);
	ll diff = INF;
	for (int i = n / 2; i <= 2 * n; ++i) {
		chkmin(diff, pref[i] - pref[i - n / 2]);
	}
	cout << sum - diff << '\n';
}

signed main() {
	fast_io();
	solve();
}