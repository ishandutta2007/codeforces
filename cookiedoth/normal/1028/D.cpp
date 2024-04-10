/*

Code for problem D by savkinsd2089
Generated 27 Aug 2018 at 08.08 pm
The Moon is Waning Gibbous (99% of Full)










(@)(@)(@)(@)(@)

>_<
=_=
>_<

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
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
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)

#ifndef TESTING
	#define endl '\n'
#endif

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

const int MOD = 1e9 + 7;
const int INF = 1e9;
int n, flag, ans = 1;
set<int> buy, sell, middle;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int max_buy = -INF, min_sell = INF;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		string s;
		cin >> s >> x;
		if (flag)
			continue;
		if (s == "ADD") {
			if (x <= max_buy)
				buy.insert(x);
			if (x >= min_sell)
				sell.insert(x);
			if (x > max_buy && x < min_sell)
				middle.insert(x);
		}
		else {
			if (x < max_buy || x > min_sell) {
				cout << 0 << endl;
				flag = 1;
				continue;
			}
			if (x > max_buy && x < min_sell)
				ans = (ans + ans) % MOD;
			for (auto val : middle) {
				if (val < x)
					buy.insert(val);
				else
					sell.insert(val);
			}
			middle.clear();
			if (buy.find(x) != buy.end())
				buy.erase(x);
			else
				sell.erase(x);
			max_buy = -INF;
			min_sell = INF;
			if (!buy.empty())
				max_buy = (*prev(buy.end()));
			if (!sell.empty())
				min_sell = (*sell.begin());
		}
	}
	if (flag)
		return 0;
	ans = ((ll)ans * (ll)(middle.size() + 1)) % (ll)MOD;
	cout << ans << endl;
}