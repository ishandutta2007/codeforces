/*

Code for problem D by cookiedoth
Generated 02 Feb 2020 at 06.40 P










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
#define rall(a) a.rbegin(), a.rend()
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

const int mx = 2010;
int n, k, bad[mx];

void ask(int pos) {
	cout << "? " << pos + 1 << endl;
	char c;
	cin >> c;
	if (c == 'Y') {
		bad[pos] = 1;
	}
}

void clear() {
	cout << 'R' << endl;
}

void answer() {
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (bad[i] == 0) {
			ans++;
		}
	}
	cout << "! " << ans << endl;
	exit(0);
}

vector<vector<int> > chains;

void gen_chains(int sz, int len) {
	vector<int> cur_chain;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			cur_chain.clear();
			int kek = 0;
			for (int pos = 0; pos < sz; pos += len) {
				if ((kek++) % 2 == 0) {
					cur_chain.push_back(pos + i);
				} else {
					cur_chain.push_back(pos + j);
				}
			}
			chains.push_back(cur_chain);
		}
	}
}

void gen_chains(int sz) {
	for (int len = 1; len < sz; len *= 2) {
		gen_chains(sz, len);
	}
}

int block_size;

void handle_chain(vector<int> v) {
	for (auto block_id : v) {
		for (int i = 0; i < block_size; ++i) {
			ask(block_id * block_size + i);
		}
	}
	clear();
}

signed main() {
	fast_io();
	cin >> n >> k;
	block_size = (k == 1 ? 1 : k / 2);
	gen_chains(n / block_size);
	for (auto ch : chains) {
		handle_chain(ch);
	}
	answer();
	// cerr << "chains:" << endl;
	// for (auto v : chains) {
	// 	output(all(v));
	// }
	// cerr << "sz = " << chains.size() << endl;
}