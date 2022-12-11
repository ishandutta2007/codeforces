#include <ctime>
#include <cstdio>
#include <random>
#include <utility>
#include <iostream>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = ( 1 << 12 ) + 5;

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

int pos[MAXN], val[MAXN];
int p[MAXN], q[MAXN];
int A[MAXN];

int K, N;

inline bool Chk() {
    int su = 0;
    rep( i, 0, N - 1 )
        su ^= A[i];
    return su == 0;
}

void Fix( const int &i, const int &j ) {
    int k = pos[val[i] ^ q[i]];
    if( k == i ) return ;
    if( k == j ) {
        std :: swap( pos[p[i]], pos[p[j]] );
        std :: swap( p[i], p[j] );
        return ;
    }
    std :: swap( pos[p[i]], pos[p[k]] );
    std :: swap( p[i], p[k] );
    std :: swap( q[k], q[j] );
    Fix( k, j );
}

int main() {
    Read( K ), N = 1 << K;
    rep( i, 0, N - 1 ) Read( A[i] );
    if( ! Chk() ) return puts( "Fou" ), 0;
    puts( "Shi" );
    rep( i, 0, N - 1 ) p[i] = q[i] = pos[i] = i, val[i] = 0;
    rep( i, 0, N - 2 ) {
        int x = val[i] ^ A[i];
        val[i] ^= x, val[i + 1] ^= x;
        Fix( i, i + 1 );
    }
    rep( i, 0, N - 1 ) Write( p[i] ), putchar( " \n"[i == N - 1] );
    rep( i, 0, N - 1 ) Write( q[i] ), putchar( " \n"[i == N - 1] );
    return 0;
}