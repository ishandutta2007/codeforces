/*

Code for problem B by cookiedoth
Generated 23 Apr 2020 at 05.56 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define sz(a) (int)a.size()
#define popcount(x) __builtin_popcount(x)

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

vector<vector<int> > digits = {
	{1, 3, 6, 7, 2, 5},
	{3, 6},
	{1, 3, 4, 5, 7},
	{1, 3, 4, 6, 7},
	{2, 4, 3, 6},
	{1, 2, 4, 6, 7},
	{1, 2, 4, 6, 7, 5},
	{1, 3, 6},
	{1, 2, 3, 4, 5, 6, 7},
	{1, 2, 3, 4, 6, 7}
};

const int D = 10;
const int SEG = 7;
const int mx = 2010;
int n, k, mask[mx], digit_mask[D];

void calc_digit_mask() {
	for (int i = 0; i < D; ++i) {
		for (auto x : digits[i]) {
			digit_mask[i] ^= (1 << (x - 1));
		}
	}
}

void read() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < SEG; ++j) {
			char bit;
			cin >> bit;
			if (bit == '1') {
				mask[i] ^= (1 << j);
			}
		}
	}
	reverse(mask, mask + n);
}

bitset<mx> dp[mx];

void calc_dp() {
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int m = 0; m < D; ++m) {
			if ((mask[i] & digit_mask[m]) == mask[i]) {
				dp[i + 1] |= (dp[i] << (popcount(digit_mask[m]) - popcount(mask[i])));
			}
		}
	}
}

int ans[mx];

void restore_ans() {
	int cur = k;
	for (int i = n - 1; i >= 0; --i) {
		for (int d = D - 1; d >= 0; --d) {
			if ((mask[i] & digit_mask[d]) == mask[i]) {
				int delta = popcount(digit_mask[d]) - popcount(mask[i]);
				if (cur - delta >= 0 && dp[i][cur - delta]) {
					ans[i] = d;
					cur -= delta;
					break;
				}
			}
		}
	}
}

void print_ans() {
	for (int i = n - 1; i >= 0; --i) {
		cout << ans[i];
	}
	cout << endl;
}

signed main() {
	fast_io();
	calc_digit_mask();
	read();
	calc_dp();
	if (dp[n][k] == 0) {
		cout << -1 << endl;
		exit(0);
	}
	restore_ans();
	print_ans();
}