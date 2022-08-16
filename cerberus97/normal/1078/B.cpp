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

const int N = 1e2 + 2, M = 1e4 + 2;

int a[N], ctr[N], dp[2][N][M];

void solve();

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ctr[a[i]]++;
	}
	sort(a + 1, a + 1 + n);
	solve();
	int best = 1;
	for (int l = 1; l <= n; ++l) {
		int sum = 0;
		for (int r = l; r <= n; ++r) {
			sum += a[r];
			if (a[r] != a[l]) {
				break;
			}
			if (dp[0][r - l + 1][sum] != 1) {
				continue;
			}
			int temp = r - l + 1;
			if (l == 1 and a[r + 1] == a[n]) {
				temp = n;
			}
			if (r == n and a[1] == a[l - 1]) {
				temp = n;
			}
			best = max(best, temp);
		}
	}
	cout << best << endl;
}

void solve() {
	dp[0][0][0] = 1;
	for (int i = 1; i <= 100; ++i) {
		memset(dp[i & 1], 0, sizeof(dp[i & 1]));
		for (int j = 0; j <= 100; ++j) {
			for (int k = 0; k < M; ++k) {
				int ans = 0;
				for (int t = 0; t <= j and t <= ctr[i]; ++t) {
					if (i * t > k) {
						break;
					}
					ans += dp[(i - 1) & 1][j - t][k - i * t];
					if (ans > 2) {
						break;
					}
				}
				if (ans > 2) {
					ans = 2;
				}
				dp[i & 1][j][k] = ans;
			}
		}
	}
}