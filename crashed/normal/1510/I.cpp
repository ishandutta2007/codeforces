#include <cmath>
#include <ctime>
#include <cstdio>
#include <random>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 10005;

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

char str[MAXN];

int wro[MAXN];

int N, M;

int main() {
    std :: default_random_engine rng( time( 0 ) );
    read( N ), read( M );
    rep( i, 1, M ) {
        scanf( "%s", str + 1 );
        double possi[2] = {}; int mn = 1e9;
        rep( j, 1, N ) mn = std :: min( mn, wro[j] );
        rep( j, 1, N ) possi[str[j] - '0'] += pow( 0.75, wro[j] - mn );
        putchar( '0' + std :: bernoulli_distribution( possi[1] / ( possi[0] + possi[1] ) )( rng ) ), putchar( '\n' );
        fflush( stdout ); int ans; read( ans );
        rep( j, 1, N ) wro[j] += ans != str[j] - '0';
    }
    return 0;
}