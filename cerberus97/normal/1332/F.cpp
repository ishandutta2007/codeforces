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

const int N = 3e5 + 10, mod = 998244353;

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}

int sub(int a, int b) {
	a -= b;
	if (a < 0) {
		a += mod;
	}
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
		x = mul(x, x);
		e /= 2;
	}
	return res;
}

vector<int> g[N];
int dp[N][3];

void solve(int, int);

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	solve(1, 0);
	int ans = sub(add(dp[1][0], dp[1][1]), 1);
	cout << ans << endl;
}

void solve(int u, int p) {
	for (auto& v : g[u]) {
		if (v == p) {
			swap(v, g[u].back());
			g[u].pop_back();
			break;
		}
	}
	int q1 = 1, q2 = 1, q3 = 1;
	for (auto& v : g[u]) {
		solve(v, u);
		q1 = mul(q1, add(add(mul(2, dp[v][0]), mul(2, dp[v][1])), dp[v][2]));
		q2 = mul(q2, add(mul(2, dp[v][0]), dp[v][1]));
		q3 = mul(q3, add(dp[v][0], dp[v][1]));
	}
	dp[u][0] = q1;
	dp[u][1] = sub(q2, q3);
	dp[u][2] = q3;
}