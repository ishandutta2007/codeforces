#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[1<<17], us[1<<17];
vector<int> pd[1<<17];

int mx[1<<17];

int main()
{
	int i, j, k;
	int ans = 0;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
		scanf( "%d", &a[i] );
	
	if ( n == 1 )
	{
		printf( "%d\n", 1 );
		return 0;
	}
		
	memset( us, 0, sizeof( us ) );
	for ( i = 2; i <= a[n]; i++ )
	{
		if ( !us[i] )
		{
			for ( j = i; j <= a[n]; j += i )
			{
				us[j] = 1;
				pd[j].push_back( i );
			}
		}
	}
	
	a[0] = 0;
	for ( i = 1; i <= n; i++ )
	{
		k = 0;
		for ( j = 0; j < (int) pd[ a[i] ].size(); j++ )
		{
			k = max( k, mx[ pd[ a[i] ][j] ] + 1 );
		}
		ans = max( k, ans );

		for ( j = 0; j < (int) pd[ a[i] ].size(); j++ )
		{
			mx[ pd[ a[i] ][j] ] = max( k, mx[ pd[ a[i] ][j] ] );
		}
	}
	printf( "%d\n", ans );
	return 0;
}