#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
int a[10020], b[10020];

int parl[10024][512];
int parr[10024][512];

int par[1024];

int s[1<<17], ls;

int ufind( int v )
{
	ls = 0;
	while ( par[v] != -1 )
	{
		s[ls++] = v;
		v = par[v];
	}
	
	for (int i = 0; i < ls; i++)
	{
		par[ s[i] ] = v;
	}
	
	return v;
}

int ufindl( int p, int v )
{
	ls = 0;
	while ( parl[p][v] != -1 )
	{
		s[ls++] = v;
		v = parl[p][v];
	}
	
	for (int i = 0; i < ls; i++)
	{
		parl[p][ s[i] ] = v;
	}
	
	return v;
}

int ufindr( int p, int v )
{
	ls = 0;
	while ( parr[p][v] != -1 )
	{
		s[ls++] = v;
		v = parr[p][v];
	}
	
	for (int i = 0; i < ls; i++)
	{
		parr[p][ s[i] ] = v;
	}
	
	return v;
}

int main()
{
	int i, j, k;
	int l, r;
	
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d %d", &a[i], &b[i] );
	}
	
	memset( parl[0], -1, sizeof( parl[0] ) );
	memset( parr[m+1], -1, sizeof( parr[m+1] ) );
	
	for ( i = 1; i <= m; i++ )
	{
		memcpy( parl[i], parl[i-1], sizeof( parl[i] ) );
		if ( ufindl( i, a[i] ) != ufindl( i, b[i] ) )
		{
			parl[i][ ufindl( i, a[i] ) ] = ufindl( i, b[i] );
		}
	}

	for ( i = m; i > 0; i-- )
	{
		memcpy( parr[i], parr[i+1], sizeof( parr[i] ) );
		if ( ufindr( i, a[i] ) != ufindr( i, b[i] ) )
		{
			parr[i][ ufindr( i, a[i] ) ] = ufindr( i, b[i] );
		}
	}
	
	scanf( "%d", &k );
	for ( i = 1; i <= k; i++ )
	{
		scanf( "%d %d", &l, &r );
		
		for ( j = 1; j <= n; j++ )
		{
			par[j] = parl[l-1][j];
			par[j+n] = parr[r+1][j] + n;
			if ( parr[r+1][j] == -1 )
				par[j+n] = -1;
		}
		
		for ( j = 1; j <= n; j++ )
		{
			if ( ufind( j ) != ufind( j+n ) )
			{
				par[ ufind( j ) ] = ufind( j + n );
			}
		}
		
		int ans = 0;
		for ( j = 1; j <= n+n; j++ )
		{
			if ( par[j] == -1 )
				ans ++;
		}
		printf( "%d\n", ans );
	}
	return 0;
}