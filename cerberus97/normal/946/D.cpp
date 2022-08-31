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

const int N = 5e2 + 10, inf = 1e9;

vector<int> a[N];
int f[N][N], dp[N][N];

void pre(int i, int k);

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '1') {
				a[i].pb(j);
			}
		}
		pre(i, k);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			dp[i][j] = inf;
			for (int l = 0; l <= j; ++l) {
				dp[i][j] = min(dp[i][j], f[i][l] + dp[i - 1][j - l]);
			}
		}
	}
	cout << dp[n][k];
}

void pre(int i, int k) {
	int n = a[i].size();
	for (int j = 0; j <= k; ++j) {
		if (j >= n) {
			break;
		} else {
			f[i][j] = inf;
			int l = 0, r = n - 1 - j;
			while (r < n) {
				f[i][j] = min(f[i][j], a[i][r] - a[i][l] + 1);
				++l; ++r;
			}
		}
	}
}