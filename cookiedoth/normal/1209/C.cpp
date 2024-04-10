/*

Code for problem C by cookiedoth
Generated 14 Sep 2019 at 04.21 P


 ] 
 
Il] 


o_O
-_-
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

void solve() {
	int n;
	string s;
	cin >> n;
	cin >> s;
	vector<pair<int, int> > vp;
	for (int i = 0; i < n; ++i) {
		vp.emplace_back(s[i] - '0', i);
	}
	sort(all(vp));
	int pos = -1, kek = 0;
	vector<int> ans(n);
	vector<int> v1, v2;
	for (int i = 0; i < n; ++i) {
		if (i && vp[i].first > vp[i - 1].first && kek == 1) {
			kek = 2;
		}
		if (vp[i].second > pos && kek <= 1) {
			ans[vp[i].second] = 1;
			pos = vp[i].second;
			v1.push_back(vp[i].second);
		}
		else {
			ans[vp[i].second] = 2;
			v2.push_back(vp[i].second);
			chkmax(kek, 1);
		}
	}
	sort(all(v1));
	sort(all(v2));
	vector<int> val;
	for (auto x : v1) {
		val.push_back(s[x] - '0');
	}
	for (auto x : v2) {
		val.push_back(s[x] - '0');
	}
	for (int i = 1; i < n; ++i) {
		if (val[i] < val[i - 1]) {
			cout << "-" << endl;
			return;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << ans[i];
	}
	cout << endl;
	//cout << "+" << endl;
}

signed main() {
	fast_io();
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		solve();
	}
}