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

const int N = 3600 + 10, H = N / 2, mod = 998244353;

bool used_row[N], used_col[N];
ll dp_row[N][H], dp_col[N][H];
ll choose[N][N], fact[N];

void compute_dp(int h, bool* used, ll dp[][H]);
ll get_ways(int h, ll dp[][H], int unused, int a, int b);

int main() {
	fast_cin();
	int h, w, n;
	cin >> h >> w >> n;
	for (int i = 1; i <= n; ++i) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		used_row[r1] = used_row[r2] = true;
		used_col[c1] = used_col[c2] = true;
	}
	fact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = (i * fact[i - 1]) % mod;
	}
	for (int i = 0; i < N; ++i) {
		choose[i][0] = choose[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			choose[i][j] = choose[i - 1][j] + choose[i - 1][j - 1];
			choose[i][j] %= mod;
		}
	}
	int unused_rows = 0, unused_cols = 0;
	for (int i = 1; i <= h; ++i) {
		unused_rows += !used_row[i];
	}
	for (int i = 1; i <= w; ++i) {
		unused_cols += !used_col[i];
	}
	compute_dp(h, used_row, dp_row);
	compute_dp(w, used_col, dp_col);
	ll ans = 0;
	for (int a = 0; a <= h; ++a) {
		for (int b = 0; b <= h; ++b) {
			ll temp = get_ways(h, dp_row, unused_rows, a, b) * get_ways(w, dp_col, unused_cols, b, a);
			temp %= mod;
			temp *= fact[a];
			temp %= mod;
			temp *= fact[b];
			ans += temp;
			ans %= mod;
		}
	}
	cout << ans << endl;
}

void compute_dp(int h, bool* used, ll dp[][H]) {
	dp[0][0] = 1;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; 2 * j <= i; ++j) {
			dp[i + 1][j] += dp[i][j];
			dp[i + 1][j] %= mod;
			if (i + 2 <= h and !used[i + 1] and !used[i + 2]) {
				dp[i + 2][j + 1] += dp[i][j];
				dp[i + 2][j + 1] %= mod;
			}
		}
	}
}

ll get_ways(int h, ll dp[][H], int unused, int a, int b) {
	if (a + 2 * b > unused) {
		return 0;
	}
	ll ans = dp[h][b] * choose[unused - 2 * b][a];
	return ans % mod;
}