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

const int N = 1e2 + 10, M = 1e6 + 10, inf = 1e9 + 42;

int dist[N][N];
int p[M], dp[M], back[M];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			char c; cin >> c;
			dist[i][j] = ((c == '1') ? 1 : inf);
		}
		dist[i][i] = 0;
	}
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
	int m; cin >> m;
	for (int i = 1; i <= m; ++i) {
		cin >> p[i];
	}
	dp[1] = 1;
	for (int i = 2; i <= m; ++i) {
		dp[i] = inf;
		for (int j = max(1, i - n - 10); j < i; ++j) {
			if (dist[p[j]][p[i]] == i - j and dp[j] + 1 < dp[i]) {
				dp[i] = dp[j] + 1;
				back[i] = j;
			}
		}
	}
	cout << dp[m] << '\n';
	int u = m;
	vector<int> path;
	while (u != 1) {
		path.pb(p[u]);
		u = back[u];
	}
	path.pb(p[1]);
	reverse(path.begin(), path.end());
	for (auto &u : path) {
		cout << u << ' ';
	}
	cout << endl;
}