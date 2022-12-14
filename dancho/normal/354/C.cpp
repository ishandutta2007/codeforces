#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int a[1<<20];

int main()
{
	scanf( "%d %d", &n, &k );
	for ( int i = 1; i <= n; ++i )
		scanf( "%d", &a[i] );
	sort( a + 1, a + n + 1 );
	
	a[n+1] = (1<<26);
	int d;
	for ( d = a[1]; d > 1; --d )
	{
		int i = 1;
		while ( i <= n )
		{
			int j = a[i]/d;
			int s = a[i]-k, p;
			if ( s <= 0 ) s = 1;
			if ( (p=j*d) < s )
				break;
			if ( p >= a[n+1] )
				p = a[n+1]-1;
			i = (int) ( upper_bound( a + 1, a + n + 1, p+k ) - a );
/*			while ( l+1 < r )
			{
				m = (l+r)/2;
				if ( a[m] <= p )
					l = m;
				else
					r = m;
			}
			i = r;*/
		}
		if ( i > n )
			break;
	}
	printf( "%d\n", d );
	return 0;
}