#include <cstdio>
#include <cstring>

int min( int a, int b )
{
	if ( a < b ) return a;
	return b;
}

int n, m;
int a[5020];
double bs;

int dp[5020][5020];

int getDP( int x, int y )
{
	if ( x > n )
		return 0;
	if ( y > m )
		return n-x+1;
	if ( dp[x][y] != -1 )
		return dp[x][y];
	
	int sol = (1<<29);
	sol = min( sol, getDP( x+1, y ) + (a[x] != y) );
	sol = min( sol, getDP( x, y+1 ) );
	
	dp[x][y] = sol;
	return dp[x][y];
}

int main()
{
	int i, j, k;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %lf", &a[i], &bs );
	}
	
	memset( dp, -1, sizeof( dp ) );
	for ( i = 1; i <= n; i++ )
		for ( j = 1; j <= m; j++ )
			getDP( n-i+1,m-j+1 );
	printf( "%d\n", getDP( 1, 1 ) );
	return 0;
}