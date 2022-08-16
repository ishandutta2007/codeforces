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

const int N = 1e3 + 10, mod = 998244353;

ll a[N], choose[N][N], dp[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		choose[i][0] = choose[i][i] = 1;
		for (int j = 1; j < i; ++j) {	
			choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % mod;
		}
	}
	dp[n + 1] = 1;
	for (int i = n; i >= 1; --i) {
		if (a[i] > 0) {
			for (int j = a[i] + i; j <= n; ++j) {
				dp[i] += choose[j - i - 1][a[i] - 1] * dp[j + 1];
				dp[i] %= mod;
			}
		}
		dp[i] = (dp[i] + dp[i + 1]) % mod;
	}
	cout << dp[1] - 1;
}