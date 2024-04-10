/*

Code for problem D by savkinsd2089
Generated 08 Aug 2018 at 08.28 pm
The Moon is Waning Crescent (11% of Full)


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

\_()_/
^_^
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

const int max_k = 110;
const int max_n = 12;
const int max_sz = (1 << max_n);
int n, q, m, w[max_n], cnt[max_sz], dist[max_sz][max_sz], q_ans[max_sz][max_k];

int read_s() {
	string s;
	cin >> s;
	int val = 0;
	for (int j = 0; j < n; ++j) {
		val += (s[j] - '0') * (1 << j);
	}
	return val;
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q >> m;
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}
	for (int i = 0; i < q; ++i) {
		int val = read_s();
		cnt[val]++;
	}
	int sz = (1 << n);
	//cerr << "cnt" << endl;
	//output(cnt, cnt + sz);
	for (int i = 0; i < sz; ++i) {
		for (int j = i; j < sz; ++j) {
			for (int b = 0; b < n; ++b) {
				if (((i >> b) & 1) == ((j >> b) & 1)) {
					dist[i][j] += w[b];
				}
			}
			int D = min(dist[i][j], max_k - 1);
			q_ans[i][D] += cnt[j];
			if (i != j)
				q_ans[j][D] += cnt[i];
			//cerr << "add " << i << " " << j << " " << D << endl;
		}
	}
	/*cerr << "dist" << endl;
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j < sz; ++j) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 0; i < sz; ++i) {
		for (int j = 1; j < max_k; ++j) {
			q_ans[i][j] += q_ans[i][j - 1];
		}
	}
	for (int i = 0; i < m; ++i) {
		int val = read_s(), k;
		cin >> k;
		cout << q_ans[val][k] << '\n';
	}
}