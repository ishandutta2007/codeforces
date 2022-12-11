#include <bitset>
#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2005, MAXM = 5e5 + 5;

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

std :: bitset<MAXN> mat[MAXN], inv[MAXN];

int px[MAXM], py[MAXM];

int N, M;

void GetInv() {
    int idx;
    rep( i, 1, N ) inv[i].set( i );
    for( int i = 1 ; i <= N ; i ++ ) {
        for( int j = i ; j <= N ; j ++ )
            if( mat[j].test( i ) )
            { idx = j; break; }
        if( idx != i ) 
            std :: swap( mat[i], mat[idx] ),
            std :: swap( inv[i], inv[idx] );
        for( int j = 1 ; j <= N ; j ++ )
            if( i ^ j && mat[j].test( i ) )
                mat[j] ^= mat[i], inv[j] ^= inv[i];
    }
}

int main() {
//	freopen( ".in", "r", stdin );
//	freopen( ".out", "w", stdout );
    read( N ), read( M );
    rep( i, 1, M ) {
        read( px[i] ), read( py[i] );
        mat[px[i]].set( py[i] );
    }
    GetInv();
    rep( i, 1, M )
        puts( inv[py[i]].test( px[i] ) ? "NO" : "YES" );
    return 0;
}