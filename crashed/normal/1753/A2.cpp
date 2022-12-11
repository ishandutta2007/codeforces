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

int lef[MAXN], rig[MAXN];
int tot = 0;

int pos[MAXN], len = 0;

int A[MAXN];
int N;

int main() {
    int T; Read( T );
    while( T -- ) {
        Read( N );
        len = tot = 0;
        rep( i, 1, N ) Read( A[i] );
        rep( i, 1, N ) if( A[i] ) 
            pos[++ len] = i;
        if( len & 1 ) {
            puts( "-1" );
            continue;
        }
        if( ! len ) {
            printf( "1\n1 %d\n", N );
            continue;
        }
        if( 1 < pos[1] )
            tot ++, lef[tot] = 1, rig[tot] = pos[1] - 1;
        for( int i = 1 ; i <= len ; i += 2 ) {
            if( i > 1 && pos[i - 1] + 1 < pos[i] )
                tot ++, lef[tot] = pos[i - 1] + 1, rig[tot] = pos[i] - 1;
            if( A[pos[i]] != A[pos[i + 1]] ) {
                tot ++, lef[tot] = pos[i], rig[tot] = pos[i];
                if( pos[i] + 1 < pos[i + 1] )
                    tot ++, lef[tot] = pos[i] + 1, rig[tot] = pos[i + 1] - 1;
                tot ++, lef[tot] = pos[i + 1], rig[tot] = pos[i + 1];
            } else {
                if( pos[i] + 1 < pos[i + 1] ) {
                    tot ++, lef[tot] = pos[i], rig[tot] = pos[i];
                    if( pos[i] + 1 < pos[i + 1] - 1 )
                        tot ++, lef[tot] = pos[i] + 1, rig[tot] = pos[i + 1] - 2;
                } 
                tot ++, lef[tot] = pos[i + 1] - 1, rig[tot] = pos[i + 1];
            }
        }
        if( pos[len] < N )
            tot ++, lef[tot] = pos[len] + 1, rig[tot] = N;
        Write( tot ), putchar( '\n' );
        rep( i, 1, tot ) Write( lef[i] ), putchar( ' ' ), Write( rig[i] ), putchar( '\n' );
    }
    return 0;
}