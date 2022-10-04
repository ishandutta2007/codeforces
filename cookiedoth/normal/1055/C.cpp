/*

Code for problem C by savkinsd2089
Generated 10 Nov 2018 at 05.50 pm
The Moon is Waxing Crescent (9% of Full)










(@)(@)(@)(@)(@)

o_O
-_-
o_O

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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

#ifndef TESTING
	#define endl '\n'
#endif

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

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}

int intersect(int l1, int r1, int l2, int r2) {
	return max(0, min(r1, r2) - max(l1, l2) + 1);
}

int l1, r1, t1;
int l2, r2, t2;

int intersect2(int diff) {
	int d1 = r1 - l1;
	int d2 = r2 - l2;
	return intersect(0, d1, diff, diff + d2);
}

signed main() {
	cin >> l1 >> r1 >> t1;
	cin >> l2 >> r2 >> t2;
	int g = gcd(t1, t2);
	int diff = l2 - l1;
	diff = (diff % g + g) % g;
	//cerr << "diff = " << diff << endl;
	cout << max(intersect2(diff), intersect2(diff - g)) << endl;
}