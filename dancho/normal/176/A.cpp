#include <cstdio>
#include <cstring>

int n, m, k;

int buy[1024], sell[1024], cnt[1024];
int dp[128][128];

char nm[1024][1024];
int a[1024][1024], b[1024][1024], c[1024][1024];

int getDP( int pos, int left )
{
//	printf( "DP %d %d\n", pos, left );
	if ( left == 0 ) return 0;
	if ( pos == 0 ) return 0;
	
	if ( dp[pos][left] != -1 ) return dp[pos][left];
	int sol = 0;
	
	for (int i = 0; i <= cnt[pos] && i <= left; i++)
	{
		if ( getDP( pos-1, left-i ) + (sell[pos]-buy[pos])*i > sol )
			sol = getDP( pos-1, left-i ) + (sell[pos]-buy[pos])*i;
	}
	
//	printf( "DP %d %d %d\n", pos, left, sol );
	dp[pos][left] = sol;
	return dp[pos][left];
}

int main()
{
	int i, j, l;
	
	int ans;
	
	scanf( "%d %d %d", &n, &m, &k );
	
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%s", nm[i] );
		for ( j = 1; j <= m; j++ )
		{
			scanf( "%d %d %d", &a[i][j], &b[i][j], &c[i][j] );
		}
	}
	
	ans = 0;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			if ( i == j ) continue;
			memset( dp, -1, sizeof( dp ) );
			
			//i -> j
			for ( l = 1; l <= m; l++ )
			{
				buy[l] = a[i][l];
				sell[l] = b[j][l];
				cnt[l] = c[i][l];
			}
			
			if ( getDP( m, k ) > ans )
			{
//				printf( "%d %d %d\n", i, j, getDP( m, k ) );
				ans = getDP( m, k );
			}
		}
	}
	printf( "%d\n", ans );
	return 0;
}