#include <cstdio>
#include <algorithm>
using namespace std;

int a[100020];

int main()
{
	int i, n;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
	}
	sort( a+1, a+n+1 );
	
	if ( a[n] == 1 )
	{
		for ( i = 1; i < n; i++ )
			printf( "1 " );
		printf( "2\n" );
	}
	else
	{
		printf( "%d", 1 );
		for ( i = 2; i <= n; i++ )
		{
			printf( " %d", a[i-1] );
		}
		printf( "\n" );
	}
	
	return 0;
}