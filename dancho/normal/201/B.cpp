#include <cstdio>
#include <cstring>
#include <iostream>

const long double eps = 1e-11;

int n, m;
int c[1024][1024];

long double sr, sx, sy;

int main()
{
	int i, j;
	
	sr = sx = sy = 0;
	scanf( "%d %d", &n, &m );
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			scanf( "%d", &c[i][j] );
			sr += c[i][j];
			sx += ((double)c[i][j]*(2+(i-1)*4));
			sy += ((double)c[i][j]*(2+(j-1)*4));
		}
	}
	
	long double xx, yy;
	xx = sx/sr;
	yy = sy/sr;
	
	int x, y;
	if ( sx > 0 )
		x = (int) (xx/4.0 + 0.5-eps);
	else x = 0;
	if ( sy > 0 )
		y = (int) (yy/4.0 + 0.5-eps);
	else y = 0;
	
	long long ans = 0;
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 1; j <= m; j++ )
		{
			ans = ans + (long long)c[i][j]*(long long)( (long long)(2+(i-1)*4-4*x)*(long long)(2+(i-1)*4-4*x) + (long long)(2+(j-1)*4-4*y)*(long long)(2+(j-1)*4-4*y) );
		}
	}
	
	std::cout << ans << "\n";
	printf( "%d %d\n", x, y );
	return 0;
}