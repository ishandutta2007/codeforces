#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, a[5005], dp[5005], ndp[5005], cnt, comb[3005][3005];

void solve()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	if(a[n - 1] == a[n - 2]) {
		printf("0\n"); return;
	}
	cnt = 0;
	for(int i = n / 2; i >= 0; i --) dp[i] = 0;
	dp[0] = 1;
	rep(i, n - 1) {
		int j = i;
		while(j + 1 < n && a[j + 1] == a[j]) j ++;
		int l = j - i + 1; i = j;
		
		for(int j = n / 2; j >= 0; j --) if(dp[j]) {
			if(cnt >= 2 * j) dp[j + 1] = (dp[j + 1] + 1ULL * dp[j] * comb[cnt - 2 * j][l - 1]) % MOD;
			dp[j] = 1ULL * dp[j] * comb[cnt - max(2 * j - 1, 0)][l] % MOD;
		}
		cnt += l;
	}
	printf("%d\n", dp[n / 2]);
}

int main()
{
	comb[0][0] = 1;
	rep(i, 3000) rep(j, 3000) {
		comb[i + 1][j] = (comb[i + 1][j] + comb[i][j]) % MOD;
		comb[i][j + 1] = (comb[i][j + 1] + comb[i][j]) % MOD;
	}
	int T;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}