/*

Code for problem B by cookiedoth
Generated 22 Jun 2019 at 02.46 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

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

int n, m;

signed main() {
	fast_io();
	cin >> n >> m;
	int ptr1 = 0, ptr2 = n - 1;
	vector<pair<int, int> > ans;
	while (ptr1 <= ptr2) {
		if (ptr1 == ptr2) {
			int p0 = 0, p1 = m - 1;
			while (p0 <= p1) {
				if (p0 == p1) {
					ans.emplace_back(ptr1, p0);
					break;
				}
				else {
					ans.emplace_back(ptr1, p0);
					ans.emplace_back(ptr1, p1);
					p0++;
					p1--;
				}
			}
			break;
		}
		for (int i = 0; i < m; ++i) {
			ans.emplace_back(ptr1, i);
			ans.emplace_back(ptr2, m - 1 - i);
		}
		ptr1++;
		ptr2--;
	}
	/*set<pair<int, int> > S;
	for (int i = 1; i < ans.size(); ++i) {
		int dx = ans[i].first - ans[i - 1].first;
		int dy = ans[i].second - ans[i - 1].second;
		if (S.find({dx, dy}) != S.end()) {
			assert(0);
		}
		S.insert({dx, dy});
	}*/
	for (auto pp : ans) {
		cout << pp.first + 1 << " " << pp.second + 1 << "\n";
	}
}