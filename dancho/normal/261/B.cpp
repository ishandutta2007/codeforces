#include <cstdio>
#include <cstring>

int n, p, a[64];
int bl;

int us[64][64][64];
long double dp[64][64][64];

long double f[64];

long double getDP( int sm, int nm, int la )
{
	if ( nm < 0 || sm < 0 ) return 0;
	if ( la == bl )
		return getDP( sm, nm, la+1 );
	if ( la > n )
	{
		if ( sm == 0 && nm == 0 )
			return 1;
		return 0;
	}
	if ( nm == 0 )
	{
		if ( sm == 0 )
			return 1;
		return 0;
	}
	if ( sm == 0 )
	{
		return 0;
	}
	if ( us[sm][nm][la] )
		return dp[sm][nm][la];
	us[sm][nm][la] = 1;
	dp[sm][nm][la] = getDP( sm-a[la], nm-1, la+1 ) + getDP( sm, nm, la+1 );
//	printf( "GET DP %d %d %d :: %Lf\n", sm, nm, la, dp[sm][nm][la] );
	return dp[sm][nm][la];
}

int main()
{
	int i, k;
	
	int sm = 0;
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%d", &a[i] );
		sm += a[i];
	}
	scanf( "%d", &p );
	if ( sm <= p )
	{
		printf( "%.6lf\n", (double) n );
		return 0;
	}
	
	f[0] = 1.0;
	for ( i = 1; i <= 50; i++ )
		f[i] = f[i-1] * (long double) i;
	
	long double all = f[n];
	long double good = 0;
	for ( bl = 1; bl <= n; bl++ )
	{
		memset( us, 0, sizeof( us ) );
		for ( k = 0; k < n; k++ )
		{
			//nm = k;
			for ( i = p-a[bl]+1; i <= p; i++ )
			{
				//sm = i;
//				printf( "OP %Lf (%Lf) : %d %d %d\n", (long double) k * getDP( i, k, 1 ) * f[k]*f[n-k-1], getDP( i, k, 1 ), bl, k, i );
				//if ( k == 1 ) return 0;
				good = good + (long double) k * getDP( i, k, 1 ) * f[k]*f[n-k-1];
			}
		}
	}
	
//	printf( "%Lf %Lf\n", good, all );
	double ans = good/all;
	printf( "%.6lf\n", ans );
	return 0;
}