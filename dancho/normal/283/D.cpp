#include <cstdio>
#include <cstring>

int n;
long long a[5020];
long long b[5020];
int k2[5020];

int dp[5020];

int mx2( long long a, int p )
{
	int r = 0;
	while ( a % 2 == 0 )
	{
		a /= 2;
		r++;
	}
	b[p] = a;
	return r;
}

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%I64d", &a[i] );
		k2[i] = mx2( a[i], i);
	}
	
	int bsol = n-1;
	
	dp[1] = 0;
	for ( i = 2; i <= n; i++ )
	{
		dp[i] = i-1;
		for ( j = i-1; j > 0; j-- )
		{
			k = (i-j);
			if ( a[j] % b[i] == 0 )
			{
				if ( k2[i] >= k )
				{
					if ( k2[i] - k == k2[j] )
					{
						if ( dp[j] + k-1 < dp[i] )
							dp[i] = dp[j] + k-1;
					}
				}
				else
				{
					if ( dp[j] + k-1 < dp[i] )
						dp[i] = dp[j] + k-1;
				}
			}
		}
		if ( n-i + dp[i] < bsol )
			bsol = n-i + dp[i];
	}
	
	printf( "%d\n", bsol );
	return 0;
}