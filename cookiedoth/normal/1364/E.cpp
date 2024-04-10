/*

Code for problem E by cookiedoth
Generated 22 Jun 2020 at 01.33 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

-_-
z_z
=_=

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

mt19937 rng(58);
int n;

int ask(int i, int j) {
	cout << "? " << i + 1 << " " << j + 1 << endl;
	int res;
	cin >> res;
	return res;
}

void guess(vector<int> &ans) {
	cout << "!";
	for (auto x : ans) {
		cout << " " << x;
	}
	cout << endl;
}

int B;
vector<int> got_zero;

void read() {
	cin >> n;
	while (n > (1 << B)) {
		B++;
	}
}

void find_bits_zeros() {
	got_zero.resize(B);
	for (int i = 0; i < B; ++i) {
		while (true) {
			int x = rng() % n;
			int y = rng() % n;
			if (x != y && ((ask(x, y) >> i) & 1) == 0) {
				got_zero[i] = x;
				// cerr << "got_zero " << i << " = " << x << endl;
				break;
			}
		}
	}
}

int zero_pos;

void find_zero() {
	int cand = got_zero[0], tail = 1, mask = 1;
	for (int i = 0; i < n; ++i) {
		if (tail == B) {
			break;
		}
		if (i != cand && (ask(i, cand) & mask)) {
			continue;
		}
		while (tail < B) {
			if (i != got_zero[tail] && ((ask(i, got_zero[tail]) >> tail) & 1)) {
				break;
			}
			cand = i;
			mask ^= (1 << tail);
			tail++;
		}
	}
	zero_pos = cand;
	// cerr << "zero_pos = " << zero_pos << endl;
}

vector<int> ans;

void restore() {
	ans.resize(n);
	for (int i = 0; i < n; ++i) {
		if (i != zero_pos) {
			ans[i] = ask(zero_pos, i);
		}
	}
	guess(ans);
}

signed main() {
	fast_io();
	read();
	find_bits_zeros();
	find_zero();
	restore();
}