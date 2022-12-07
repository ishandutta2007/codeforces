#include<bits/stdc++.h>
using namespace std;
const int N(1111);
int a[N];
int go[N][11][133];
int dp[N][277], inf(1e9);
int main() {
	int n;
	int tot(0);
	scanf("%d", &n);
	for(int i(1); i <= n; i++) {
		scanf("%d", &a[i]);
		tot |= 1 << a[i];
	}
	int ans(__builtin_popcount(tot));
	for(int j(1); j <= 8; j++) {
		for(int l(1); l <= 126; l++) {
			go[n + 1][j][l] = n + 1;
		}
	}
	for(int i(n); i >= 1; i--) {
		memcpy(go[i], go[i + 1], sizeof(go[i + 1]));
		for(int l(1); l <= 126; l++) {
			go[i][a[i]][l] = go[i + 1][a[i]][l - 1];
		}
		go[i][a[i]][1] = i;
	}
//	cout << go[1][8][3] << endl;
	for(int len(1); len <= 125; len++) {
		for(int i(0); i <= n; i++) {
			for(int msk(0); msk < (1 << 8); msk++) {
				dp[i][msk] = -inf;
			}
		}
		dp[0][0] = 0;
		for(int i(0); i < n; i++) {
			for(int msk(0); msk < (1 << 8); msk++) {
				if(dp[i][msk] < 0) {
					continue;
				}
				dp[i + 1][msk] = max(dp[i + 1][msk], dp[i][msk]);
				if(0 == (1 & (msk >> (a[i + 1] - 1)))) {
					//printf("%d %d %d %d\n", i, msk, go[i + 1][a[i + 1]][len], msk | (1 << a[i + 1] - 1));
					dp[go[i + 1][a[i + 1]][len]][msk | (1 << a[i + 1] - 1)] = max(dp[go[i + 1][a[i + 1]][len]][msk | (1 << a[i + 1] - 1)], dp[i][msk]);
					dp[go[i + 1][a[i + 1]][len + 1]][msk | (1 << a[i + 1] - 1)] = max(dp[go[i + 1][a[i + 1]][len + 1]][msk | (1 << a[i + 1] - 1)], dp[i][msk] + 1);
					
				}
			}
		}
		for(int i(1); i <= n; i++) {
			ans = max(ans, dp[i][(1 << 8) - 1] + len * 8);
		}
	}
	printf("%d\n", ans);
}