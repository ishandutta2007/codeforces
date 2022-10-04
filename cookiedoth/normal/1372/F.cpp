/*

Code for problem F by cookiedoth
Generated 11 Jul 2020 at 08.43 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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
int n, a[mx];

#ifndef TESTING
pair<int, int> ask(int l, int r) {
	cout << "? " << l + 1 << " " << r + 1 << endl;
	int x, f;
	cin >> x >> f;
	return {x, f};
}

void guess() {
	cout << "! ";
	output(a, a + n, cout);
	cout << endl;
}
#else
int arr[mx];

void read_arr() {
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
}

int q_id;

pair<int, int> ask(int l, int r) {
	cerr << "ask " << l << " " << r << endl;
	q_id++;
	map<int, int> mp;
	for (int i = l; i <= r; ++i) {
		mp[arr[i]]++;
	}
	vector<pair<int, int> > vp(all(mp));
	for (auto &pp : vp) {
		swap(pp.first, pp.second);
		pp.second = -pp.second;
	}
	sort(all(vp));
	pair<int, int> res(-vp.back().second, vp.back().first);
	return res;
}

void guess() {
	cerr << "q_id = " << q_id << endl;
	for (int i = 0; i < n; ++i) {
		assert(a[i] == arr[i]);
	}
	set<int> S;
	for (int i = 0; i < n; ++i) {
		S.insert(a[i]);
	}
	assert(q_id <= 4 * S.size());
	output(a, a + n);
}
#endif

void solve(int l, int r) {
	if (l > r) {
		return;
	}
	// cerr << "solve " << l << " " << r << endl;
	pair<int, int> pp = ask(l, r);
	int x = pp.first, f = pp.second;
	// cerr << "x = " << x << endl;
	int t = 1;
	while ((t << 1) < f) {
		t <<= 1;
	}
	// cerr << "t = " << t << endl;
	int l_pr = l - l % t;
	if (l_pr < l) {
		l_pr += t;
	}
	vector<int> detected;
	for (; l_pr <= r; l_pr += t) {
		// cerr << "l_pr " << a[l_pr] << endl;
		if (a[l_pr] == -1) {
			a[l_pr] = ask(l_pr, l_pr).first;
		}
		// cerr << "a " << l_pr << " " << a[l_pr] << endl;
		if (a[l_pr] == x) {
			detected.push_back(l_pr);
		}
	}
	// cerr << "detected" << endl;
	// output(all(detected));
	assert(detected.size() >= 1 && detected.size() <= 2);
	int L, R;
	if (detected.size() == 1) {
		int pos = detected[0];
		pair<int, int> pp = ask(max(l, pos - t + 1), pos);
		if (pp.first == x) {
			L = pos - pp.second + 1;
			R = L + f - 1;
		} else {
			pair<int, int> pp = ask(pos, min(r, pos + t - 1));
			assert(pp.first == x);
			R = pos + pp.second - 1;
			L = R - f + 1;
		}
	} else {
		int pos = detected[0];
		pair<int, int> pp = ask(pos, min(r, pos + 2 * t - 1));
		R = pos + pp.second - 1;
		L = R - f + 1;
	}
	for (int i = L; i <= R; ++i) {
		a[i] = x;
	}
	solve(l, L - 1);
	solve(R + 1, r);
}

signed main() {
	fast_io();
	cin >> n;
	#ifdef TESTING
		read_arr();
	#endif
	fill(a, a + n, -1);
	solve(0, n - 1);
	guess();
}