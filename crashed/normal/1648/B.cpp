#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e6 + 5;

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
_T MIN( const _T a, const _T b ) {
    return a < b ? a : b;
}

int pref[MAXN];
bool app[MAXN];

int A[MAXN];

int N, C;

int main() {
    // freopen( ".in", "r", stdin );
    // freopen( ".out", "w", stdout );
    int T; read( T );
    while( T -- ) {
        read( N ), read( C );
        rep( i, 0, C ) app[i] = false, pref[i] = 0;
        rep( i, 1, N ) read( A[i] );
        rep( i, 1, N ) app[A[i]] = true;
        rep( i, 1, C ) pref[i] = pref[i - 1] + app[i];
        bool flg = true;
        rep( i, 1, C ) {
            if( app[i] ) continue;
            for( int j = 1 ; j * i <= C ; j ++ ) 
                if( app[j] && pref[MIN( C, j * ( i + 1 ) - 1 )] - pref[j * i - 1] ) {
                    flg = false; break;
                }
            if( ! flg ) break;
        }
        puts( flg ? "Yes" : "No" );
    }
    return 0;
}