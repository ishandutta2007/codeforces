#include <cstdio>
#include <cstring>
#include <iostream>

const int mod = 1000000007;

long long com[1024][1024];

long long gcom( int n, int k )
{
	if ( k == 0 ) return 1;
	if ( n < k ) return 0;
	if ( n == 1 ) return 1;
	if ( com[n][k] != -1 ) return com[n][k];
	
	com[n][k] = gcom( n-1, k )+gcom( n-1, k-1 );
	if ( com[n][k] >= mod ) com[n][k] = com[n][k] % mod;
	return com[n][k];
}

int n;
int a[16];

long long dp[16][128];
long long ans, cur;

int main()
{
	memset( com, -1, sizeof( com ) );
	int i, j, k;
	
	scanf( "%d", &n );
	k = 0;
	for ( i = 0; i < 10; i++ )
	{
		scanf( "%d", &a[i] );
		k+= a[i];
	}
	ans = 0;

	for ( int fi = 1; fi <= 9; fi++ )
	{
		bool fl = 0;
		if ( a[fi] > 0 )
		{
			a[fi]--;
			fl = 1;
		}
		n--;
		memset( dp, 0, sizeof( dp ) );
		for ( i = a[0]; i <= n; i++ )
		{
			dp[0][i] = 1;
		}
		
		//printf( "FI %d\n", fi );
		cur = a[0];
		for ( i = 1; i <= 9; i++ )
		{
			cur += a[i];
			for ( j = cur; j <= n; j++ )
			{
				dp[i][j] = 0;
				for ( k = j-a[i]; k >= 0; k-- )
				{
					dp[i][j] = dp[i][j] + (dp[i-1][k]*gcom( j, j - k ) );
					if ( dp[i][j] >= mod ) dp[i][j] = dp[i][j] % mod;
				}
				if ( i == 9 )
				{
					ans = ans + dp[i][j];
					if ( ans >= mod ) ans = ans % mod;
				}
			}
		}
		n++;
		if ( fl )
			a[fi]++;
	}
	
	std::cout<<ans<<"\n";
	return 0;
}