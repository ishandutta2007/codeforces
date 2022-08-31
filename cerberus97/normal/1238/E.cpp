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

const int N = 1e5 + 10, M = 20, S = (1 << M) + 10;
const ll inf = 1e15 + 42;

int g[M][M];
int out[S], to[S][M];
ll dp[S];

int main() {
	fast_cin();
	int n, m; string s;
	cin >> n >> m >> s;
	for (auto &c : s) {
		c -= 'a';
	}
	for (int i = 0; i < n - 1; ++i) {
		++g[s[i]][s[i + 1]];
		++g[s[i + 1]][s[i]];
	}
	for (int mask = 1; mask < (1 << m); ++mask) {
		dp[mask] = inf;
		int u = __builtin_ctz(mask);
		for (int i = 0; i < m; ++i) {
			to[mask][i] = to[mask ^ (1 << u)][i] + g[i][u];
			if (!(mask & (1 << i))) {
				out[mask] += to[mask][i];
			}
		}
	}
	for (int mask = 0; mask < (1 << m); ++mask) {
		for (int i = 0; i < m; ++i) {
			if (!(mask & (1 << i))) {
				ll cand = dp[mask] + out[mask | (1 << i)];
				dp[mask | (1 << i)] = min(dp[mask | (1 << i)], cand);
			}
		}
	}
	cout << dp[(1 << m) - 1] << endl;
}