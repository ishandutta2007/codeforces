#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e4 + 5;

template<typename _T>
void read( _T &x )
{
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
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

int seq[MAXN], tot = 0;

int a[MAXN], pos[MAXN];
int N;

void Reverse( const int r )
{
	if( r == 1 ) return;
	for( int i = 1 ; i * 2 <= r ; i ++ )
		a[i] ^= a[r - i + 1] ^= a[i] ^= a[r - i + 1];
	rep( i, 1, r ) pos[a[i]] = i; seq[++ tot] = r;
}

int main()
{
//	freopen( "data.in", "r", stdin );
//	freopen( "data.out", "w", stdout );
	int T;
	read( T );
	while( T -- )
	{
		read( N ), tot = 0;
		rep( i, 1, N ) read( a[i] ), pos[a[i]] = i;
		bool flg = true;
		rep( i, 1, N ) flg &= pos[i] % 2 == i % 2;
		if( ! flg ) { puts( "-1" ); continue; }
		for( int i = N ; i > 1 ; i -= 2 )
		{
			if( pos[i] == i && pos[i - 1] == i - 1 )
				continue;
			Reverse( pos[i] );
			Reverse( pos[i - 1] - 1 );
			Reverse( pos[i - 1] + 1 );
			Reverse( 3 ), Reverse( i );
		}
		write( tot ), putchar( '\n' );
		rep( i, 1, tot ) write( seq[i] ), putchar( i == tot ? '\n' : ' ' );
	}
	return 0;
}