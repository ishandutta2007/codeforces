/*

Code for problem E by cookiedoth
Generated 24 Nov 2019 at 02.21 P


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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

const int mx = 1010;
int n, a[mx], used[mx], ptr, c[mx], lst[mx], new_class[mx][2];
char ans[mx][mx];

void divide(int id) {
	fill(lst, lst + n + 1, -1);
	fill(used, used + n + 1, -1);
	int cnt = a[id];
	for (int i = 0; i <= n; ++i) {
		if (lst[c[i]] != -1) {
			used[lst[c[i]]] = 0;
			used[i] = 1;
			cnt--;
			break;
		}
		lst[c[i]] = i;
	}
	for (int i = 0; i <= n; ++i) {
		if (used[i] == -1) {
			if (cnt) {
				used[i] = 1;
				cnt--;
			} else {
				used[i] = 0;
			}
		}
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < 2; ++j) {
			new_class[i][j] = -1;
		}
	}
	int ptr = 0;
	for (int i = 0; i <= n; ++i) {
		if (new_class[c[i]][used[i]] == -1) {
			new_class[c[i]][used[i]] = ptr++;
		}
		c[i] = new_class[c[i]][used[i]];
	}
	for (int i = 0; i <= n; ++i) {
		ans[i][id] = used[i];
	}
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		divide(i);
	}
	cout << n + 1 << endl;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << (int)ans[i][j];
		}
		cout << endl;
	}
}