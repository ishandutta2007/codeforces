#include <cstdio>

#define rep( x, a, b ) for( int ( x ) = a ; x <= b ; x ++ )
#define per( x, a, b ) for( int ( x ) = a ; x >= b ; x -- )

typedef long long LL;

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

template<typename _T>
_T MIN( const _T a, const _T b )
{
	return a < b ? a : b;
}

int mod;

int Sub( int x, int v ) { return x < v ? x + mod - v : x - v; }
int Mul( LL x, int v ) { x *= v; if( x >= mod ) x %= mod; return x; }
int Add( int x, int v ) { return x + v >= mod ? x + v - mod : x + v; }

struct Value
{
	int s, c;
	Value() { s = c = 0; }
	Value( int S, int C ) { s = S, c = C; }
	Value operator + ( const Value &b ) const
	{ return Value( Add( s, b.s ), Add( c, b.c ) ); }
	Value operator + ( const int &b ) const
	{ return Value( Add( s, Mul( b, c ) ), c ); }
	Value operator * ( const int &b ) const
	{ return Value( Mul( s, b ), c ); }
	Value operator - ( const int &b ) const { return *this + ( mod - b ); }
	Value operator -= ( const int &b ) { return *this = *this - b; }
	Value operator += ( const int &b ) { return *this = *this + b; }
	Value operator *= ( const int &b ) { return *this = *this * b; }
	Value operator += ( const Value &b ) { return *this = *this + b; }
};

Value Sum( LL a, LL b )
{
	if( a > b ) return Value();
	a %= mod, b %= mod;
	int s = Add( a, b ), d = Add( 1, Sub( b, a ) );
	if( s & 1 ) return Value( 1ll * s * ( d / 2 ) % mod, d );
	return Value( 1ll * ( s / 2 ) * d % mod, d );
}

Value Calc( const LL n, const LL l, const LL r, const LL u, const LL v )
{
	if( n == 0 ) return Value();
	if( l <= 1 && n <= r ) return Sum( MAX( 0ll, u ), MIN( n, v ) );
	LL len = n + 1 >> 1; Value ret;
	if( l <= len ) ret += Calc( len, l, MIN( r, len ), u + 2 >> 1, v + 1 >> 1 ) * 2 - 1;
	if( len < r ) ret += Calc( n - len, MAX( l - len, 1ll ), r - len, u + 1 >> 1, v >> 1 ) * 2;
	return ret;
}

int main()
{
	LL N; int M;
	read( N ), read( M ), read( mod );
	while( M -- )
	{
		LL L, R, U, V;
		read( L ), read( R ), read( U ), read( V );
		write( Calc( N, L, R, U, V ).s ), putchar( '\n' );
	}
	return 0;
}