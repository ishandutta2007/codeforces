#include <cstdio>

int ia( int x )
{
	if ( x < 0 ) return -x;
	return x;
}

int main()
{
	int i, j, k, l, n, m;
	int hg, hr, he, ne = 0;
	int nor = 0, nog = 0;
	int cmg = 0, cmr = 0;
	int xr[16];
	char s[128];
	int az = 1;
	
	for ( j = 0; j < 10; j++ ) xr[j] = 0;
	
	scanf( "%d %d %d", &n, &m, &k );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%s", s );
		hg = -1;
		hr = -1;
		he = 0;
		for ( j = 0; j < m; j++ )
		{
			if ( s[j] == '-' ) he = 1;
			else if ( s[j] == 'R' )
			{
				hr = j;
				if ( (j-1>=0) && ( s[j-1] == '-' ) )
					cmr = 1;
				if ( (j+1<m) && (s[j+1] == '-' ) )
					cmr = 1;
			}
			else if ( s[j] == 'G' ) 
			{
				hg = j;
				if ( (j-1>=0) && ( s[j-1] == '-' ) )
					cmg = 1;
				if ( (j+1<m) && (s[j+1] == '-' ) )
					cmg = 1;
			}
		}
		if ( he == 1 ) ne = 1;
		if ( ( hr == -1 ) && ( he == 1 ) && ( hg != -1 ) )
		{
			nog = 1;
		}
		if ( ( hg == -1 ) && ( he == 1 ) && ( hr != -1 ) )
		{
			nor = 1;
		}
		if ( ( hg != -1 ) && ( hr != -1 ) )
		{
			l = ia(hg-hr)-1;
			for ( j = 0; j < 10; j++ )
			{
				xr[j] = (xr[j]+(bool)(l&(1<<j)))%(k+1);
			}
		}
	}
	
	for ( j = 0; j < 10; j++ ) if ( xr[j] != 0 ) az = 0;
//	if ( ( n == 12 ) && ( m == 21 ) && ( k == 1 ) )
//		printf( "%d %d ; %d ; %d %d ; %d\n", cmr, cmg, ne, nog, nor, az );
	if ( cmg == 0 )
	{
		printf( "Second\n" );
		return 0;
	}
	if ( cmr == 0 )
	{
		printf( "First\n" );
		return 0;
	}
	if ( ne == 0 )
	{
		printf( "Second\n" );
		return 0;
	}
	if ( ( nog == 1 ) && ( nor == 1 ) )
	{
		printf( "Draw\n" );
		return 0;
	}
	if ( az == 1 )
	{
		printf( "Second\n" );
	}
	else printf( "First\n" );
	return 0;
}