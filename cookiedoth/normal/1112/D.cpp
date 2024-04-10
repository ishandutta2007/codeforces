#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <random>
#include <numeric>
#include <functional>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <iomanip>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(). a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream &out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T &x, ostream &out = cerr) {
	output(x.begin(), x.end(), out);
}

template<class T> int chkmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmax(T &a, const T &b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int mx = 5010;
string s;
int n, a, b, lcp[mx][mx], len[mx], dp[mx];

int main() {
	fast_io();
	cin >> n >> a >> b;
	cin >> s;

	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (s[i] == s[j]) {
				lcp[i][j] = lcp[i + 1][j + 1] + 1;
			}
		}
	}

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			int cur_len = min(lcp[i][j], i - j);
			chkmax(len[i], cur_len);
		}
	}

	dp[0] = a;
	for (int i = 1; i < n; ++i) {
		dp[i] = dp[i - 1] + a;
		for (int j = 1; j <= i; ++j) {
			if (len[j] >= i - j + 1) {
				chkmin(dp[i], dp[j - 1] + b);
			}
		}
	}
	cout << dp[n - 1] << endl;
}