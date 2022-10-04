/*

Code for problem C by cookiedoth
Generated 07 May 2020 at 05.08 PM


   ,##.                   ,==.
 ,#    #.                 \ o ',
#        #     _     _     \    \
#        #    (_)   (_)    /    ; 
 `#    #'                 /   .'  
   `##'                   "=="

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
#define rall(a) a.rbegin(), a.rend()
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

string dir_s = "SNWE";
vector<pair<int, int> > dir = {
	{0, -1},
	{0, 1},
	{-1, 0},
	{1, 0}
};

void solve() {
	int ans = 0;
	set<vector<int> > usedCoords;
	pair<int, int> coords = {0, 0};
	string path;
	cin >> path;
	for (auto c : path) {
		pair<int, int> delta = dir[dir_s.find(c)];
		pair<int, int> newCoords = {coords.first + delta.first, 
			coords.second + delta.second};
		if (usedCoords.find({coords.first, coords.second, newCoords.first, newCoords.second}) != usedCoords.end() ||
			usedCoords.find({newCoords.first, newCoords.second, coords.first, coords.second}) != usedCoords.end()) {
			ans++;
		} else {
			ans += 5;
		}
		usedCoords.insert({coords.first, coords.second, newCoords.first, newCoords.second});
		coords = newCoords;
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}