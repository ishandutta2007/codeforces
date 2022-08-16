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
 
const int N = 80 + 10, K = 15, IT = 3000, inf = 2e9 + 42;
 
int w[N][N], dp[K][N];
 
int main() {
	srand(time(0));
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> w[i][j];
		}
	}
	int best = inf, it = IT;
	while (it--) {
		vector<int> groups(n, 0);
		for (int i = 2; i <= n; ++i) {
			groups[i] = (rand() % 2);
		}
		for (int len = 0; len <= k; ++len) {
			for (int u = 1; u <= n; ++u) {
				dp[len][u] = inf;
			}
		}
		dp[0][1] = 0;
		for (int len = 0; len < k; ++len) {
			for (int u = 1; u <= n; ++u) {
				if (dp[len][u] == inf) {
					continue;
				}
				for (int v = 1; v <= n; ++v) {
					if (groups[u] != groups[v]) {
						dp[len + 1][v] = min(dp[len + 1][v], dp[len][u] + w[u][v]);
					}
				}
			}
		}
		best = min(best, dp[k][1]);
	}
	cout << best << endl;
}