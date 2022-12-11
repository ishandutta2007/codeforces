#include <cstdio>

const int MAXN = 1e5 + 5, MAXLOG = 50;

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
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
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

int ance[MAXN];
int N, M, K;

int Lowbit( const int x ) { return x & ( -x ); }
bool Chk( int x ) { return x - Lowbit( x ) == 0; }

int main()
{
	read( N ), read( K );
	int lim = MAX( ( N - 3 ) / 2, 0 );
	if( K > lim ) return puts( "NO" ), 0;
	if( N % 2 == 0 ) return puts( "NO" ), 0;
	if( N == 9 && K == 2 ) return puts( "NO" ), 0;
	if( Chk( N + 1 ) && K == 1 ) return puts( "NO" ), 0;
	if( ! Chk( N + 1 ) && K == 0 ) return puts( "NO" ), 0;
	
	puts( "YES" );
	int base = 2 * MAX( 0, K - 1 ); 
	for( int i = 1 ; i < base ; i += 2 )
		ance[i + 1] = i, ance[i] = MAX( 0, i - 2 );
	for( int i = 1 ; i <= N - base ; i ++ )
	{
		if( i == 1 ) ance[i + base] = MAX( 0, base - 1 );
		else ance[i + base] = ( i >> 1 ) + base;
	}	
	if( Chk( N - base + 1 ) && K ) ance[N - 1] = ance[N] = 2;
	for( int i = 1 ; i <= N ; i ++ ) write( ance[i] ), putchar( i == N ? '\n' : ' ' );
	return 0;
}