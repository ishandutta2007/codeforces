/*

Code for problem B by cookiedoth
Generated 25 May 2022 at 08.58 PM
The Moon is Waning Crescent (21% of Full)


 ] 
 
Il] 


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

int A, B, AB, BA;
string s;
int cA, cB;

void solve() {
	cin >> A >> B >> AB >> BA;
	cin >> s;
	cA = 0;
	cB = 0;
	for (auto c : s) {
		if (c == 'A') {
			cA++;
		} else {
			cB++;
		}
	}
	if (cA != AB + A + BA || cB != AB + B + BA) {
		cout << "NO\n";
		return;
	}
	int len = 0;
	char fl;
	vector<int> extraA, extraB;
	int got = 0;
	for (int i = 0; i <= s.size(); ++i) {
		if (i && (i == s.size() || s[i] == s[i - 1])) {
			got += (len - 1) / 2;
			if (len % 2 == 0) {
				if (fl == 'A') {
					extraA.push_back(len / 2);
				} else {
					extraB.push_back(len / 2);
				}
			}
			len = 0;
		}
		if (i == 0 || (i < s.size() && s[i] == s[i - 1])) {
			fl = s[i];
		}
		len++;
	}
	int need = max(0, AB + BA - got);
	sort(all(extraA));
	sort(all(extraB));
	int totA = 0, full = 0;
	for (auto x : extraA) {
		totA += x;
		if (totA <= AB) {
			full++;
		}
	}
	int totB = 0;
	for (auto x : extraB) {
		totB += x;
		if (totB <= BA) {
			full++;
		}
	}
	cout << (full >= need ? "YES" : "NO") << '\n';
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
}