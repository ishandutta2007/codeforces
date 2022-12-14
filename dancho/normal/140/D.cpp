#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[1024];

int main()
{
	int i, j, k, pt;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &a[i] );
	sort( a + 1, a + n + 1 );
	
	k = 0; j = 0; pt = 0;
	for ( i = 1; i <= n; i++ )
	{
		if ( k + a[i] <= 350+360 )
		{
			j++;
			k = k + a[i];
			pt = pt + max( k-350, 0 );
		}
	}
	printf( "%d %d\n", j, pt );
	return 0;
}