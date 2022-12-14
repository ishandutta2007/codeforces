#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int mod = 1000000007;

long long com[1024][1024];

long long qpow( long long v, long long st )
{
	long long r = 1;
	while ( st )
	{
		if ( st&1 )
		{
			r = r * v;
			if ( r >= mod ) r %= mod;
		}
		v = v * v;
		if ( v >= mod ) v %= mod;
		st = st / 2;
	}
	return r;
}

long long gc( int n, int k )
{
	if ( com[n][k] != -1 ) return com[n][k];
	if ( n == k ) return 1;
	if ( n < k ) return 0;
	if ( k < 0 ) return 0;
	if ( k == 0 ) return 1;
	if ( n == 0 ) return 1;
	
	com[n][k] = gc( n-1, k ) + gc( n-1, k-1 );
	if ( com[n][k] >= mod ) com[n][k] %= mod;
	
	return com[n][k];
}

int n, k;
long long m;

long long dp[128][10020];

long long qp[128][128];

int main()
{
	cin >> n >> m >> k;
	
	int i, j, x;
	
	memset( dp, 0, sizeof( dp ) );
	memset( com, -1, sizeof( com ) );
	
	for ( i = 1; i <= n; i++ )
	{
		for ( x = 0; x <= n; x++ )
		{
			qp[i][x] = qpow( gc( n, x ), (m-i)/n+1 );
		}
	}
	
	dp[0][0] = 1;
	for ( i = 1; i <= n; i++ )
	{
		dp[i][0] = 1;
		for ( j = 1; j <= k; j++ )
		{
			dp[i][j] = 0;
			for ( x = 0; x <= n && x <= j; x++ )
			{
				dp[i][j] += dp[i-1][j-x] * qp[i][x];
				if ( dp[i][j] >= mod ) dp[i][j] %= mod;
			}
			
//			cout << "DP " << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	
	cout << dp[n][k] << endl;
	return 0;
}