/*

Code for problem F by savkinsd2089
Generated 16 Dec 2018 at 07.51 pm
The Moon is Waxing Gibbous (62% of Full)


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

>_<
z_z
-_-

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

int get(int l, int r) {
	cout << "? " << l + 1 << " " << r + 1 << endl;
	int val;
	cin >> val;
	return val;
}

int get_double(int l, int r) {
	get(l, r);
	return get(l, r);
}

const int mx = 1e5 + 228;
int n, t, a[mx], suf_sum[mx];
const int K = 16;

int gen_sum_suf(int pos) {
	vector<int> t;
	for (int i = 0; i < K; ++i) {
		t.push_back(get_double(pos, n - 1));
	}
	int v0 = (*min_element(all(t))), v1 = (*max_element(all(t)));
	int res = (v0 + v1 - pos) / 2;
	return res;
}

signed main() {
	cin >> n >> t;
	suf_sum[0] = t;
	for (int i = 1; i < n; ++i) {
		suf_sum[i] = gen_sum_suf(i);
	}
	for (int i = 0; i < n; ++i) {
		a[i] = suf_sum[i] - suf_sum[i + 1];
	}
	cout << "! ";
	for (int i = 0; i < n; ++i) {
		cout << a[i];
	}
	cout << endl;
}