/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e6 + 10, A = 300;

// bool g[100][100];
ll ctr[A][A];
ll min_y[N], min_x[N];

int main() {
	fast_cin();
	string s, t;
	cin >> s >> t;
	ll n = s.size(), m = t.size();
	ll x = 0, y = 0;
	min_y[0] = 0;
	ll ans = n * m;
	while (true) {
		if (x == n - 1) {
			break;
		} else if (s[x] == t[y] and y == m - 1) {
			ans -= m * (n - (x + 1));
			n = x + 1;
			break;
		} else {
			if (s[x] == t[y]) {
				++y;
			}
			++x;
			min_y[x] = y;
			// g[x][y] = true;
			ans -= y;
		}
	}
	x = 0; y = 0;
	min_x[0] = 0;
	while (true) {
		if (y == m - 1) {
			break;
		} else if (t[y] == s[x] and x == n - 1) {
			ans -= n * (m - (y + 1));
			m = y + 1;
			break;
		} else {
			if (t[y] == s[x]) {
				++x;
			}
			++y;
			min_x[y] = x;
			// g[x][y] = true;
			ans -= x;
		}
	}

	// for (int i = n - 1; i >= 0; --i) {
	// 	for (int j = 0; j < m; ++j) {
	// 		if (g[i][j]) {
	// 			cout << '#';
	// 		} else {
	// 			cout << '.';
	// 		}
	// 	}
	// 	cout << endl;
	// }

	ll ly = 0, ry = 0;
	for (x = 0; x < n; ++x) {
		while (ly < min_y[x]) {
			if (ly) {
				--ctr[t[ly]][t[ly - 1]];
			}
			++ly;
		}
		while (ry < m - 1 and min_x[ry + 1] <= x) {
			++ry;
			++ctr[t[ry]][t[ry - 1]];
		}
		if (x and s[x] != s[x - 1]) {
			// cout << x << ' ' << ctr[s[x - 1]][s[x]] << endl;
			ans -= ctr[s[x - 1]][s[x]];
		}
	}
	cout << ans << endl;
}