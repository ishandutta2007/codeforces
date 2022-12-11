#include <cmath>
#include <cstdio>

typedef long long LL;

const double PI = acos( -1 );
const int MAXN = 4e5 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( s < '0' || '9' < s ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ); s = getchar(); }
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
void swapp( _T &x, _T &y )
{
	_T t = x; x = y, y = t;
}

LL P;
int N, M;

int main()
{
//	freopen( "sing.in", "r", stdin );
//	freopen( "sing.out", "w", stdout );
	read( N ), read( M ), read( P );
	int p = -1, q = -1; LL a;
	for( int i = 0 ; i < N ; i ++ )
	{
		read( a );
		if( a % P && p == -1 ) p = i;
	}
	for( int i = 0 ; i < M ; i ++ )
	{
		read( a );
		if( a % P && q == -1 ) q = i;
	}
	write( p + q ), putchar( '\n' );
	return 0;
}