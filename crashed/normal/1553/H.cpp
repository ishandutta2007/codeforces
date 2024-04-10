#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f, NEGINF = 0xc0c0c0c0;
const int MAXS = 1 << 19;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); bool f = false;
	while( ! ( '0' <= s && s <= '9' ) ) { f = s == '-', s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

template<typename _T>
inline _T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

template<typename _T>
inline _T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

int f[MAXS], g[MAXS], h[MAXS];

int N, K;

int main() {
	read( N ), read( K );
	memset( f, 0x3f, sizeof f );
	memset( g, 0x3f, sizeof g );
	memset( h, 0xc0, sizeof h );
	rep( i, 1, N ) {
		int a; read( a );
		g[a] = h[a] = 0;
	}
	for( int s = 1 ; s < ( 1 << K ) ; s <<= 1 )
		for( int i = 0 ; i < ( 1 << K ) ; i += s << 1 )
			for( int j = i ; j < i + s ; j ++ ) {
				int p = INF, q = INF;
				p = Min( Min( f[j], f[j + s] ), g[j + s] + s - h[j] );
				q = Min( Min( f[j], f[j + s] ), g[j] + s - h[j + s] );
				f[j] = p, f[j + s] = q, p = q = INF;
				p = Min( g[j], g[j + s] + s );
				q = Min( g[j] + s, g[j + s] );
				g[j] = p, g[j + s] = q, p = q = NEGINF;
				p = Max( h[j], h[j + s] + s );
				q = Max( h[j] + s, h[j + s] );
				h[j] = p, h[j + s] = q;
			}
	for( int s = 0 ; s < ( 1 << K ) ; s ++ )
		write( f[s] ), putchar( " \n"[s == ( 1 << K ) - 1] );
	return 0;
}