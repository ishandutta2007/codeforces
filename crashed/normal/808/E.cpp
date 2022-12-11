#include <cstdio>
#include <iostream>
#include <algorithm>
#include <functional>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

#define int long long

const int MAXN = 3e5 + 5;

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

int good[4][MAXN], tot[4];

int N, M;

int Query( const int x ) {
    int ret = 0;
    for( int i = 0 ; i <= tot[2] && i * 2 + x * 3 <= M ; i ++ )
        ret = std :: max( ret, good[3][x] + good[2][i] + good[1][std :: min( tot[1], M - i * 2 - x * 3 )] );
    return ret;
}

signed main() {
    read( N ), read( M );
    rep( i, 1, N ) {
        int w, c;
        read( w ), read( c );
        good[w][++ tot[w]] = c;
    }
    rep( i, 1, 3 ) {
        std :: sort( good[i] + 1, good[i] + 1 + tot[i], std :: greater<int>() );
        rep( j, 1, tot[i] ) good[i][j] += good[i][j - 1];
    }
    int l = 0, r = std :: min( M / 3, tot[3] ), lmid, rmid;
    while( r - l + 1 > 5 ) {
        lmid = ( l * 2 + r ) / 3, rmid = ( l + r * 2 ) / 3;
        if( Query( lmid ) > Query( rmid ) ) r = rmid - 1;
        else l = lmid;
    }
    int ans = 0;
    rep( i, l, r )
        ans = std :: max( ans, Query( i ) );
    write( ans ), putchar( '\n' );
    return 0;
}