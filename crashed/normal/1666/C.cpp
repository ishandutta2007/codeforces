#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 15;

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
_T Abs( const _T &a ) {
	return a < 0 ? -a : a;
}

template<typename _T>
_T Min( const _T &a, const _T &b ) {
	return a < b ? a : b;
}

template<typename _T>
_T Max( const _T &a, const _T &b ) {
	return a > b ? a : b;
}

typedef std :: pair<int, int> Point;
typedef std :: pair<Point, Point> Segment;

std :: vector<Segment> seg;

Point pnt[3];

int main() {
	// freopen( ".in", "r", stdin );
	// freopen( ".out", "w", stdout );
	int yMn = 1e9, yMx = - 1e9;
	rep( i, 0, 2 )
		read( pnt[i].first ),
		read( pnt[i].second );
	std :: sort( pnt, pnt + 3 );
	rep( i, 0, 2 ) {
		yMn = Min( yMn, pnt[i].second );
		yMx = Max( yMx, pnt[i].second );
	}
	if( yMn != yMx )
		seg.push_back( { { pnt[1].first, yMn }, { pnt[1].first, yMx } } );
	if( pnt[0].first != pnt[1].first )
		seg.push_back( { { pnt[0].first, pnt[0].second }, { pnt[1].first, pnt[0].second } } );
	if( pnt[2].first != pnt[1].first )
		seg.push_back( { { pnt[2].first, pnt[2].second }, { pnt[1].first, pnt[2].second } } );
	int n = seg.size();
	write( n ), putchar( '\n' );
	rep( i, 0, n - 1 ) {
		write( seg[i].first.first ), putchar( ' ' );
		write( seg[i].first.second ), putchar( ' ' );
		write( seg[i].second.first ), putchar( ' ' );
		write( seg[i].second.second ), putchar( '\n' );
	}
	return 0;
}