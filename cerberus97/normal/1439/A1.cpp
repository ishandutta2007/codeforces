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
#include <numeric>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10;

void apply(vector<string>& a, int r, int c, int x, int y, vector<vector<int>>& op);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for (auto& r : a) {
			cin >> r;
			for (auto& c : r) {
				c -= '0';
			}
		}
		vector<vector<int>> ops;
		for (int i = 0; i < n - 2; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j]) {
					int r = i, c = min(j, m - 2);
					apply(a, r, c, r, (a[r][c] ? c + 1 : c), ops);
				}
			}
		}
		int i = n - 2;
		for (int j = 0; j < m - 2; ++j) {
			if (a[i][j] and a[i + 1][j]) {
				apply(a, i, j, i, j + 1, ops);
			} else if (a[i][j]) {
				apply(a, i, j, i + 1, j, ops);
			} else if (a[i + 1][j]) {
				apply(a, i, j, i, j, ops);
			}
		}
		while (true) {
			int cnt = 0;
			vector<vector<pii>> tmp(2);
			for (int i = n - 2; i < n; ++i) {
				for (int j = m - 2; j < m; ++j) {
					cnt += a[i][j];
					tmp[a[i][j]].pb({i, j});
				}
			}
			if (cnt == 0) {
				break;
			} else if (cnt == 2 or cnt == 4) {
				apply(a, n - 2, m - 2, tmp[1][0].first, tmp[1][0].second, ops);
			} else {
				apply(a, n - 2, m - 2, tmp[0][0].first, tmp[0][0].second, ops);
			}
		}
		cout << ops.size() << '\n';
		for (auto& op : ops) {
			for (auto& x : op) {
				cout << x << ' ';
			}
			cout << '\n';
		}
	}
}

void apply(vector<string>& a, int r, int c, int x, int y, vector<vector<int>>& op) {
	op.pb({});
	for (int i = r; i < r + 2; ++i) {
		for (int j = c; j < c + 2; ++j) {
			if (i != x or j != y) {
				op.back().pb(i + 1);
				op.back().pb(j + 1);
				a[i][j] ^= 1;
			}
		}
	}
}