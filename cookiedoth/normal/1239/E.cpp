/*

Code for problem K by cookiedoth
Generated 20 Oct 2019 at 05.24 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

-_-
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

const int INF = 1e9;
const int N = 26;
const int A = 5e4 + 10;
vector<int> value;
int p[N][A * N];

signed main() {
	fast_io();
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n; ++i) {
		int x;
		cin >> x;
		value.push_back(x);
	}
	sort(all(value));
	int sum = 0;
	for (int i = 2; i < 2 * n; ++i) {
		sum += value[i];
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < A * N; ++j) {
			p[i][j] = -1;
		}
	}
	p[0][0] = -2;
	for (int i = 2; i < value.size(); ++i) {
		int cur = value[i];
		//cerr << "update " << cur << endl;
		for (int j = n - 1; j > 0; --j) {
			for (int x = cur; x < A * N; ++x) {
				if (p[j - 1][x - cur] != -1 && p[j][x] == -1) {
					//cerr << "got " << j << " " << x << endl;
					p[j][x] = i;
				}
			}
		}
	}

	int best = INF;
	for (int i = 0; i < N * A; ++i) {
		if (abs(i - (sum - i)) < abs(best - (sum - best)) && p[n - 1][i] != -1) {
			best = i;
		}
	}
	vector<int> type(2 * n);
	type[1] = 1;
	for (int i = n - 1; i > 0; --i) {
		type[p[i][best]] = 1;
		best -= value[p[i][best]];
	}
	vector<vector<int> > ans(2);
	for (int i = 0; i < 2 * n; ++i) {
		ans[type[i]].push_back(value[i]);
	}
	sort(all(ans[0]));
	sort(ans[1].rbegin(), ans[1].rend());
	for (auto v : ans) {
		for (auto x : v) {
			cout << x << " ";
		}
		cout << endl;
	}
}