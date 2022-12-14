#include <cstdio>
#include <cmath>
#include <cstring>

int n;
int x[2048], y[2048];

int main()
{
	int i, j, k, sm = 0;
	scanf( "%d %d", &n, &k );
	for ( i = 1; i <= n; i++ )
	{
		for ( j = i+1; j <= n; j++ )
			sm++;
		x[i] = i;
		y[i] = i*3001;
	}
	
	if ( sm <= k )
		printf( "no solution\n" );
	else
	{
		for ( i = 1; i <= n; i++ )
			printf( "%d %d\n", x[i], y[i] );
	}
	return 0;
}