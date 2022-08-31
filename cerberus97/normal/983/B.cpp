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

const int N = 5e3 + 10;

int a[N];
int f[N][N], dp[N][N];

int main() {
	fast_cin();
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i][i] = a[i];
		dp[i][i] = a[i];
	}
	for (int len = 2; len <= n; ++len) {
		for (int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			f[i][j] = f[i][j - 1] xor f[i + 1][j];
			dp[i][j] = max(f[i][j], max(dp[i + 1][j], dp[i][j - 1]));
		}
	}
	int q; cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << dp[l][r] << '\n';
	}
}