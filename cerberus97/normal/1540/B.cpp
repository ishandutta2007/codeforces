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

const int N = 200 + 10, mod = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int mul(ll a, int b) {
	return (a * b) % mod;
}

int pwr(int x, int e) {
	int res = 1;
	while (e) {
		if (e & 1) {
			res = mul(res, x);
		}
		e /= 2;
		x = mul(x, x);
	}
	return res;
}

int divd(int a, int b) {
	return mul(a, pwr(b, mod - 2));
}

vector<int> g[N];
int dp[N][N], dist[N][N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			dist[i][j] = dist[j][i] = n;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
		dist[u][v] = dist[v][u] = 1;
	}
	for (int i = 2; i <= n; ++i) {
		dp[i][i - 1] = 1;
		for (int j = 1; j < i - 1; ++j) {
			dp[i][j] = add(dp[i - 1][j - 1], dp[i - 1][j]);
			dp[i][j] = divd(dp[i][j], 2);
		}
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int d = dist[i][j], tmp = 0;
			for (int k = 1; k <= n; ++k) {
				int id = (dist[i][k] - dist[k][j] + d) / 2;
				tmp = add(tmp, dp[d + 1][id]);
			}
			ans = add(ans, divd(tmp, n));
		}
	}
	cout << ans << endl;
}