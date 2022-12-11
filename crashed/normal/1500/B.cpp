#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

#define int LL

const int MAXN = 5e5 + 5;

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

int A[MAXN], B[MAXN], app[MAXN << 1]; 
int N, M, lim, d; LL K, LCM;

int Gcd( int a, int b ) { return b ? Gcd( b, a % b ) : a; }

int Exgcd( const int a, const int b, LL &x, LL &y )
{
	if( ! b ) return ( x = 1, y = 0, a );
	int d = Exgcd( b, a % b, y, x );
	y -= ( a / b ) * x; return d;
}

bool Chk( const LL p )
{
	LL dif = p, tims = p / LCM, ref = p % LCM;
	rep( i, 0, M - 1 ) if( ~ B[i] )
		dif -= tims, dif -= B[i] < ref;
	return dif >= K;
}

LL Inv( const LL a, const LL mod )
{
	LL x, y; Exgcd( a, mod, x, y );
	return ( x % mod + mod ) % mod;
}

signed main()
{
	read( N ), read( M ), read( K ); 
	d = Gcd( N, M ), LCM = 1ll * N / d * M;
	memset( app, -1, sizeof app );
	rep( i, 0, N - 1 ) read( A[i] ), app[-- A[i]] = i;
	rep( i, 0, M - 1 ) read( B[i] ), B[i] = app[B[i] - 1];
	
	LL inv = Inv( N / d, M / d );
	rep( i, 0, M - 1 )
	{
		if( ~ B[i] && ( i - B[i] ) % d == 0 )
		{
			LL x = ( ( i - B[i] ) / d * inv % ( M / d ) + ( M / d ) ) % ( M / d );
			B[i] = x * N + B[i];
		}
		else B[i] = -1;
	}
	LL l = 1, r = 1e18, mid;
	while( l < r )
	{
		mid = l + r >> 1;
		if( Chk( mid ) ) r = mid;
		else l = mid + 1;
	}
	write( l ), putchar( '\n' );
	return 0;
}