/*

Code for problem B by cookiedoth
Generated 31 Mar 2020 at 06.40 PM



10%

30%

50%

70%

100%

=_=
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

int is_prime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if (x % i == 0) {
			return 0;
		}
	}
	return 1;
}

const int M = 11;
const int mx = 1010;
int n, a[mx], clr[mx];
vector<int> primes;

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	fill(clr, clr + n, -1);
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < n; ++j) {
			if (clr[j] == -1 && a[j] % primes[i] == 0) {
				clr[j] = i;
			}
		}
	}
	vector<int> colors;
	for (int i = 0; i < n; ++i) {
		colors.push_back(clr[i]);
	}
	sort(all(colors));
	colors.erase(unique(all(colors)), colors.end());
	cout << colors.size() << "\n";
	for (int i = 0; i < n; ++i) {
		cout << lower_bound(all(colors), clr[i]) - colors.begin() + 1 << " ";
	}
	cout << "\n";
}

signed main() {
	fast_io();
	int val = 2;
	while (primes.size() < M) {
		if (is_prime(val)) {
			primes.push_back(val);
		}
		val++;
	}
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}