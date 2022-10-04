/*

Code for problem A by cookiedoth
Generated 20 Jul 2019 at 06.26 P



10%

30%

50%

70%

100%

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

int n;
vector<int> a;

signed main() {
	fast_io();
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> can = {0};
	int sum = a[0], all_sum = 0;
	for (int i = 0; i < n; ++i) {
		all_sum += a[i];
	}
	for (int i = 1; i < n; ++i) {
		if (a[0] >= a[i] * 2) {
			can.push_back(i);
			sum += a[i];
		}
	}
	if (2 * sum > all_sum) {
		cout << can.size() << endl;
		for (auto x : can) {
			cout << x + 1 << " ";
		}
		cout << endl;
	}
	else {
		cout << 0 << endl;
	}
}