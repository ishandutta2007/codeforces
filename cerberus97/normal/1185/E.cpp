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

const int N = 2e3 + 10;

char a[N][N];
vector<pair<pii, pii>> ans;

bool check(int n, int m, char s);

int main() {
	fast_cin();
	int t; cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			cin >> (a[i] + 1);
		}
		ans.clear();
		bool ok = true;
		for (char i = 'z'; i >= 'a'; --i) {
			if (!check(n, m, i)) {
				cout << "NO\n";
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << "YES\n" << ans.size() << '\n';
			reverse(ans.begin(), ans.end());
			for (auto &p : ans) {
				cout << p.first.first << ' ' << p.first.second << ' ';
				cout << p.second.first << ' ' << p.second.second << '\n';
			}
		}
	}
}

bool check(int n, int m, char s) {
	int ctr = 0;
	int r_min = n + 1, r_max = 0;
	int c_min = m + 1, c_max = 0;
	pii star = {0, 0};
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i][j] == s) {
				++ctr;
				r_min = min(r_min, i);
				r_max = max(r_max, i);
				c_min = min(c_min, j);
				c_max = max(c_max, j);
			} else if (a[i][j] == '*') {
				star = {i, j};
			}
		}
	}
	if (ctr == 0) {
		if (star.first) {
			ans.pb({star, star});
		}
		return true;
	} else if (r_min < r_max and c_min < c_max) {
		return false;
	} else if (r_min == r_max) {
		int i = r_min;
		for (int j = c_min; j <= c_max; ++j) {
			if (a[i][j] != s and a[i][j] != '*') {
				return false;
			} else {
				a[i][j] = '*';
			}
		}
	} else {
		int j = c_min;
		for (int i = r_min; i <= r_max; ++i) {
			if (a[i][j] != s and a[i][j] != '*') {
				return false;
			} else {
				a[i][j] = '*';
			}
		}
	}
	ans.pb({{r_min, c_min}, {r_max, c_max}});
	return true;
}