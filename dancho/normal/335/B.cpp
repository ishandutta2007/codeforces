#include <cstdio>
#include <cstring>

int n;
char s[1<<20];

int la[50020][64];

int dp[50020][128];
int pr[50020][128];
char sol[1024];

int main()
{
	int i, j, k;
	int mlen = 0;
	int mj, mk;
	mj = mk = -1;
	scanf( "%s", s );
	n = strlen( s );
	
	memset( la, -1, sizeof( la ) );
	for ( i = 0; i < n; i++ )
	{
		if ( i )
			memcpy( la[i], la[i-1], sizeof( la[i] ) );
		la[i][ (int) s[i]-'a' ] = i;
	}

	memset( dp, -1, sizeof( dp ) );
	memset( pr, -1, sizeof( pr ) );
	for ( i = 0; i < n; i++ )
		dp[i][0] = n;
	
	dp[0][1] = la[ n-1 ][ (int) s[0]-'a' ];
	if ( dp[0][1] > 1 && 1*2 > mlen )
	{
		mlen = 1*2;
		mj = 0;
		mk = 1;
	}
	else if ( dp[0][1] != -1 && 1*2-1 > mlen )
	{
		mlen = 1*2-1;
		mj = 0;
		mk = 1;
	}
	for ( j = 1; j <= 50; j++ )
	{
		for ( i = 1, k = 0; i < n; i++ )
		{
			if ( dp[k][j-1] > 0 )
			{
				if ( la[ dp[k][j-1]-1 ][ (int) s[i]-'a' ] >= i )
				{
					dp[i][j] = la[ dp[k][j-1]-1 ][ (int) s[i]-'a' ];
					if ( dp[i][j] != -1 )
					{
						if ( dp[i][j] > i && j*2 > mlen)
						{
							mlen = j*2;
							mj = i;
							mk = j;
						}
						else if (j*2-1 > mlen)
						{
							mlen = j*2-1;
							mj = i;
							mk = j;
						}
					}
					pr[i][j] = k;
				}
			}
			//printf( "DP %d %d %d :: %d\n", i, j, dp[i][j], k );
			if ( dp[i][j-1] > dp[k][j-1] )
				k = i;
		}
	}
	
	i = (mlen-1)/2;
	sol[mlen] = '\0';
	if ( mlen % 2 )
	{
		sol[i] = s[mj];
		i--;
		mj = pr[mj][mk];
		mk--;
	}
	while ( mk > 0 )
	{
		sol[i] = sol[mlen-1-i] = s[mj];
		i--;
		mj = pr[mj][mk];
		mk--;
	}
	
	printf( "%s\n", sol );
	
	return 0;
}