/*

Code for problem C by cookiedoth
Generated 30 May 2021 at 12.46 PM


  !











o_O
-_-
z_z

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

int L;
vector<string> A;

void set_cell(int r, int c) {
	if (r >= L || c >= L) {
		L = max(r, c) + 1;
	}
	A.resize(L);
	for (int i = 0; i < L; ++i) {
		A[i].resize(L, '.');
	}
	A[r][c] = 'o';
}

void print() {
	cout << L << '\n';
	for (int i = L - 1; i >= 0; --i) {
		cout << A[i] << '\n';
	}
}

signed main() {
	fast_io();
	int n;
	cin >> n;
	if (n == 2) {
		cout << -1 << '\n';
		exit(0);
	}
	int opt = -1;
	for (int i = 1; i * i <= n; ++i) {
		if (i * i % 2 == n % 2) {
			opt = i;
		}
	}
	for (int i = 0; i < opt; ++i) {
		for (int j = 0; j < opt; ++j) {
			set_cell(i, j);
		}
	}
	int cnt = (n - opt * opt) / 2;
	for (int i = opt; ; ++i) {
		for (int j = 0; j < opt; ++j) {
			if (cnt) {
				set_cell(i, j);
				set_cell(j, i);
				cnt--;
			} else {
				break;
			}
		}
		if (!cnt) {
			break;
		}
	}
	print();
}