/*

Code for problem A by cookiedoth
Generated 01 Apr 2019 at 07.54 P


  !











-_-
z_z
>_<

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

const ll INF = 1e18;
ll n, k, a, b, p1, p2, q1, q2, MOD;
ll low = INF, high = 0;

ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

void go(ll l) {
	//cerr << "l = " << l << endl;
	ll res = MOD / gcd(l, MOD);
	chkmax(high, res);
	chkmin(low, res);
}

void go(ll pos1, ll pos2) {
	if (pos2 > pos1) {
		go(pos2 - pos1);
	}
	else {
		go(MOD - (pos1 - pos2));
	}
}

signed main() {
	fast_io();
	cin >> n >> k >> a >> b;
	MOD = n * k;
	p1 = a;
	p2 = k - a;
	q1 = b;
	q2 = k - b;
	for (ll i = 0; i < n; ++i) {
		go(p1, i * k + q1);
		go(p1, i * k + q2);
		go(p2, i * k + q1);
		go(p2, i * k + q2);
	}
	cout << low << " " << high << endl;
}