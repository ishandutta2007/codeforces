/*

Code for problem E by cookiedoth
Generated 26 Mar 2019 at 08.21 P


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

const int mx = 2000;
const int add = mx / 2;
const int D = 10;
int a, used[mx][mx], digit[mx][mx];
pair<int, int> mv[mx][mx];

void bfs() {
	queue<pair<int, int> > q;
	q.push({0, 0});
	while (!q.empty()) {
		int carry = q.front().first, balance = q.front().second;
		//cerr << "<<<<<<<<<<<<<<<<< " << carry << " " << balance << endl;
		q.pop();
		int ok = 0;
		for (int x = 0; x < D; ++x) {
			if (carry == 0 && balance == 0 && x == 0) {
				continue;
			}
			int c2 = (carry + a * x) / D;
			int b2 = (balance + a * ((carry + a * x) % D) - x);
			int pos = b2 + add;
			if (pos >= 0 && pos < mx && c2 < mx && used[c2][pos] == 0) {
				digit[c2][pos] = x;
				used[c2][pos] = 1;
				q.push({c2, b2});
				mv[c2][pos] = {carry, balance + add};
				if (c2 == 0 && b2 == 0) {
					ok = 1;
					break;
				}
			}
		}
		if (ok) {
			break;
		}
	}
	if (used[0][add] == 0) {
		cout << -1 << endl;
	}
	else {
		int carry = 0, pos = add;
		vector<int> ans;
		while (true) {
			ans.push_back(digit[carry][pos]);
			int _carry = mv[carry][pos].first, _pos = mv[carry][pos].second;
			carry = _carry, pos = _pos;
			if (carry == 0 && pos == add) {
				break;
			}
		}
		int pos0 = 0;
		while (ans[pos0] == 0) {
			pos0++;
		}
		for (int i = pos0; i < ans.size(); ++i) {
			cout << ans[i];
		}
		cout << endl;
	}
}

signed main() {
	fast_io();
	cin >> a;
	bfs();
}