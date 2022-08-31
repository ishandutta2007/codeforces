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

const int K = 1e3 + 10, mod = 1e9 + 7;

int dp[K];
ll choose[K][K];

int main() {
	fast_cin();
	dp[1] = 0;
	for (int i = 2; i < K; ++i) {
		dp[i] = 1 + dp[__builtin_popcount(i)];
		// cout << i << ' ' << dp[i] << endl;
	}
	for (int i = 0; i < K; ++i) {
		choose[i][i] = choose[i][0] = 1;
		for (int j = 1; j < i; ++j) {
			choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % mod;
		}
	}
	string n; int k;
	cin >> n >> k;
	int len = n.length();
	ll ans = (k == 0) - (k == 1);
	for (int i = 1; i <= len; ++i) {
		if (dp[i] == k - 1) {
			int cnt = 0;
			ans += (count(n.begin(), n.end(), '1') == i);
			for (int j = 0; j < len and cnt <= i; ++j) {
				if (n[j] == '1') {
					ans += choose[len - j - 1][i - cnt];
					ans %= mod;
					++cnt;
				}
			}
		}
	}
	cout << ans % mod << endl;
}