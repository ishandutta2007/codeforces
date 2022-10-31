#include <bits/stdc++.h>

using namespace std;
const int MAXN = 2e3+5;
const int MOD = 998244353;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int digit(int x) {
	
	int ret = 0;
	while (x) x /= 10, ret ^= 1;
	return ret;
}
int dp[2][MAXN][11], ret[2][MAXN][11], n, p, m, a[MAXN];
vector<int> V0, V1;
int main() {
	
	//freopen("in.txt", "r", stdin);
	
	int ncase;
	for (scanf("%d", &ncase); ncase--; ) {
		
		scanf("%d", &n);
		V0.clear(); V1.clear();
		int tot = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			
			if (digit(a[i]) & 1) V1.push_back(a[i] % 11), tot += (a[i] % 11), tot %= 11;
			else V0.push_back(a[i] % 11);
		}
		int now = 0;
		for(int j = 0; j <= V1.size(); j++)
			for (int k = 0; k < 11; k++) dp[now][j][k] = 0;
		dp[now][0][0] = 1;
		for (int i = 0; i < V1.size(); i++) {
			for (int j = 0; j <= V1.size(); j++)
				for (int k = 0; k < 11; k++) dp[!now][j][k] = dp[now][j][k];	
			for (int j = 0; j <= i; j++)
				for (int k = 0; k < 11; k++) add(dp[!now][j + 1][(k + V1[i]) % 11], 1LL * dp[now][j][k] * (j + 1) % MOD);
				
			now ^= 1;
		}
		for (int i = 0; i <= V0.size(); i++)
			for (int j = 0; j < 11; j++) ret[now][i][j] = 0;
			
		int f = 1;
		for (int i = 1; i <= V1.size() / 2; i++) f = 1LL * f * i % MOD;
		for (int k = 0; k < 11; k++) add(ret[now][0][(2 * k + 11 - tot) % 11], 1LL * dp[now][(V1.size() + 1) / 2][k] * f % MOD);
		int p = (V1.size() + 2) / 2, m = V1.size() + 1 - p;
		for (int i = 0; i < V0.size(); i++) {
			for (int j = 0; j <= V0.size(); j++)
				for (int k = 0; k < 11; k++) ret[!now][j][k] = 0;
			for (int j = 0; j <= i; j++)
				for (int k = 0; k < 11; k++) {
					add(ret[!now][j + 1][(k + V0[i]) % 11], 1LL * ret[now][j][k] * (p + j) % MOD);
					add(ret[!now][j][(k + 11 - V0[i]) % 11], 1LL * ret[now][j][k] * (m + i - j) % MOD);
				}	
			now ^= 1;	
		}
		
		int ans = 0;
		for (int i = 0; i <= V0.size(); i++) add(ans, ret[now][i][0]);
		printf("%d\n", ans);
	}
	return 0;
}