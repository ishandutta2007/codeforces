#include <cstdio>
#include <cstring>

int n, k;
char rh[4][100020];
int s[4];

bool isv( char x )
{
	if ( x == 'a' || x == 'e' || x == 'o' || x == 'i' || x == 'u' )
		return 1;
	return 0;
}

bool R( char x[], char y[] )
{
	int lx = strlen( x ), ly = strlen( y );
	int i, j, b;
	b = k;
	i = lx;
	while ( b > 0 )
	{
		i--;
		if ( i < 0 ) return 0;
		if ( isv( x[i] ) )
			b--;
	}

	b = k;
	j = ly;
	while ( b > 0 )
	{
		j--;
		if ( j < 0 ) return 0;
		if ( isv( y[j] ) )
			b--;
	}
	for ( ; i < lx && j < ly; i++, j++ )
	{
		if ( x[i] != y[j] ) return 0;
	}
	if ( i != lx || j != ly ) return 0;
	return 1;
}

int main()
{
	int i;
	
	memset( s, 0, sizeof( s ) );
	
	scanf( "%d %d", &n, &k );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%s", rh[0] );
		scanf( "%s", rh[1] );
		scanf( "%s", rh[2] );
		scanf( "%s", rh[3] );
		if ( ( R( rh[0], rh[1] ) == 0 ) || ( R( rh[2], rh[3] ) == 0 ) )
		{
			s[0] = 1;
			s[3] = 1;
		}
		if ( ( R( rh[0], rh[2] ) == 0 ) || ( R( rh[1], rh[3] ) == 0 ) )
		{
			s[1] = 1;
			s[3] = 1;
		}
		if ( ( R( rh[0], rh[3] ) == 0 ) || ( R( rh[1], rh[2] ) == 0 ) )
		{
			s[2] = 1;
			s[3] = 1;
		}
	}
	
	if ( s[3] == 0 )
	{
		printf( "aaaa\n" );
	}
	else if ( s[0] == 0 )
	{
		printf( "aabb\n" );
	}
	else if ( s[1] == 0 )
	{
		printf( "abab\n" );
	}
	else if ( s[2] == 0 ) 
		printf( "abba\n" );
	else printf( "NO\n" );
	return 0;
}