#include <cstring>
#include <cstdio>

int n;
char s[1000020];
int f[1000020];

bool find( int l )
{
	int i, j = 0;
	for ( i = 1; i < n-1; i++ )
	{
		if ( s[i] == s[j] )
		{
			j++;
			if ( j == l ) return 1;
			continue;
		}
		if ( j > 0 )
		{
			j = f[j];
			i--;
			continue;
		}
	}
	return 0;
}

int main()
{
	int i, j;
	
	scanf( "%s", s );
	n = strlen( s );
	f[0] = 0;
	f[1] = 0;
	for ( i = 1; i < n; i++ )
	{
		j = i;
		f[i+1] = 0;
		while ( j > 0 )
		{
			if ( s[i] == s[f[j]] )
			{
				f[i+1] = f[j] + 1;
				break;
			}
			j = f[j];
		}
	}
	for ( i = f[n]; i > 0; i = f[i] )
	{
		if ( find( i ) )
		{
			for ( j = 0; j < i; j++ )
				printf( "%c", s[j] );
			printf( "\n" );
			return 0;
		}
	}
	printf( "Just a legend\n" );
	return 0;
}