#include <cstdio>
#include <cstring>

int n, m;
int nes[200020][27], net[200020][27];
int prs[200020][27], prt[200020][27];
int left[200020], ri[200020];

char s[200020];
char t[200020];

int main()
{
	int i, j, k;
	scanf( "%s", s+1 );
	scanf( "%s", t+1 );
	
	n = strlen( s+1 );
	m = strlen( t+1 );
	
	memset( prs, -1, sizeof( prs ) );
	for ( i = 2; i <= n+1; i++ )
	{
		for ( j = 0; j < 26; j++ )
		{
			prs[i][j] = prs[i-1][j];
		}
		prs[i][ s[i-1]-'a' ] = i-1;
	}

	memset( prt, -1, sizeof( prt ) );
	for ( i = 2; i <= m+1; i++ )
	{
		for ( j = 0; j < 26; j++ )
		{
			prt[i][j] = prt[i-1][j];
		}
		prt[i][ t[i-1]-'a' ] = i-1;
	}

	memset( nes, 63, sizeof( nes ) );
	for ( i = n-1; i >= 0; i-- )
	{
		for ( j = 0; j < 26; j++ )
		{
			nes[i][j] = nes[i+1][j];
		}
		nes[i][ s[i+1]-'a' ] = i+1;
	}

	memset( net, 63, sizeof( net ) );
	for ( i = m-1; i >= 0; i-- )
	{
		for ( j = 0; j < 26; j++ )
		{
			net[i][j] = net[i+1][j];
		}
		net[i][ t[i+1]-'a' ] = i+1;
	}
	
	memset( left, 63, sizeof( left ) );
	for ( i = n; i > 0; --i )
	{
		//koe e left[i] ?
		left[i] = m+1;
		if ( nes[i][ s[i]-'a' ] != nes[n+2][0] )
			left[i] = left[ nes[i][s[i]-'a'] ];
		for ( j = prt[left[i]][s[i]-'a']; j > 0; j = prt[j][ s[i]-'a' ] )
		{
			if ( t[j] == s[i] )
			{
				if ( j+1 <= m )
				{
					k = nes[i][ t[j+1]-'a' ];
					if ( k != nes[n+2][0] )
					{
						if ( left[k] > j+1 )
						{
							break;
						}
					}
					else break;
				}
				left[i] = j;
			}
			else break;
		}
	}

	memset( ri, -1, sizeof( ri ) );
	for ( i = 1; i <= n; ++i )
	{
		//koe e ri[i] ?
		ri[i] = 0;
		if ( prs[i][ s[i]-'a' ] != prs[n+2][0] )
		{
			ri[i] = ri[ prs[i][s[i]-'a'] ];
		}
		for ( j = net[ ri[i] ][ s[i]-'a' ]; j <= m; j = net[j][ s[i]-'a' ] )
		{
			if ( t[j] == s[i] )
			{
				if ( j-1 > 0 )
				{
					k = prs[i][ t[j-1]-'a' ];
					if ( k != prs[n+2][0] )
					{
						if ( ri[k] < j-1 )
						{
							break;
						}
					}
					else break;
				}
				ri[i] = j;
			}
			else break;
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		if ( left[i] > ri[i] )
		{
			printf( "No\n" );
			return 0;
		}
	}
	printf( "Yes\n" );
	return 0;
}