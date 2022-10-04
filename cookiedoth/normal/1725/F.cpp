/*

Code for problem F by cookiedoth
Generated 18 Sep 2022 at 07.43 PM
The Moon is Waning Crescent (40% of Full)


  !











o_O
^_^
~_^

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
#include <chrono>
#include <array>
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

const int MAX_N = 1e5 + 228;
const int MAX_B = 30;
int n, L[MAX_N], R[MAX_N], ans[MAX_B];
vector<pair<int, int>> events;

void add_seg(int l, int r) {
	events.emplace_back(l, 1);
	events.emplace_back(r + 1, -1);
}

int scanline() {
	int bal = 0, res = 0;
	sort(all(events));
	for (auto [x, delta] : events) {
		bal += delta;
		chkmax(res, bal);
	}
	return res;
}

signed main() {
	fast_io();
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> L[i] >> R[i];
	}
	for (int b = 0; b < MAX_B; ++b) {
		events.clear();
		ans[b] = 0;
		for (int i = 0; i < n; ++i) {
			if (R[i] - L[i] + 1 >= (1 << b)) {
				ans[b]++;
			} else {
				int l = L[i] % (1 << b);
				int r = R[i] % (1 << b);
				if (r >= l) {
					add_seg(l, r);
				} else {
					add_seg(l, (1 << b) - 1);
					add_seg(0, r);
				}
			}
		}
		ans[b] += scanline();
	}
	int q;
	cin >> q;
	while (q--) {
		int x;
		cin >> x;
		int b_cnt = 0;
		while (x % 2 == 0) {
			b_cnt++;
			x >>= 1;
		}
		cout << ans[b_cnt] << '\n';
	}
}