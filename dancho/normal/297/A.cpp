#include <cstdio>
#include <cstring>

char a[1024], b[1024];
int a1, b1;

int main()
{
	scanf( "%s", a );
	scanf( "%s", b );
	
	int i, j, m, n;
	a1 = b1 = 0;
	
	n = strlen( a );
	m = strlen( b );
	for ( i = 0; i < n; i++ )
		if ( a[i] == '1' )
			a1++;
	
	for ( j = 0; j < m; j++ )
		if ( b[j] == '1' )
			b1++;
	
	if ( a1%2 == 1 ) a1++;
	if ( a1 < b1 )
		printf( "NO\n" );
	else printf( "YES\n" );
	return 0;
}