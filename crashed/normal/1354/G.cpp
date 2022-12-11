#include <cstdio>
#include <random>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e3 + 5;

bool tried[MAXN];

int seq[MAXN];
int N, K;

inline int Query( const std :: vector<int> &A, const std :: vector<int> &B ) {
    static char buf[10] = {};

    printf( "? %lu %lu\n", A.size(), B.size() );
    for( const int &x : A ) printf( "%d ", x );
    puts( "" );
    for( const int &x : B ) printf( "%d ", x );
    puts( "" ), fflush( stdout );

    scanf( "%s", buf );
    if( buf[0] == 'F' ) return 1;
    if( buf[0] == 'S' ) return -1;
    if( buf[0] == 'E' ) return 0;
    exit( 114514 );
}

// return a non-negative value: knowing the absolute length
// return -1: the whole range is just same.
// return -2: the whole range isn't same, and further search needed.

inline bool IfHeaviest( const int &x ) {
    static std :: mt19937 rng( 998244853 );

    rep( i, 1, N - 1 ) seq[i] = i + 1;
    std :: shuffle( seq + 1, seq + N, rng ); 
    for( int i = 1 ; i < N && i <= 15 ; i ++ )
        if( Query( { x }, { seq[i] } ) == -1 )
            return false;
    return true;
}

int main() {
    // freopen( ".in", "r", stdin );
    // freopen( ".out", "w", stdout );
    int T; scanf( "%d", &T );
    while( T -- ) {
        scanf( "%d %d", &N, &K );
        if( ! IfHeaviest( 1 ) ) {
            puts( "! 1" ); 
            fflush( stdout );
            continue;
        }
        int siz = 1;
        while( siz * 2 <= N - K ) {
            std :: vector<int> A, B;
            rep( i, 1, siz ) A.push_back( i );
            rep( i, 1, siz ) B.push_back( i + siz );
            if( Query( A, B ) ) break;
            siz <<= 1;
        }
        int l = siz;
        for( int s = siz >> 1 ; s ; s >>= 1 ) {
            if( l + s > N ) continue;
            std :: vector<int> A, B;
            rep( i, 1, s ) A.push_back( i );
            rep( i, 1, s ) B.push_back( i + l );
            if( Query( A, B ) ) continue;
            l += s;
        }
        printf( "! %d\n", l + 1 );
        fflush( stdout );
    }
    return 0;
}