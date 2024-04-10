#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n;
char str[705];

int cnt[15];
int dp[15][705];

int main()
{
	str[0] = '0';
	scanf("%s", str + 1);
	n = strlen(str);
	int cur = n - 1;
	while(str[cur] == '9') str[cur --] = '0';
	str[cur] ++;
	rep(i, n) str[i] -= '0';
	
	rep(i, n) {
		rep(j, 10) for(int k = n; k >= 0; k --) {
			dp[j][k] = 1LL * dp[j][k] * j % MOD;
			if(k > 0) dp[j][k] = (dp[j][k] + 1LL * dp[j][k - 1] * (10 - j)) % MOD;
		}
		rep(j, 10) {
			dp[j][cnt[j]] = (dp[j][cnt[j]] + min(j, (int)str[i])) % MOD;
			dp[j][cnt[j] + 1] = (dp[j][cnt[j] + 1] + (int)str[i] - min(j, (int)str[i])) % MOD;
		}
		for(int j = 0; j <= str[i]; j ++) cnt[j] ++;
	}
	
	rep(i, 10) for(int j = n; j >= 0; j --) dp[i][j] = (dp[i][j] + dp[i][j + 1]) % MOD;
	
	int ans = 0;
	rep(i, 10) {
		int curt = i;
		rep1(j, n) {
			ans = (ans + 1LL * (dp[i][j] - dp[i + 1][j] + MOD) * curt) % MOD;
			curt = 10LL * curt % MOD;
		}
	}
	printf("%d\n", ans);
	return 0;
}