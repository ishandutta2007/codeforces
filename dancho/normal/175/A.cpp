#include <cstdio>
#include <cstring>

int n;
long long dp[1024][4];
char s[1024];

long long getDP( int p, int c )
{
	if ( p >= n )
	{
		return -(1LL<<40);
	}
	if ( c > 2 ) return -(1LL<<40);
	if ( dp[p][c] != -1 ) return dp[p][c];

	long long x = 0;
	long long ms = -(1LL<<40);
	if ( c == 2 )
	{
		x = 0;
		if ( ( s[p] == '0' ) && ( p+1 < n ) )
		{
			dp[p][c] = -(1LL<<40);
			return dp[p][c];
		}
		for ( int i = p; i < n; i++ )
		{
			x = x * 10 + (s[i]-'0');
			if ( x > 1000000 ) break;
		}
		if ( x <= 1000000 )
		{
			dp[p][c] = x;
		}
		else 
		{
			dp[p][c] = -(1LL<<40);
		}
		return dp[p][c];
	}
	
	if ( s[p] == '0' )
	{
		x = 0;
		dp[p][c] = getDP( p+1, c+1 );
		return dp[p][c];
	}
	
	for ( int i = p; i < n; i++ )
	{
		x = x * 10 + (s[i] - '0');
		if ( x <= 1000000 )
		{
		if ( ms < x + getDP( i+1, c+1 ) )
			ms = x + getDP( i+1, c+1 );
		}
		else break;
	}
	
	dp[p][c] = ms;
	return dp[p][c];
}

int main()
{
	long long k;
	
	scanf( "%s", s );
	n = strlen( s );
	
	memset( dp, -1, sizeof( dp ) );
	
	k = getDP( 0, 0 );
	if ( k >= 0 )
		printf( "%d\n", (int)getDP( 0, 0 ) );
	else printf( "-1\n" );
	return 0;
}