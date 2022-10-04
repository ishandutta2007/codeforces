/*

Code for problem D by cookiedoth
Generated 31 May 2020 at 06.40 PM



10%

30%

50%

70%

100%

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

int n, k;
vector<vector<int> > subsets;

int ask(vector<int> &v) {
	if (v.empty()) {
		return 0;
	}
	cout << "?" << " " << v.size();
	for (auto x : v) {
		cout << " " << x + 1;
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
}

int ask(int l, int r) {
	vector<int> to_ask;
	for (int i = l; i <= r; ++i) {
		to_ask.push_back(i);
	}
	return ask(to_ask);
}

void guess(vector<int> &ans) {
	cout << "!";
	for (auto x : ans) {
		cout << " " << x;
	}
	cout << endl;
	string isCorrect;
	cin >> isCorrect;
	if (isCorrect != "Correct") {
		exit(0);
	}
}

void solve() {
	cin >> n >> k;
	subsets.assign(k, vector<int> ());
	for (int i = 0; i < k; ++i) {
		int curSubSz;
		cin >> curSubSz;
		for (int j = 0; j < curSubSz; ++j) {
			int x;
			cin >> x;
			x--;
			subsets[i].push_back(x);
		}
	}
	int l = 0, r = n - 1;
	int maxEl = ask(0, n - 1);
	while (l < r) {
		int mid = (l + r) >> 1;
		if (ask(l, mid) == maxEl) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	for (int i = 0; i < k; ++i) {
		for (auto id : subsets[i]) {
			if (id == l) {
				vector<int> inside(n);
				for (auto x : subsets[i]) {
					inside[x] = 1;
				}
				vector<int> not_here;
				for (int j = 0; j < n; ++j) {
					if (inside[j] == 0) {
						not_here.push_back(j);
					}
				}
				int cur_ans = ask(not_here);
				vector<int> ans(k, maxEl);
				ans[i] = cur_ans;
				guess(ans);
				return;
			}
		}
	}
	vector<int> ans(k, maxEl);
	guess(ans);
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}