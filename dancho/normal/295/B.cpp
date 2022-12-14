#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
long long di[512][512];
long long a[512][512];
int x[512];
int v[512];

long long sol[512];
bool us[512];

int main()
{
	int i, j, k;
	
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= n; j++ )
		{
			scanf( "%d", &k );
			a[i][j] = di[i][j] = k;
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &x[i] );
		v[ n+1-i ] = x[i];
	}
	
	memset( us, 0, sizeof( us ) );
	for ( k = 1; k <= n; k++ )
	{
		us[ v[k] ] = 1;
		for ( i = 1; i <= n; i++ )
		{
			for ( j = 1; j <= n; j++ )
			{
				if ( di[ v[i] ][ v[k] ] + di[ v[k] ][ v[j] ] < di[ v[i] ][ v[j] ] )
					di[ v[i] ][ v[j] ] = di[ v[i] ][ v[k] ] + di[ v[k] ][ v[j] ];
			}
		}
		sol[k] = 0;
		for ( i = 1; i <= n; i++ )
		{
			if ( !us[i] ) continue;
			for ( j = 1; j <= n; j++ )
			{
				if ( us[j] )
					sol[k] += di[i][j];
			}
		}
	}
	
	for ( i = n; i > 1; i-- )
		printf( "%I64d ", sol[i] );
	printf( "%I64d\n", sol[1] );
	return 0;
}