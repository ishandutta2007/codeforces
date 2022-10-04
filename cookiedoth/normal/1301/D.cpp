/*

Code for problem  by cookiedoth
Generated 13 Feb 2020 at 07.10 P


 ] 
 
Il] 


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

int n, m, k;
vector<pair<string, int> > path;

void gen_path() {
	for (int i = 0; i < n - 1; ++i) {
		if (m > 1) {
			path.emplace_back("R", m - 1);
			path.emplace_back("DUL", m - 1);
		}
		path.emplace_back("D", 1);
	}
	if (m > 1) {
		path.emplace_back("R", m - 1);
		path.emplace_back("L", m - 1);
	}
	if (n > 1) {
		path.emplace_back("U", n - 1);
	}
}

void resize_path() {
	int sum = 0, ok = 0;
	for (int i = 0; i < path.size(); ++i) {
		int len = path[i].first.size();
		string S = path[i].first;
		int cnt = path[i].second;
		if (sum + len * cnt >= k) {
			path.resize(i);
			int rem = k - sum;
			if (rem / len) {
				path.emplace_back(S, rem / len);
			}
			if (rem % len) {
				path.emplace_back(S.substr(0, rem % len), 1);
			}
			ok = 1;
			break;
		}
		sum += len * cnt;
	}
	if (!ok) {
		cout << "NO\n";
		exit(0);
	}
}

void print_path() {
	cout << "YES\n";
	cout << path.size() << "\n";
	for (auto pp : path) {
		cout << pp.second << " " << pp.first << "\n";
	}
}

signed main() {
	fast_io();
	cin >> n >> m >> k;
	gen_path();
	resize_path();
	print_path();
}