#include <cstdio>
#include <cstring>

int n, ln;
char x[128];
bool us[128][64][2][2];
int dp[128][64][2][2];

int max( int a, int b )
{
	if ( a > b ) return a;
	return b;
}

int min( int a, int b )
{
	if ( a < b ) return a;
	return b;
}

int ia( int v )
{
	if ( v < 0 ) return -v;
	return v;
}

int getDP( int p, int rn, int s, int di )
{
	if ( p >= ln )
	{
		if ( rn == 0 )
			return 0;
		return -(1<<29);
	}
	if ( us[p][rn][s][di] == 1 )
		return dp[p][rn][s][di];
	int i;
	int sol = -(1<<29);
	for ( i = 0; i <= rn; i++ )
	{
		if ( i%2 == 0 )
		{
			if ( x[p] == 'F' )
			{
				if ( s == di )
					sol = max( sol, getDP( p+1, rn-i, s, di ) +1 );
				else
					sol = max( sol, getDP( p+1, rn-i, s, di ) -1 );
			}
			else if ( x[p] == 'T' )
			{
				if ( s == di )
					sol = max( sol, getDP( p+1, rn-i, 1-s, di ) );
				else
					sol = max( sol, getDP( p+1, rn-i, 1-s, di ) );
			}
		}
		else
		{
			if ( x[p] == 'T' )
			{
				if ( s == di )
					sol = max( sol, getDP( p+1, rn-i, s, di ) +1 );
				else
					sol = max( sol, getDP( p+1, rn-i, s, di ) -1 );
			}
			else if ( x[p] == 'F' )
			{
				if ( s == di )
					sol = max( sol, getDP( p+1, rn-i, 1-s, di ) );
				else
					sol = max( sol, getDP( p+1, rn-i, 1-s, di ) );
			}
		}
	}
	dp[p][rn][s][di] = sol;
	us[p][rn][s][di] = 1;
	//printf( "DP %d %d %d %d _ %d\n", p, rn, s, di, sol );
	return dp[p][rn][s][di];
}

int main()
{
	scanf( "%s", x );
	ln = strlen( x );
	scanf( "%d", &n );
	memset( us, 0, sizeof( us ) );
	printf( "%d\n", max( getDP( 0, n, 0, 1 ), getDP( 0, n, 0, 0 ) ) );
	return 0;
}