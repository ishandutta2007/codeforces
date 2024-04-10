#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e3 + 5;

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

template<typename _T>
_T Max( const _T a, const _T b ) {
    return a > b ? a : b;
}

int suf[MAXN], pref[MAXN];
int A[MAXN];

int N;

int main() {
    // freopen( ".in", "r", stdin );
    // freopen( ".out", "w", stdout );
    int T; read( T );
    while( T -- ) {
        read( N );
        rep( i, 1, N ) read( A[i] );
        int ans = 0;
        rep( i, 1, N ) rep( j, i + 1, N )
            ans = Max( ans, A[i] + A[j] );
        write( ans ), putchar( '\n' );
    }
    return 0;
}