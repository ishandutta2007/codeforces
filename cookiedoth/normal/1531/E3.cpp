/*

Code for problem E by cookiedoth
Generated 30 May 2021 at 01.33 PM



10%

30%

50%

70%

100%

>_<
\_()_/
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
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
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

string s;
int ptr = 0;
vector<vector<int>> g;

void go_check(int l, int r) {
	if (r - l <= 1) {
		return;
	}
	int mid = (l + r) >> 1;
	go_check(l, mid);
	go_check(mid, r);
	int i = l, j = mid;
	while (i < mid && j < r) {
		if (ptr >= s.size()) {
			ptr = s.size() + 1;
			return;
		}
		if (s[ptr++] == '0') {
			i++;
		} else {
			j++;
		}
	}
}

int check(int len) {
	ptr = 0;
	go_check(0, len);
	return ptr;
}

vector<int> restore(int l, int r) {
	if (r - l == 1) {
		return {l};
	}
	int mid = (l + r) >> 1;
	vector<int> vl = restore(l, mid);
	vector<int> vr = restore(mid, r);
	vector<int> res;
	int i = l, j = mid;
	while (i < mid && j < r) {
		if (s[ptr++] == '0') {
			res.push_back(vl[i - l]);
			i++;
		} else {
			res.push_back(vr[j - mid]);
			j++;
		}
	}
	while (i < mid) {
		res.push_back(vl[i - l]);
		i++;
	}
	while (j < r) {
		res.push_back(vr[j - mid]);
		j++;
	}
	return res;
}

signed main() {
	fast_io();
	cin >> s;
	int l = 1, r = 1e5;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid + 1) > s.size()) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	// cerr << "Optimal length: " << l << '\n';
	ptr = 0;
	vector<int> order = restore(0, l);
	vector<int> ans(l);
	for (int i = 0; i < l; ++i) {
		ans[order[i]] = i;
	}
	cout << l << '\n';
	for (int i = 0; i < l; ++i) {
		cout << ans[i] + 1 << ' ';
	}
	cout << '\n';
}