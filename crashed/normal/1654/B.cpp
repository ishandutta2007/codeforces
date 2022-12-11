#include <cstdio>
#include <cstring>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5;

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
int app[26];

int N, fir;

int main() {
    // freopen( ".in", "r", stdin );
    // freopen( ".out", "w", stdout );
    int T; read( T );
    while( T -- ) {
        scanf( "%s", str + 1 );
        N = strlen( str + 1 );
        rep( i, 0, 25 ) app[i] = 0;
        rep( i, 1, N ) app[str[i] - 'a'] ++;
        for( fir = 1 ; app[str[fir] - 'a'] > 1 ; app[str[fir ++] - 'a'] -- );
        puts( str + fir );
    }
    return 0;
}