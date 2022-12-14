#include <cstdio>
#include <cstring>

char s[1<<22], t[1<<22];

int a[2][2];

int sc[2], be[2];

int main()
{
	int i, n;
	scanf( "%d", &n );
	scanf( "%s", s );
	scanf( "%s", t );
	
	memset( a, 0, sizeof( a ) );
	memset( sc, 0, sizeof( sc ) );
	for ( i = 0; i < 2*n; i++ )
	{
		a[ s[i]-'0' ][ t[i]-'0' ]++;
		be[0] += s[i]-'0';
		be[1] += t[i]-'0';
	}
	
	for ( i = 0; i < 2*n; i++ )
	{
		if ( a[1][1] > 0 )
		{
			sc[i%2]++;
			a[1][1]--;
		}
		else if ( a[1][0] > 0 )
		{
			if ( i%2 == 0 )
				sc[i%2]++;
			a[1][0]--;
		}
		else if ( a[0][1] > 0 )
		{
			if ( i%2 == 1 )
				sc[i%2]++;
			a[0][1]--;
		}
	}
	
	if ( sc[0] > sc[1] )
		printf( "First\n" );
	else if ( sc[0] == sc[1] )
		printf( "Draw\n" );
	else printf( "Second\n" );
	return 0;
}