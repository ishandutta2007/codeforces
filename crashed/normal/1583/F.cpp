#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e3 + 5;

template<typename _T>
void read( _T &x ) {
	x = 0; char s = getchar(); int f = 1;
	while( ! ( '0' <= s && s <= '9' ) ) { f = 1; if( s == '-' ) f = -1; s = getchar(); }
	while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
	x *= f;
}

template<typename _T>
void write( _T x ) {
	if( x < 0 ) putchar( '-' ), x = -x;
	if( 9 < x ) write( x / 10 );
	putchar( x % 10 + '0' );
}

int grph[MAXN][MAXN];

int N, K, col = 0;

void Construct( const int &l, const int &r, const int &id ) {
	if( l >= r ) return ;
	if( col < id ) col = id;
	int siz = r - l + 1, lstR = l - 1, curL, curR;
	rep( i, 1, K ) {
		curL = lstR + 1, curR = lstR + siz / K + ( i <= siz % K );
		Construct( curL, curR, id + 1 );
		rep( j, l, lstR )
			rep( k, curL, curR )
				grph[j][k] = id;
		lstR = curR;
	}
}

int main() {
	read( N ), read( K );
	Construct( 1, N, 1 );
	write( col ), putchar( '\n' );
	rep( i, 1, N ) rep( j, i + 1, N )
		write( grph[i][j] ), putchar( ' ' );
	puts( "" );
	return 0;
}