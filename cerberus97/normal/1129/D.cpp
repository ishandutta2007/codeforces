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

const int N = 1e5 + 10, SQ = sqrt(N) + 2, mod = 998244353;

int a[N], pos[N], prv[N], B;
ll dp[N], weight[N], ans;
int sum[SQ][N], offset[SQ];

void upd(int l, int r, int x, int k);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		prv[i] = pos[a[i]];
		pos[a[i]] = i;
	}
	B = min(SQ, n);
	dp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		int j = prv[i];
		sum[(i - 1) / B][0] += dp[i - 1];
		sum[(i - 1) / B][0] %= mod;
		ans += dp[i - 1];
		ans %= mod;
		upd(j + 1, i, 1, k);
		if (j != 0) {
			upd(prv[j] + 1, j, -1, k);
		}
		dp[i] = ans;
	}
	cout << dp[n] << endl;
}

void upd(int l, int r, int x, int k) {
	for (int i = 0; i * B + 1 <= r; ++i) {
		int bl = i * B + 1;
		int br = (i + 1) * B;
		if (l > br or bl > r) {
			continue;
		} else if (l <= bl and br <= r) {
			if (x == 1) {
				if (k >= offset[i]) {
					ans -= sum[i][k - offset[i]];
				}
			} else {
				if (k + 1 >= offset[i]) {
					ans += sum[i][k + 1 - offset[i]];
				}
			}
			ans = (ans + mod) % mod;
			offset[i] += x;
		} else {
			for (int j = bl; j <= br; ++j) {
				if (j < l or j > r) {
					continue;
				}
				if (x == 1 and weight[j] + offset[i] == k) {
					ans -= (dp[j - 1] - mod);
					ans %= mod;
				} else if (x == -1 and weight[j] + offset[i] == k + 1) {
					ans += dp[j - 1];
					ans %= mod;
				}
				sum[i][weight[j]] -= (dp[j - 1] - mod);
				sum[i][weight[j]] %= mod;
				weight[j] += x;
				sum[i][weight[j]] += dp[j - 1];
				sum[i][weight[j]] %= mod;
			}
		}
	}
}