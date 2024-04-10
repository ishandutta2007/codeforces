#include<stdio.h>

#define MIN(A, B) ((A)<(B)?(A):(B))

char s[55];
int n;
int dp[55];

int DP(int at)
{
	if(at==n+1) return 0;

	if(dp[at] != 1000000) return dp[at];

	int i;
	for(i = at+1;i<=n+1;i++)
		if(s[i]!=s[at])
		{
			dp[at] = MIN(dp[at], DP(i)+i-at-1);
		}

	return dp[at];
}

int main()
{
	int ans, i;

	scanf("%d%s", &n, s+1);

	s[0] = 'x';

	for(i = 0; i <= n; i++)
		dp[i] = 1000000;

	ans = DP(0);

	printf("%d\n", ans);

	return 0;
}