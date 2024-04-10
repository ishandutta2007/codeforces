/*

Code for problem A by cookiedoth
Generated 11 Dec 2020 at 07.06 PM


  !
 
                                    
                          
                  




















z_z
>_<
o_O

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

const int mx = 5010;
int n, a[mx], ans[mx], cnt[mx], max_cnt;

void read() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i]--;
	}
}

void solve(int r) {
	fill(cnt, cnt + n, 0);
	max_cnt = 0;
	for (int i = r; i < n; ++i) {
		cnt[a[i]]++;
		if (make_pair(cnt[a[i]], -a[i]) > make_pair(cnt[max_cnt], -max_cnt)) {
			max_cnt = a[i];
		}
		ans[max_cnt]++;
	}
}

signed main() {
	fast_io();
	read();
	for (int i = 0; i < n; ++i) {
		solve(i);
	}
	output(ans, ans + n, cout);
}