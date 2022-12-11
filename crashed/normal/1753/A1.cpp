#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5;

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

int tot = 0;
int lef[MAXN], rig[MAXN];

int A[MAXN];

int N;

int main() {
    int T; Read( T );
    while( T -- ) {
        Read( N );
        rep( i, 1, N ) Read( A[i] );
        if( N & 1 ) {
            puts( "-1" );
            continue;
        }
        tot = 0;
        for( int i = 1 ; i <= N ; i += 2 ) {
            if( A[i] != A[i + 1] ) {
                tot ++, lef[tot] = i, rig[tot] = i;
                tot ++, lef[tot] = i + 1, rig[tot] = i + 1;
            } else 
                tot ++, lef[tot] = i, rig[tot] = i + 1;
        }
        printf( "%d\n", tot );
        rep( i, 1, tot ) Write( lef[i] ), putchar( ' ' ), Write( rig[i] ), putchar( '\n' );
    }
    return 0;
}