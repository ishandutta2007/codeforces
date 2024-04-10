#include<bits/stdc++.h>
using namespace std;
char st[99];
int modulo(1e9 + 7);
int dp[77][1048599];
int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", st);
	for(int i(0); i < n; i++) {
		dp[i][0] = 1;
	}
	for(int i(0); i < n; i++) {
		int cur(0);
		
		for(int j(i); j < n; j++) {
			cur = cur * 2 + (st[j] - '0');
			if(cur == 0)
				continue;
			if(cur > 20) {
				break;
			}
			//cout << i << ' ' << j << ' ' << cur << endl;
			for(int msk(0); msk < (1 << 20); msk++) {
				if(dp[i][msk])
					(dp[j + 1][msk | (1 << cur - 1)] += dp[i][msk]) %= modulo;
			}
		}
	}
	int ans(0);
	for(int i(1); i <= n; i++) {
		for(int msk(1); msk < (1 << 20); msk = msk * 2 + 1)
			ans = (ans + dp[i][msk]) % modulo;
	}
	cout << ans << endl;
}