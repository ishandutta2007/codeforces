#include <cstdio>

const int mod = 1e9 + 7;
const int MAXK = 1e6 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0;char s = getchar();int f = 1;
	while( s > '9' || s < '0' ){if( s == '-' ) f = -1; s = getchar();}
	while( s >= '0' && s <= '9' ){x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar();}
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ){ putchar( '-' ); x = ( ~ x ) + 1; }
	if( 9 < x ){ write( x / 10 ); }
	putchar( x % 10 + '0' );
}

int S[MAXK];
int prime[MAXK], pk[MAXK], inv[MAXK], pn;
int N, K;
bool isPrime[MAXK];

int qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = 1ll * ret * base % mod;
		base = 1ll * base * base % mod, indx >>= 1;
	}
	return ret;
}

int inver( const int a ) { return qkpow( a, mod - 2 ); }
void add( int &x, const int v ) { x = ( x + v >= mod ? x + v - mod : x + v ); }

int Lagrange( const int n, const int k )
{
	int L = 1, ret = 0, w = 1;
	for( int i = 1 ; i <= k + 2 ; i ++ ) S[i] = ( S[i - 1] + pk[i] ) % mod;
	if( n <= k + 2 ) return S[n];
	for( int i = 1 ; i <= k + 2 ; i ++ ) L = 1ll * L * ( n - i ) % mod;
	for( int i = 1 ; i <= k + 1 ; i ++ ) w = 1ll * w * inver( i - k - 2 + mod ) % mod;
	for( int i = 1 ; i <= k + 2 ; i ++ )
	{
		add( ret, 1ll * L * w % mod * S[i] % mod * inver( n - i ) % mod );
		if( i <= k + 1 ) w = 1ll * w * ( i - k - 2 + mod ) % mod * inv[i] % mod;
	}
	return ret;
}

void EulerSieve( const int siz, const int k )
{
	pk[1] = 1;
	for( int i = 2 ; i <= siz ; i ++ )
	{
		if( ! isPrime[i] ) prime[++ pn] = i, pk[i] = qkpow( i, k );
		for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= siz ; j ++ )
		{
			isPrime[i * prime[j]] = true, pk[i * prime[j]] = 1ll * pk[i] * pk[prime[j]] % mod;
			if( ! ( i % prime[j] ) ) break;
		}
	}
}

void init()
{
	EulerSieve( K + 5, K );
	inv[1] = 1; 
	for( int i = 2 ; i <= K + 5 ; i ++ ) 
		inv[i] = 1ll * ( mod - mod / i ) * inv[mod % i] % mod;
}

int main()
{
	read( N ), read( K ), init();
	write( Lagrange( N, K ) ), putchar( '\n' );
	return 0;
}