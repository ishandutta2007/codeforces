/*

Code for problem D by cookiedoth
Generated 20 Jul 2019 at 06.52 P


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

int n;
vector<pair<int, int> > edges;

int is_prime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		edges.emplace_back(i, (i + 1) % n);
	}
	int shift = n / 2, ptr = 0;
	while (!is_prime(edges.size())) {
		if (ptr == shift) {
			assert(0);
		}
		edges.emplace_back(ptr, (ptr + shift) % n);
		ptr++;
	}
	cout << edges.size() << endl;
	for (auto pp : edges) {
		cout << pp.first + 1 << " " << pp.second + 1 << endl;
	}
}