/* 	* In the name of GOD 
 	* Thanks God */
#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 102, M = 12, MOD = 10000 * 10000;
int dp[N][N][2 * M];
int n1, n2, c, d;

int ans(int a, int b, int st) {
	if (dp[a][b][st] != -1)
		return dp[a][b][st];
	if (a == 0 && b == 0)
		return 1;
	int aa = 0;
	bool h = (st >= M);
	int x = st % M;
	if (((!h && x != c && a != 0) || (h && x != d && b != 0))) {
		aa += ans(a - (int)(!h), b - (int)(h), st + 1);
		aa %= MOD;
	}
	if ((!h && b != 0) || (h && a != 0)) {
		int sst = 0;
		if (!h)
			sst += M;
		sst += 1;
		aa += ans(a - (int)(h), b - (int)(!h), sst);
		aa %= MOD;
	}
	return dp[a][b][st] = aa;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n1 >> n2 >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int m = 0; m < 2 * M; m++) {
				dp[i][j][m] = -1;
			}
		}
	}
	cout << ans(n1, n2, 0);
}