#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[100020];
int b[100020];

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
		b[i] = a[i];
	}
	sort( b + 1, b + n + 1 );
	k = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( a[i] != b[i] ) k++;
	}
	if ( k <= 2 )
	{
		printf( "YES\n" );
	}
	else printf( "NO\n" );
	return 0;
}