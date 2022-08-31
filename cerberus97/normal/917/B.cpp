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

const int N = 1e2 + 10, C = 30;

struct edge {
	int v, c;
};

bool seen[N][N][C], dp[N][N][C];
vector<edge> g[N];

bool solve(int i, int j, int c);

int main() {
	fast_cin();
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v; char c;
		cin >> u >> v >> c;
		g[u].pb({v, c - 'a'});
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if(solve(i, j, 0)) {
				cout << 'A';
			} else {
				cout << 'B';
			}
		}
		cout << '\n';
	}
}

bool solve(int i, int j, int c) {
	if (seen[i][j][c]) {
		return dp[i][j][c];
	} else {
		seen[i][j][c] = true;
		bool ans = false;
		for (auto &e : g[i]) {
			if (e.c >= c and !solve(j, e.v, e.c)) {
				ans = true;
				break;
			}
		}
		dp[i][j][c] = ans;
		return ans;
	}
}