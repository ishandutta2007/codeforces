#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1000000007;

int n, m;
char s[5020], t[5020];
long long ps[2][5020];
long long dp[2][5020];

void add( int k, int pos, int v )
{
	if ( k < 0 ) return;
	if ( pos < 0 ) return;
	k = k % 2;
	pos++;
	ps[k][pos] = ps[k][pos] + v;
}

long long que( int k, int pos )
{
	if ( k < 0 ) return 0;
	if ( pos < 0 ) return 0;
	k = k % 2;
	pos++;
	return ps[k][pos];
}

void init( int k )
{
	if ( k < 0 ) return;
	k = k % 2;
	ps[k][0] = 0;
	for ( int i = 1; i <= m; i++ )
	{
		ps[k][i] = ps[k][i-1] + ps[k][i];
		if ( ps[k][i] >= mod ) ps[k][i] = ps[k][i] % mod;
	}
}

int main()
{
	int i, j;
	long long ans = 0;
	
	scanf( "%s", s ); n = strlen( s );
	scanf( "%s", t ); m = strlen( t );
	
	memset( ps, 0, sizeof( ps ) );
	for ( i = 0; i < n; i++ )
	{
		memset( ps[i%2], 0, sizeof( ps[i%2] ) );
		init( i-1 );
		for ( j = 0; j < m; j++ )
		{
//			printf( "%d %d\n", i, j );
			if ( s[i] != t[j] ) continue;
			dp[i%2][j] = 1LL + que( i-1, j-1 );
			if ( dp[i%2][j] >= mod ) dp[i%2][j] = dp[i%2][j] % mod;
			add( i, j, dp[i%2][j] );
			ans = ans + dp[i%2][j];
			if ( ans >= mod ) ans = ans % mod;
			
		}
	}
	
	cout << ans << endl;
	
	return 0;
}