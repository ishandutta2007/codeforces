#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;

const int mod = 1e9 + 7;
const int MAXN = 1e4 + 5, MAXS = 100;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x )
{
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
_T MAX( const _T a, const _T b )
{
	return a > b ? a : b;
}

int f[MAXS], inv[MAXS];

int ind[MAXN];
LL prim[MAXN], pn;

LL N; int K, lim;

int Qkpow( int, int );
inline int Mul( LL x, int v ) { return x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

int Qkpow( int base, int indx )
{
	int ret = 1;
	while( indx )
	{
		if( indx & 1 ) ret = Mul( ret, base );
		base = Mul( base, base ), indx >>= 1;
	}
	return ret;
}

void PFactorize( LL n )
{
	for( LL i = 2 ; i * i <= n ; i ++ )
		if( ! ( n % i ) )
		{
			prim[++ pn] = i;
			while( ! ( n % i ) )
				ind[pn] ++, n /= i;
		}
	if( n > 1 ) prim[++ pn] = n, ind[pn] = 1;
}

int Calc( LL p, const int x )
{
	for( int i = 0 ; i <= x ; i ++ ) f[i] = 0;
	f[0] = 1; int tmp;
	for( int k = 1 ; k <= K ; k ++ )
		for( int i = x ; ~ i ; i -- )
		{
			tmp = 0;
			for( int j = i ; ~ j ; j -- )
				tmp = Add( tmp, Mul( inv[x - j + 1], f[j] ) );
			f[i] = tmp;
		}
	int ret = 0, pw = 1; p %= mod;
	for( int i = 0 ; i <= x ; i ++, pw = Mul( pw, p ) )
		ret = Add( ret, Mul( pw, f[x - i] ) );
	return ret;
}

int main()
{
	read( N ), read( K );
	PFactorize( N ); int ans = 1;
	for( int i = 1 ; i <= pn ; i ++ ) lim = MAX( lim, ind[i] );
	for( int i = 1 ; i <= lim + 1 ; i ++ ) inv[i] = Inv( i );
	for( int i = 1 ; i <= pn ; i ++ ) ans = Mul( ans, Calc( prim[i], ind[i] ) );
	write( ans ), putchar( '\n' );
	return 0;
}