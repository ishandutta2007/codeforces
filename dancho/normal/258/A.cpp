#include <cstdio>
#include <cstring>

char a[100020];

int main()
{
	int i, k, n;
	scanf( "%s", a );
	n = strlen( a );
	k = 0;
	for ( i = 0; i < n; i++ )
	{
		if ( a[i] == '0' && k == 0 )
			k = i;
	}
	for ( i = 0; i < n; i++ )
	{
		if ( i == k ) continue;
		printf( "%c", a[i] );
	}
	printf( "\n" );
	return 0;
}