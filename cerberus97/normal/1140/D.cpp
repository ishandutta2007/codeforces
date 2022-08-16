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

const int N = 510;
const ll inf = 1e18 + 42;

ll dp[N][N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int len = 3; len <= n; ++len) {
		for (int i = 1; i <= n; ++i) {
			int j = i + len - 1;
			if (j > n) {
				break;
			}
			dp[i][j] = inf;
			for (int k = i + 1; k < j; ++k) {
				ll cand = i * j * k + dp[i][k] + dp[k][j];
				dp[i][j] = min(dp[i][j], cand);
			}
		}
	}
	cout << dp[1][n] << endl;
}