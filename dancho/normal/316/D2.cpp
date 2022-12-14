#include <cstdio>
#include <cstring>

const long long mod = 1000000007;

long long qpow( long long v, long long st )
{
	long long r = 1;
	while ( st )
	{
		if ( st&1 )
		{
			r *= v;
			r %= mod;
		}
		v = v * v;
		v %= mod;
		st = st / 2;
	}
	return r;
}

long long f[1024];
long long dp[1024][1024];
long long sdp[1024][1024];

long long getDP( int,int );

long long getSdp( int b1, int b2 )
{
	if ( sdp[b1][b2] != -1 )
		return sdp[b1][b2];
	if ( b2 == 0 )
		return getDP( b1-2, 0 );
	sdp[b1][b2] = getSdp( b1, b2-1 ) + getDP( b1-2, b2 )*qpow( f[b2], mod-2 );
	sdp[b1][b2] %= mod;
	return sdp[b1][b2];
}

long long getDP( int b1, int b2 )
{
	if ( dp[b1][b2] != -1 )
		return dp[b1][b2];
	if ( !b1 )
		return f[b2];
	
	long long sol = 0;
	if ( b1 >= 2 )
	{
		long long p = getSdp( b1, b2 );
		p *= f[b2]; p%= mod; p *= (b1-1); p %= mod;
		sol += p;
		sol %= mod;
	}
	if ( b2 > 0 )
	{
		sol += getDP( b1, b2-1 )*b2;
		sol %= mod;
	}
	sol += getDP( b1-1, b2 );
	if ( sol >= mod )
		sol %= mod;
	dp[b1][b2] = sol;
	
	return dp[b1][b2];
}

int main()
{
	int i, j, k;
	f[0] = 1;
	for ( i = 1; i <= 1000; i++ )
	{
		f[i] = f[i-1]*i;
		f[i] %= mod;
	}
		
	j = k = 0;
	int n, l;
	scanf( "%d", &n );
	for ( i = 0; i < n; i++)
	{
		scanf( "%d", &l );
		if ( l == 1 )
			j++;
		else
			k++;
	}
	
	memset( dp, -1, sizeof( dp ) );
	memset( sdp, -1, sizeof( sdp ) );
	
	printf( "%d\n", (int) getDP( j, k ) );
	
	return 0;
}