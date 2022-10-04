#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <algorithm>
#include <cstring>
#include <cassert>
#include <cmath>
#include <queue>
#include <deque>
#include <numeric>
#include <random>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

using namespace std;

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(const T &x, ostream &out = cerr) {
	output(all(x), out);
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

string s;
int n;

signed main() {
	fast_io();
	cin >> n;
	cin >> s;
	for (char c = 'z'; c >= 'b'; --c) {
		while (true) {
			int ok = 0;
			for (int i = 0; i < s.size(); ++i) {
				if (s[i] == c && ((i > 0 && s[i - 1] == c - 1) || (i < (int)s.size() - 1 && s[i + 1] == c - 1))) {
					s.erase(s.begin() + i);
					ok = 1;
					break;
				}
			}
			if (!ok) {
				break;
			}
		}
	}
	cout << n - s.size() << endl;
}