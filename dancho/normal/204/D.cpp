#include <cstdio>
#include <cstring>
#include <iostream>

const int mod = 1000000007;

long long qpow( long long v, long long st )
{
	long long r = 1;
	while ( st > 0 )
	{
		if ( st % 2 == 1 )
		{
			r = r * v;
			if ( r >= mod ) r = r % mod;
		}
		v = v * v;
		if ( v >= mod ) v = v % mod;
		st = st / 2;
	}
	return r;
}

int n, k;
char s[1000020];

long long g[1000020], sg[1000020];
long long ri[1000020], sri[1000020];
long long dinv;

int sb[1000020], sw[1000020], sx[1000020];

void init()
{
	sb[0] = sw[0] = sx[0] = 0;
	if ( s[0] == 'W' ) sw[0]++;
	if ( s[0] == 'B' ) sb[0]++;
	if ( s[0] == 'X' ) sx[0]++;
	for (int i = 1; i < n; i++)
	{
		sb[i] = sb[i-1];
		sw[i] = sw[i-1];
		sx[i] = sx[i-1];
		if ( s[i] == 'B' ) sb[i]++;
		else if ( s[i] == 'W' ) sw[i]++;
		else if ( s[i] == 'X' ) sx[i]++;
	}
}

bool canPutBBlock( int l, int r )
{
	if ( l > 0 )
	{
		if ( sw[r]-sw[l-1] == 0 ) return 1;
		return 0;
	}
	else return (sw[r] == 0);
}

bool canPutWBlock( int l, int r )
{
	if ( l > 0 )
	{
		return ( sb[r]-sb[l-1] == 0 );
	}
	else return (sb[r] == 0);
}

int main()
{
	int i, j;
	int la;
	
	scanf( "%d %d", &n, &k );
	scanf( "%s", s );
	
	init();
	
	if ( n < 2*k )
	{
		printf( "0\n" );
		return 0;
	}
	
	sg[0] = 1;
	la = -1;
	if ( s[0] == 'B' )
		g[0] = 0;
	else if ( s[0] == 'W' )
	{
		g[0] = 1;
		sg[0] = 2;
		la = 0;
	}
	else if ( s[0] == 'X' )
	{
		g[0] = 1;
		sg[0] = 2;
	}
	
	for ( i = 1; i < n; i++ )
	{
		if ( i - la > k ) la = i-k;
		if ( s[i] == 'B' )
		{
			g[i] = 0;
		}
		else if ( s[i] == 'W' )
		{
			if ( la > 0 )
				g[i] = sg[i-1] - sg[la-1] + mod;
			else g[i] = sg[i-1];
			if ( la == 0 ) g[i] = g[i] - 1 + mod;
			la = i;
		}
		else if ( s[i] == 'X' )
		{
			if ( la > 0 )
				g[i] = sg[i-1] - sg[la-1] + mod;
			else g[i] = sg[i-1];
			if ( la == 0 ) g[i] = g[i] - 1 + mod;
		}
		if ( g[i] >= mod ) g[i] = g[i] % mod;
		sg[i] = sg[i-1] + g[i];
		if ( sg[i] >= mod ) sg[i] = sg[i] % mod;
	}
	
	sri[n-1] = 1;
	la = n;
	if ( s[n-1] == 'W' )
		ri[n-1] = 0;
	else if ( s[n-1] == 'B' )
	{
		ri[n-1] = 1;
		sri[n-1] = 2;
		la = n-1;
	}
	else if ( s[n-1] == 'X' )
	{
		ri[n-1] = 1;
		sri[n-1] = 2;
	}
	
	for ( i = n-2; i >= 0; i-- )
	{
		if ( la - i > k ) la = i + k;
		if ( s[i] == 'W' )
		{
			ri[i] = 0;
		}
		else if ( s[i] == 'B' )
		{
			if ( la < n-1 )
				ri[i] = sri[i+1] - sri[la+1] + mod;
			else ri[i] = sri[i+1];
			if ( la == n-1 ) ri[i] = ri[i] - 1 + mod;
			la = i;
		}
		else if ( s[i] == 'X' )
		{
			if ( la < n-1 )
				ri[i] = sri[i+1] - sri[la+1] + mod;
			else ri[i] = sri[i+1];
			if ( la == n-1 ) ri[i] = ri[i] - 1 + mod;
		}
		if ( ri[i] >= mod ) ri[i] = ri[i] % mod;
		sri[i] = sri[i+1] + ri[i];
		if ( sri[i] >= mod ) sri[i] = sri[i] % mod;
	}
	
	dinv = qpow( 2, mod-2 );
	long long rsum = 0;
	long long ans = 0;
	
	if ( canPutWBlock( n-k, n-1 ) )
	{
		rsum = qpow( 2LL, sx[n-k-1] );
		if ( rsum >= mod ) rsum = rsum % mod;
	}
	
	ri[n] = 1;
	for ( i = n-k-k-1; i >= 0; i-- )
	{
		j = i + 2*k+1;
		if ( ( canPutWBlock( j-k, j-1 ) ) && ( j < n ) )
		{
			rsum = rsum + ri[j]*qpow( 2LL, sx[j-k-1] );
			if ( rsum >= mod ) rsum = rsum % mod;
		}
		
		if ( canPutBBlock( i+1, i+k ) )
		{
			ans = ans + ((g[i]*qpow( dinv, sx[i+k] ))%mod)*rsum;
			if ( ans >= mod ) ans = ans % mod;
		}
	}
	
	if ( n > 2*k )
	{
		if ( canPutWBlock( k, k+k-1 ) )
		{
			rsum = rsum + ri[k+k]*qpow( 2LL, sx[k-1] );
			if ( rsum >= mod ) rsum = rsum % mod;
		}
	}
	
	if ( canPutBBlock( 0, k-1 ) )
	{
		ans = ans + qpow( dinv, sx[k-1] )*rsum;
		if ( ans >= mod ) ans = ans % mod;
	}
	
	std::cout << ans << '\n';
	
	return 0;
}