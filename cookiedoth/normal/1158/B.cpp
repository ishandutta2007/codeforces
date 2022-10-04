/*

Code for problem B by cookiedoth
Generated 12 May 2019 at 06.12 P


 ] 
 
Il] 


^_^
~_^
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

signed main() {
	fast_io();
	int n, k;
	cin >> n >> k;
	if (n == k) {
		for (int i = 0; i < n; ++i) {
			cout << 0;
		}
		cout << endl;
		exit(0);
	}
	if (k == 1) {
		cout << 1;
		for (int i = 0; i < n - 1; ++i) {
			cout << 0;
		}
		cout << endl;
		exit(0);
	}
	int pos = (n - k) / 2 + 1;
		vector<int> v(pos);
		v[0] = 1;
		v.back() = 0;
		srand(time(null));
	//no random
	for (int i = 0; i < n; ++i) {
		cout << v[i % pos];
	}
	cout << endl;

}