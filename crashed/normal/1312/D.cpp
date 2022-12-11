#include <cstdio>

const int mod = 998244353;
const int MAXN = 2e5 + 5;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int fac[MAXN], inv[MAXN], invFac[MAXN];
int N, M;

void init()
{
	fac[0] = fac[1] = invFac[0] = invFac[1] = inv[1] = 1;
	for( int i = 2 ; i <= M ; i ++ )
		fac[i] = 1ll * fac[i - 1] * i % mod, inv[i] = 1ll * ( mod - mod / i ) * inv[mod % i] % mod,
		invFac[i] = 1ll * invFac[i - 1] * inv[i] % mod;
}

int C( const int n, const int m ) 
{ 
	if( n < m ) return 0;
	return 1ll * fac[n] * invFac[m] % mod * invFac[n - m] % mod;
}

int main()
{
	read( N ), read( M );
	init();
	int tmp = 0;
	for( int i = 2 ; i <= N ; i ++ ) tmp = ( tmp + 1ll * C( N - 3, i - 2 ) ) % mod;
	write( 1ll * C( M, N - 1 ) * ( N - 2 ) % mod * tmp % mod ), putchar( '\n' ); 
	return 0;
}