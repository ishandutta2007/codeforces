/*
 
Code for problem A by cookiedoth
Generated 15 Dec 2019 at 02.08 P
 
 








(@)(@)(@)(@)(@)
 
~_^
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
 
int a, b, c, d, e, f;
 
signed main() {
	fast_io();
	cin >> a >> b >> c >> d >> e >> f;
	int ans = 0;
	if (e > f) {
		int ce = min(a, d);
		d -= ce;
		ans += ce * e;
		int cf = min(min(b, c), d);
		ans += cf * f;
	} else {
		int cf = min(min(b, c), d);
		d -= cf;
		ans += cf * f;
		int ce = min(a, d);
		ans += ce * e;
	}
	cout << ans << endl;
}