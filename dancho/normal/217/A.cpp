#include <cstdio>
#include <cstring>

int n;
int x[128], y[128];

int lc = 0;
int col[128];

void dfs( int v )
{
	for ( int i = 1; i <= n; i++ )
	{
		if ( col[i] != -1 ) continue;
		if ( x[i] == x[v] || y[i] == y[v] )
		{
			col[i] = col[v];
			dfs( i );
		}
	}
}

int main()
{
	int i;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d %d", &x[i], &y[i] );
	}
	
	memset( col, -1, sizeof( col ) );
	for ( i = 1; i <= n; i++ )
	{
		if ( col[i] == -1 )
		{
			lc++;
			col[i] = lc;
			dfs( i );
		}
	}
	
	printf( "%d\n", lc-1 );
	return 0;
}