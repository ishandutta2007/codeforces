/*

Code for problem H by cookiedoth
Generated 18 Sep 2022 at 06.50 PM
The Moon is Waning Crescent (41% of Full)


 ] 
 
Il] 


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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#include <array>
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

int n, Z;
vector<int> a, gr, pos3, posn3;

void print() {
	cout << Z << '\n';
	for (int i = 0; i < n; ++i) {
		cout << gr[i];
	}
	cout << '\n';
}

signed main() {
	fast_io();
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] % 3 == 0) {
			pos3.push_back(i);
		} else {
			posn3.push_back(i);
		}
	}
	gr.resize(n, 0);
	for (auto x : posn3) {
		pos3.push_back(x);
	}
	for (int i = 0; i < n / 2; ++i) {
		gr[pos3[i]] = 1;
	}
	if (posn3.size() == 0 || posn3.size() == n) {
		Z = 1;
	} else {
		if (posn3.size() >= n / 2) {
			Z = 0;
		} else {
			Z = 2;
		}
	}
	print();
}