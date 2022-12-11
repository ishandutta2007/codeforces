#include <cstdio>

#define rep( x, a, b ) for( int ( x ) = a ; x <= b ; x ++ )
#define per( x, a, b ) for( int ( x ) = a ; x >= b ; x -- )

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

template<typename _T>
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
}

void Upt( int &x, const int v ) { x = MAX( x, v ); }

int Calc( const int len, int l1, int r1, int l2, int r2 )
{
	if( len == 0 ) return 0;
	if( l1 > r1 || l2 > r2 ) return 0;
	if( l1 > l2 ) swapp( l1, l2 ), swapp( r1, r2 ); int ret = 0;
	if( MAX( l1, l2 ) <= MIN( r1, r2 ) ) ret = MIN( r1, r2 ) - MAX( l1, l2 ) + 1;
	if( ( l1 <= l2 && r2 <= r1 ) || ( l2 <= l1 && r1 <= r2 ) ) return ret;
	int mid = 1 + len >> 1, 
		nL1 = l1 % mid, nR1 = r1 % mid, 
		nL2 = l2 % mid, nR2 = r2 % mid;
	bool i1 = l1 <= mid && mid <= r1, i2 = l2 <= mid && mid <= r2;
	if( ! i1 && ! i2 ) 
		Upt( ret, Calc( len >> 1, nL1, nR1, nL2, nR2 ) );
	if( i1 && ! i2 ) 
	{
		Upt( ret, Calc( len >> 1, l1, mid - 1, nL2, nR2 ) );
		Upt( ret, Calc( len >> 1, 1, nR1, nL2, nR2 ) );
	}
	if( ! i1 && i2 )
	{
		Upt( ret, Calc( len >> 1, nL1, nR1, l2, mid - 1 ) ); 
		Upt( ret, Calc( len >> 1, nL1, nR1, 1, nR2 ) );
	}
	if( i1 && i2 )
	{
		Upt( ret, Calc( len >> 1, l1, mid - 1, 1, nR2 ) ); 
		Upt( ret, Calc( len >> 1, l1, mid - 1, l2, mid - 1 ) );
		Upt( ret, Calc( len >> 1, 1, nR1, 1, nR2 ) );
		Upt( ret, Calc( len >> 1, 1, nR1, l2, mid - 1 ) );
	}
	return ret;
}

const int LIM = 30;

int main()
{
	int L1, L2, R1, R2;
	read( L1 ), read( L2 ), read( R1 ), read( R2 );
	write( Calc( ( 1 << LIM ) - 1, L1, L2, R1, R2 ) ), putchar( '\n' );
	return 0;
}
/*
5 9 3 7
*/