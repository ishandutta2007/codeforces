#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;

int n, m;
int dp[100005];

int main()
{
	scanf("%d%d", &n, &m);
	dp[0] = 2;
	rep1(i, max(n, m)) dp[i] = (dp[i - 1] + (i >= 2 ? dp[i - 2] : 0)) % MOD;
	int ans = (dp[n] + dp[m] - 2) % MOD;
	ans = (ans + MOD) % MOD;
	printf("%d\n", ans);
	return 0;
}