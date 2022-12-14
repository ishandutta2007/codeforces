#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, k;

int a[1<<20];
int b[1<<20];

int main()
{
	int i, j, s, t;
	
	scanf( "%d %d %d", &n, &m, &k );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &a[i] );
	for ( i = 1; i <= m; i++ )
		scanf( "%d", &b[i] );
	
	sort( a + 1, a + n + 1 );
	sort( b + 1, b + m + 1 );
	
	s = t = 1;
	while ( s <= n )
	{
		while ( ( t <= m ) && ( a[s] > b[t] ) )
			t++;
		if ( t > m )
		{
			printf( "YES\n" );
			return 0;
		}
		s++;
		t++;
	}
	printf( "NO\n" );

	return 0;
}