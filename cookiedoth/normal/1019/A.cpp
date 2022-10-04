/*

Code for problem A by savkinsd2089
Generated 11 Aug 2018 at 04.28 pm
The Moon is New










(@)(@)(@)(@)(@)

>_<
o_O
-_-

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

const int mx = 3228;
int n, m, cnt[mx];
vector<vector<int> > prices;
const ll INF = 1e18;

ll get(int aim) {
	//cerr << "get " << aim << endl;
	int cur_cnt = cnt[0];
	ll res = 0;
	vector<int> cur_prices;
	for (int i = 1; i < m; ++i) {
		//cerr << "i = " << i << endl;
		int buy = max((int)prices[i].size() - aim + 1, 0);
		//cerr << "buy = " << buy << endl;
		//cerr << prices[i].size() << endl;
		for (int j = 0; j < buy; ++j) {
			res += (ll)prices[i][j];
		}
		//cerr << "res = " << res << endl;
		cur_cnt += buy;
		for (int j = buy; j < prices[i].size(); ++j) {
			cur_prices.push_back(prices[i][j]);
		}
	}
	sort(cur_prices.begin(), cur_prices.end());
	//output(cur_prices);
	for (int i = 0; i < aim - cur_cnt; ++i) {
		res += (ll)cur_prices[i];
	}
	return res;
}

signed main() {
	cin >> n >> m;
	prices.resize(m);
	for (int i = 0; i < n; ++i) {
		int p, cost;
		cin >> p >> cost;
		p--;
		cnt[p]++;
		prices[p].push_back(cost);
	}
	for (int i = 0; i < m; ++i) {
		sort(prices[i].begin(), prices[i].end());
	}
	ll ans = INF;
	for (int i = max(cnt[0], 1); i <= n; ++i) {
		ans = min(ans, get(i));
	}
	cout << ans << endl;
}