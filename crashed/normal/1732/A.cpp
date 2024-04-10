#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 25;

template<typename _T>
inline void Read( _T &x ) {
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    if( f ) x = -x;
}

template<typename _T>
inline void Write( _T x ) {
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) Write( x / 10 );
    putchar( x % 10 + '0' );
}

int A[MAXN];

int N;

inline int Gcd( int x, int y ) { for( int z ; y ; z = x, x = y, y = z % y ); return x; }

int main() {
    int T; Read( T );
    while( T -- ) {
        Read( N ); int d = 0;
        rep( i, 1, N ) {
            Read( A[i] );
            d = Gcd( d, A[i] );
        }
        if( d == 1 ) {
            puts( "0" );
            continue;
        }
        if( Gcd( d, N ) == 1 ) {
            puts( "1" );
            continue;
        }
        if( Gcd( d, N - 1 ) == 1 ) {
            puts( "2" );
            continue;
        }
        puts( "3" );
    }
    return 0;
}