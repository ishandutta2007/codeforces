/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 2012;
ld dp[N][N];
int n, t;
ld p;

ld ans(int i, int j) {
	if (i == 0 || j == 0)
		return 0;
	if (dp[i][j] != -1)
		return dp[i][j];
	return dp[i][j] = (p * (1 + (ans(i - 1, j - 1))) + ((1 - p) * ans(i, j - 1)));
}

int32_t main() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = -1;
		}
	}
	cin >> n >> p >> t;
	cout << fixed << setprecision(10);
	cout << ans(n, t);
}