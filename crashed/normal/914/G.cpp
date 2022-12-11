#include <cstdio>

typedef long long LL;

const int mod = 1e9 + 7, inv2 = 5e8 + 4;
const int MAXN = 1e6 + 5, MAXL = ( 1 << 17 ) + 5, MAXLOG = 20;

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
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int f[MAXLOG][MAXL], h[MAXL];
int A[MAXL], B[MAXL], C[MAXL], fibo[MAXL];
int cnt[MAXL];
int N, len, lg2;

int lowbit( const int x ) { return x & ( -x ); }
int fix( const int a ) { return ( a % mod + mod ) % mod; }
int count( int x ) { int ret = 0; while( x ) ret ++, x -= lowbit( x ); return ret; }

namespace OR
{
	void FWT( int *F, const int mode )
	{
		for( int s = 2 ; s <= len ; s <<= 1 )
			for( int i = 0, t = s >> 1 ; i < len ; i += s )
				for( int j = i ; j < i + t ; j ++ )
					F[j + t] = fix( F[j + t] + mode * F[j] );
	}
}

namespace AND
{
	void FWT( int *F, const int mode )
	{
		for( int s = 2 ; s <= len ; s <<= 1 )
			for( int i = 0, t = s >> 1 ; i < len ; i += s )
				for( int j = i ; j < i + t ; j ++ )
					F[j] = fix( F[j] + mode * F[j + t] );
	}
}

namespace XOR
{
	void FWT( int *F, const int mode )
	{
		int t1, t2;
		for( int s = 2 ; s <= len ; s <<= 1 )
			for( int i = 0, t = s >> 1 ; i < len ; i += s )
				for( int j = i ; j < i + t ; j ++ )
				{
					t1 = F[j], t2 = F[j + t];
					if( mode > 0 ) F[j] = ( t1 + t2 ) % mod, F[j + t] = fix( t1 - t2 );
					else F[j] = 1ll * ( t1 + t2 ) * inv2 % mod, F[j + t] = 1ll * fix( t1 - t2 ) * inv2 % mod;
				}
	}
}

void FST()
{
	for( int i = 0 ; i <= lg2 ; i ++ ) OR :: FWT( f[i], 1 );
	for( int i = 0 ; i <= lg2 ; i ++ )
	{
		for( int S = 0 ; S < len ; S ++ ) h[S] = 0;
		for( int j = 0 ; j <= i ; j ++ )
			for( int S = 0 ; S < len ; S ++ )
				h[S] = ( h[S] + 1ll * f[j][S] * f[i - j][S] % mod ) % mod;
		OR :: FWT( h, -1 );
		for( int S = 0 ; S < len ; S ++ ) if( cnt[S] == i ) A[S] = ( A[S] + h[S] ) % mod;	
	}
}

void init()
{
	fibo[0] = 0, fibo[1] = 1;
	for( int i = 2 ; i < ( 1 << 17 ) ; i ++ ) fibo[i] = ( fibo[i - 1] + fibo[i - 2] ) % mod;
	for( int i = 0 ; i < ( 1 << 17 ) ; i ++ ) cnt[i] = count( i );
}

signed main()
{
	int mx = 0;
	read( N );
	init();
	for( int i = 1, v ; i <= N ; i ++ ) 
	{
		read( v ), mx = MAX( v, mx );
		f[cnt[v]][v] ++, C[v] ++, B[v] = ( B[v] + fibo[v] ) % mod;
	}
	for( lg2 = 0, len = 1 ; len <= mx ; len <<= 1, lg2 ++ );
	FST();
	XOR :: FWT( C, 1 );
	for( int i = 0 ; i < len ; i ++ ) C[i] = 1ll * C[i] * C[i] % mod;
	XOR :: FWT( C, -1 );
	for( int i = 0 ; i < len ; i ++ ) A[i] = 1ll * A[i] * fibo[i] % mod, C[i] = 1ll * C[i] * fibo[i] % mod;
	AND :: FWT( A, 1 ), AND :: FWT( B, 1 ), AND :: FWT( C, 1 );
	for( int i = 0 ; i < len ; i ++ ) A[i] = 1ll * A[i] * B[i] % mod * C[i] % mod;
	AND :: FWT( A, -1 );
	int ans = 0;
	for( int i = 1 ; i <= len ; i <<= 1 ) ( ans += A[i] ) %= mod;
	write( ans ), putchar( '\n' );
	return 0;
}