#include <cstdio>
#include <cstring>

const int mod = 1000000007;

long long n;
int k;
char st[1024], en[1024];

long long dp[100020][2];

int main()
{
	int i, j;
	long long x;
	
	scanf( "%s", st );
	scanf( "%s", en );
	n = strlen( st );
	
	scanf( "%d", &k );
	
	dp[0][0] = 0;
	dp[0][1] = 0;
	
	x = 0;
	for ( i = 0; i < n; i++ )
	{
		for ( j = 0; j < n; j++ )
		{
			if ( st[ (i+j)%n ] != en[j] ) break;
		}
		if ( j >= n )
		{
			x++;
			if ( i == 0 )
				dp[0][1] = 1;
		}
	}
	
	if ( dp[0][1] == 0 ) dp[0][0] = 1;
	
	for ( i = 1; i <= k; i++ )
	{
		dp[i][0] = (long long)(n-1-x)*dp[i-1][0] + (long long)(n-x)*dp[i-1][1];
		if ( dp[i][0] >= mod ) dp[i][0] = dp[i][0] % mod;
		dp[i][1] = (long long) x*dp[i-1][0] + (long long)(x-1)*dp[i-1][1];
		if ( dp[i][1] >= mod ) dp[i][1] = dp[i][1] % mod;
	}
	
	printf( "%d\n", (int) dp[k][1] );
	return 0;
}