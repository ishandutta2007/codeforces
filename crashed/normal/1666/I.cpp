#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

template<typename _T>
void read( _T &x ) {
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    if( f ) x = -x;
}

template<typename _T>
void write( _T x ) {
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) write( x / 10 );
    putchar( x % 10 + '0' );
}

inline int Dig( const int &r, const int &c ) {
    printf( "DIG %d %d\n", r, c );
    fflush( stdout ); int x;
    read( x ); return x;
}

inline int Scan( const int &r, const int &c ) {
    printf( "SCAN %d %d\n", r, c );
    fflush( stdout ); int x;
    read( x ); return x;
}

int main() {
    int T; read( T );
    while( T -- ) {
        int N, M;
        read( N ), read( M );
        int c1 = Scan( 1, 1 ) + 4, 
            c2 = Scan( N, 1 ) - 2 * N + 2;
        int xSum = ( c1 - c2 ) / 2,
            ySum = ( c1 + c2 ) / 2;
        int xDif = Scan( xSum >> 1, 1 ) - ( ySum - 2 ),
            yDif = Scan( 1, ySum >> 1 ) - ( xSum - 2 );
        int x1 = ( xSum + xDif ) / 2, x2 = xSum - x1,
            y1 = ( ySum + yDif ) / 2, y2 = ySum - y1;
        if( x1 > x2 ) std :: swap( x1, x2 );
        if( y1 > y2 ) std :: swap( y1, y2 );
        if( Dig( x1, y1 ) ) Dig( x2, y2 );
        else Dig( x1, y2 ), Dig( x2, y1 );
    }
    return 0;
}