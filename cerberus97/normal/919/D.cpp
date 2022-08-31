/*
Cerberus97
Hanit Banga
*/

#include <iostream>
#include <iomanip>
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
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 3e5 + 10, C = 26, inf = 1e7;

vector <int> g[N];
char s[N];
int seen[N][C], dp[N][C];

int solve(int i, int j);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m >> (s + 1);
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		g[x].pb(y);
	}

	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < C; ++j) {
			if (!seen[i][j]) {
				ans = max(ans, solve(i, j));
			}
		}
	}

	if (ans >= inf) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}

int solve(int i, int j) {
	if (seen[i][j] == 2) {
		return dp[i][j];
	} else if (seen[i][j] == 1) {
		return inf;
	}

	seen[i][j] = 1;
	if (s[i] - 'a' == j) {
		dp[i][j] = 1;
	}

	int temp = 0;
	for (auto &u : g[i]) {
		temp = max(temp, solve(u, j));
	}

	dp[i][j] += temp;
	seen[i][j] = 2;
	return dp[i][j];
}