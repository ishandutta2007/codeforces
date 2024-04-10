/*

Code for problem B by cookiedoth
Generated 10 Oct 2020 at 05.56 PM


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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
#include <random>
#include <utility>
#include <tuple>
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

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int last_win = -1, score = 0, wins = 0;
	vector<int> segs;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'W') {
			score++;
			wins++;
			if (last_win != -1 && last_win + 1 == i) {
				score++;
			}
			if (last_win + 1 != i && last_win != -1) {
				segs.push_back(i - last_win - 1);
			}
			last_win = i;
		}
	}
	if (wins == 0) {
		cout << (k == 0 ? 0 : 2 * k - 1) << '\n';
		return;
	}
	sort(all(segs));
	int ans = score + 2 * min(n - wins, k);
	for (auto x : segs) {
		if (k >= x) {
			k -= x;
			ans++;
		}
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