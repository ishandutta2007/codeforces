/*

Code for problem B by cookiedoth
Generated 19 Jan 2020 at 04.44 P


_____________
_____________
_____________
_____________ ______
_____________
_____________
___________ ________

>_<
o_O
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
#define y0 kukarek
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

ll x0, y0, ax, ay, bx, by, xs, ys, t;
vector<pair<ll, ll> > coords;

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

signed main() {
	fast_io();
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	cin >> xs >> ys >> t;
	while (true) {
		if ((x0 + y0) - (xs + ys) > t) {
			break;
		}
		coords.emplace_back(x0, y0);
		x0 = x0 * ax + bx;
		y0 = y0 * ay + by;
	}
	pair<ll, ll> S = {xs, ys};
	int ans = 0;
	for (int i = 0; i < coords.size(); ++i) {
		ll sum = dist(S, coords[i]);
		if (sum > t) {
			continue;
		}
		int cnt = 1, ok = 1;
		for (int j = i - 1; j >= 0; --j) {
			if (sum + dist(coords[j], coords[j + 1]) <= t) {
				sum += dist(coords[j], coords[j + 1]);
				cnt++;
			} else {
				ok = 0;
				break;
			}
		}
		chkmax(ans, cnt);
		if (ok) {
			int pos = 0;
			for (int j = i + 1; j < coords.size(); ++j) {
				if (sum + dist(coords[pos], coords[j]) <= t) {
					sum += dist(coords[pos], coords[j]);
					cnt++;
					pos = j;
				} else {
					break;
				}
			}
			chkmax(ans, cnt);
		}
	}
	cout << ans << endl;
}