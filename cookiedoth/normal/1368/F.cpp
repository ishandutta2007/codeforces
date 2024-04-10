/*

Code for problem  by cookiedoth
Generated 19 Jun 2020 at 12.47 PM










(@)(@)(@)(@)(@)

>_<
o_O
^_^

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

const int mx = 1010;
int n, state[mx];

void ask(vector<int> &v) {
	int k = v.size();
	cout << k;
	for (auto x : v) {
		state[x] = 1;
		cout << " " << x + 1;
	}
	cout << endl;
	int pos;
	cin >> pos;
	pos--;
	for (int it = 0; it < k; ++it) {
		state[pos] = 0;
		pos = (pos + 1) % n;
	}
	// cerr << "new_state" << endl;
	// output(state, state + n);
}

int k, best, n1;

int get() {
	return accumulate(state, state + n, 0);
}

void solve() {
	int s = 1;
	while ((s + 1) * (s + 1) <= n) {
		s++;
	}
	for (int cur_k = s; cur_k <= s; ++cur_k) {
		int blocks = n / cur_k;
		if (chkmax(best, (cur_k - 1) * (blocks - 1) + max(n % cur_k - 1, 0))) {
			k = cur_k;
		}
	}
	n1 = n - n % k;
	vector<int> cur;
	while (get() < best) {
		cur.clear();
		for (int i = 0; i < n; ++i) {
			if (i % k && state[i] == 0) {
				cur.push_back(i);
				if (cur.size() == k) {
					break;
				}
			}
		}
		ask(cur);
	}
}

signed main() {
	fast_io();
	cin >> n;
	if (n > 3) {
		solve();
	}
	cout << 0 << endl;
}