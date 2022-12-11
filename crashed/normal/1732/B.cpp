#include <bits/stdc++.h>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 1e5 + 5;

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

char str[MAXN];

int pos[MAXN], tot;

int N;

int main() {
    int T; Read( T );
    while( T -- ) {
        Read( N ), tot = 0;
        scanf( "%s", str + 1 );

        LL ans = INF;
        rep( i, 2, N ) 
            if( str[i - 1] != str[i] )
                pos[++ tot] = i;
        if( tot == 0 ) {
            puts( "0" );
            continue;
        }
        rep( i, 1, tot ) {
            LL res = tot - 1;
            if( ( ( i - 1 ) & 1 ) != ( str[pos[i] - 1] == '1' ) )
                res ++;
            ans = std :: min( ans, res );
        }
        Write( ans ), putchar( '\n' );
    }
    return 0;
}