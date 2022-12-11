#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 5e5 + 5;

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

int cnt[MAXN];

int N, X;

int main() {
    Read( N ), Read( X );
    rep( i, 1, N ) {
        int a; Read( a );
        cnt[a] ++;
    }
    rep( i, 1, X - 1 ) {
        cnt[i + 1] += cnt[i] / ( i + 1 );
        cnt[i] %= i + 1;
        if( cnt[i] ) 
            return puts( "No" ), 0;
    }
    puts( "Yes" );
    return 0;
}