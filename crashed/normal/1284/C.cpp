#include <cstdio>

const int MAXN = 250005;

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

int fac[MAXN];
int N, mod;

int sqr( const int n ) { return 1ll * n * n % mod; }

int main()
{
	int ans = 0;
	read( N ), read( mod );
	fac[0] = 1;
	for( int i = 1 ; i <= N ; i ++ ) fac[i] = 1ll * fac[i - 1] * i % mod;
	for( int i = 1 ; i <= N ; i ++ )
		ans = ( ans + 1ll * sqr( N - i + 1 ) * fac[i] % mod * fac[N - i] % mod ) % mod;
	write( ans ), putchar( '\n' );
	return 0;
}