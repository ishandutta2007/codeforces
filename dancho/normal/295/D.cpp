#include <cstdio>
#include <cstring>

const int mod = 1000000007;

long long g[2048][2048];
long long sg[2048][2048];
long long sgk[2048][2048];
long long qq[2048][2048];

int n, m;

int main()
{
	int i, j;
	long long ans = 0;
	scanf( "%d %d", &n, &m );
	
	memset( g, 0, sizeof( g ) );
	memset( sg, 0, sizeof( sg ) );
	memset( sgk, 0, sizeof( sgk ) );
	
	for ( i = 1; i <= n; i++ )
	{
		g[i][1] = 0;
		sg[i][1] = 0;
		sgk[i][1] = 0;
		for ( j = 2; j <= m; j++ )
		{
			g[i][j] = 1LL + sg[i-1][j] * (j+1);
			if ( g[i][j] >= mod ) g[j][i] %= mod;
			g[i][j] = g[i][j] + mod - sgk[i-1][j];
			if ( g[i][j] >= mod ) g[i][j] %= mod;
			
			sg[i][j] = sg[i][j-1] + g[i][j];
			if ( sg[i][j] >= mod ) sg[i][j] %= mod;
			sgk[i][j] = sgk[i][j-1] + g[i][j]*j;
			if ( sgk[i][j] >= mod ) sgk[i][j] %= mod;
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		qq[i][1] = 1;
		for ( j = 2; j <= m; j++ )
		{
			qq[i][j] = 1LL + sg[i-1][j-1]*(j+1);
			if ( qq[i][j] >= mod )
				qq[i][j] %= mod;
			qq[i][j] = qq[i][j] + mod - sgk[i-1][j-1];
			if ( qq[i][j] >= mod )
				qq[i][j] %= mod;
//			qq[i][j] = qq[i][j-1] + g[i-1][j-1];
		}
	}
	
	for ( i = 1; i <= n; i++ )
	{
		for ( j = 2; j <= m; j++ )
		{
			long long p = qq[i][j] * g[n-i+1][j];
			if ( p >= mod )
				p %= mod;
			p *= (m-j+1);
			ans += p;
			if ( ans >= mod )
				ans %= mod;
		}
	}
	printf( "%d\n", (int) ans );
	return 0;
}