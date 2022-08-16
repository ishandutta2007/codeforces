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

const int N = 3e5 + 10;

struct state_t {
	int val, l, r;
};

state_t dp[N][2][2];
int a[N], d[N];

state_t solve(int n, int m);

int main() {
	fast_cin();
	int n; string s;
	cin >> n >> s;
	if (count(s.begin(), s.end(), '(') * 2 != n) {
		cout << "0\n1 1\n";
		return 0;
	}
	int cur = 0, m = 0;
	for (int i = 0; i < n; ++i) {
		a[i] = (s[i] == '(' ? 1 : -1);
		cur += a[i];
		d[i] = cur;
		m = min(m, cur);
	}
	int ans = 0, l = 1, r = 1;
	for (int mval = m - 2; mval <= m + 2; ++mval) {
		auto res = solve(n, mval);
		if (res.val > ans) {
			ans = res.val;
			l = res.l + 1;
			r = res.r + 1;
		}
	}
	cout << ans << '\n' << l << ' ' << r << endl;
}

state_t solve(int n, int m) {
	for (int i = 0; i <= n; ++i) {
		for (int ca = 0; ca < 2; ++ca) {
			for (int cs = 0; cs < 2; ++cs) {
				dp[i][ca][cs] = {-1, 1, 1};
			}
		}
	}
	dp[0][0][0] = {0, 1, 1};
	for (int i = 0; i < n; ++i) {
		for (int ca = 0; ca < 2; ++ca) {
			for (int cs = 0; cs < 2; ++cs) {
				auto cur = dp[i][ca][cs];
				if (cur.val == -1) {
					continue;
				}
				int del = d[i] + (ca * 2) + (cs * -2);
				if (del >= m) {
					int nval = cur.val + (del == m);
					if (nval > dp[i + 1][ca][cs].val) {
						dp[i + 1][ca][cs] = cur;
						dp[i + 1][ca][cs].val = nval;
					}
				}
				if (a[i] == 1 and !cs and del - 2 >= m) {
					int nval = cur.val + (del - 2 == m);
					if (nval > dp[i + 1][ca][1].val) {
						dp[i + 1][ca][1] = cur;
						dp[i + 1][ca][1].val = nval;
						dp[i + 1][ca][1].r = i;
					}
				}
				if (a[i] == -1 and !ca) {
					int nval = cur.val;
					if (nval > dp[i + 1][1][cs].val) {
						dp[i + 1][1][cs] = cur;
						dp[i + 1][1][cs].l = i;
					}
				}
			}
		}
	}
	if (dp[n][0][0].val > dp[n][1][1].val) {
		return dp[n][0][0];
	} else {
		return dp[n][1][1];
	}
}