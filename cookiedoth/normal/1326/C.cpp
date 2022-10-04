/*

Code for problem C by cookiedoth
Generated 19 Mar 2020 at 05.42 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

~_^
=_=
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

const int mx = 2e5 + 228;
const ll MOD = 998244353;

ll mul(ll a, ll b) {
	return (a * b) % MOD;
}

int n, k;
ll p[mx];
vector<pair<int, ll> > vp;

signed main() {
	fast_io();
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		vp.emplace_back(p[i], i);
	}
	sort(rall(vp));
	ll ans1 = 0, ans2 = 1;
	for (int i = n; i > n - k; --i) {
		ans1 += (ll)i;
	}
	vector<int> pos;
	for (int i = 0; i < k; ++i) {
		pos.push_back(vp[i].second);
	}
	sort(all(pos));
	for (int i = 1; i < pos.size(); ++i) {
		ans2 = mul(ans2, pos[i] - pos[i - 1]);
	}
	cout << ans1 << " " << ans2 << endl;
}