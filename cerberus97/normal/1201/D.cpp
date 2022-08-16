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

const int N = 2e5 + 10;
const ll inf = 1e15 + 42;

int b[N];
int pos[N][2];
ll dp[N][2];

ll solve(int r, int pos, int t);

int main() {
	fast_cin();
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= n; ++i) {
		pos[i][0] = m + 1;
		pos[i][1] = 0;
	}
	for (int i = 1; i <= k; ++i) {
		int r, c;
		cin >> r >> c;
		pos[r][0] = min(pos[r][0], c);
		pos[r][1] = max(pos[r][1], c);
	}
	for (int i = 1; i <= q; ++i) {
		cin >> b[i];
	}
	sort(b + 1, b + 1 + q);
	if (pos[1][0] == m + 1) {
		pos[1][0] = pos[1][1] = 1;
	}
	dp[1][0] = solve(1, 1, 0);
	dp[1][1] = solve(1, 1, 1);
	for (int i = 1; i < n;) {
		int nr = i + 1;
		while (pos[nr][0] == m + 1 and nr <= n) {
			++nr;
		}
		if (nr > n) {
			n = i;
			break;
		}
		dp[nr][0] = dp[nr][1] = inf;
		for (int j = 0; j < 2; ++j) {
			int p = pos[i][j];
			ll cost = dp[i][j];
			int lt = upper_bound(b + 1, b + 1 + q, p) - b - 1;
			if (lt >= 1) {
				for (int t = 0; t < 2; ++t) {
					dp[nr][t] = min(dp[nr][t], cost + nr - i + (p - b[lt]) + solve(nr, b[lt], t));
				}
			}
			int rt = lower_bound(b + 1, b + 1 + q, p) - b;
			if (rt <= q) {
				for (int t = 0; t < 2; ++t) {
					dp[nr][t] = min(dp[nr][t], cost + nr - i + (b[rt] - p) + solve(nr, b[rt], t));
				}
			}
		}
		i = nr;
	}
	cout << min(dp[n][0], dp[n][1]) << endl;
}

ll solve(int r, int p, int t) {
	if (t == 0) {
		return abs(pos[r][1] - p) + (pos[r][1] - pos[r][0]);
	} else {
		return abs(pos[r][0] - p) + (pos[r][1] - pos[r][0]);
	}
}