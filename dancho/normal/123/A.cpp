#include <cstdio>
#include <cstring>

int ln, lp, k;
char str[1024];
int b[32], sz[1024];
int pr[1024];

int par[1024];

int a[1024];

int ufind( int v )
{
	int i = 0, j;
	while ( par[v] != -1 )
	{
		a[++i] = v;
		v = par[v];
	}
	for ( j = 1; j <= i; j++ )
		par[a[j]] = v;
	return v;
}

bool isPr( int x )
{
	for ( int i = 2; i*i <= x; i++ )
	{
		if ( x % i == 0 ) return 0;
	}
	return 1;
}

int getfr()
{
	int i;
	for ( i = 0; i < 30; i++ )
	{
		if ( b[i] > 0 && i != k )
		{
			b[i]--;
			return i;
		}
	}
	b[k]--;
	return k;
}

int main()
{
	int i, j;
	k = 0;
	scanf( "%s", str );
	ln = strlen( str );
	
	memset( b, 0, sizeof( b ) );
	
	lp = 0;
	for ( i = 2; i <= ln; i++ )
	{
		if ( isPr( i ) == 1 )
			pr[++lp] = i;
	}
	
	memset( par, -1, sizeof( par ) );
	for ( i = 2; i <= ln; i++ )
	{
		for ( j = 1; j <= lp && pr[j] <= i; j++ )
		{
			if ( i%pr[j] == 0 )
			{
				if ( ufind( i ) != ufind( pr[j] ) )
					par[ufind( i )] = ufind( pr[j] );
			}
		}
	}
	
	for ( i = 0; i < ln; i++ )
	{
		b[str[i]-'a']++;
	}
	k = 0;
	for ( i = 0; i < 30; i++ )
	{
		if ( b[k] < b[i] ) k = i;
	}
	
	memset( sz, 0, sizeof( sz ) );
	for ( i = 1; i <= ln; i++ )
	{
		sz[ufind(i)]++;
	}
	j = 0;
	for ( i = 1; i <= ln; i++ )
	{
		if ( sz[j] < sz[i] ) j = i;
	}
	
	//printf( "%d %d\n", b[k], sz[j] );
	if ( b[k] < sz[j] )
	{
		printf( "NO\n" );
		return 0;
	}
	printf( "YES\n" );
	for ( i = 1; i <= ln; i++ )
	{
		if ( ufind( i ) == j )
		{
			printf( "%c", k+'a' );
			b[k]--;
		}
		else
		{
			printf( "%c", getfr()+'a' );
		}
	}
	printf( "\n" );
	return 0;
}