#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int a[100020];

int main()
{
	int i, j, k, q;
	
	q = (1<<29);
	scanf( "%d", &m );
	for ( i = 1; i <= m; i++ )
	{
		scanf( "%d", &k );
		if ( k < q )
			q = k;
	}
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &a[i] );
	
	sort( a + 1, a + n + 1 );
	int ans = 0;
	for ( i = n, j = 1; i > 0; i--, j++ )
	{
		if ( j > 0 )
			ans += a[i];
		if ( j == q )
			j = -2;
	}
	printf( "%d\n", ans );
	return 0;
}