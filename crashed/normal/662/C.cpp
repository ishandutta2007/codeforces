#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 25, MAXM = 1e5 + 5, MAXS = ( 1 << 20 ) + 5;

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
_T Min( const _T &a, const _T &b ) {
    return a < b ? a : b;
}

LL coe[MAXS], app[MAXS], res[MAXS];

char buf[MAXN][MAXM];

int N, M;

void XOR( LL *coe, const int &n, const int &typ ) {
    int L = 1 << n;
    for( int s = 1 ; s < L ; s <<= 1 )
        for( int i = 0 ; i < L ; i += s << 1 )
            for( int j = 0 ; j < s ; j ++ ) {
                LL a = coe[i + j], b = coe[i + j + s];
                if( ~ typ )
                    coe[i + j] = a + b, 
                    coe[i + j + s] = a - b;
                else
                    coe[i + j] = ( a + b ) >> 1, 
                    coe[i + j + s] = ( a - b ) >> 1;
            }
}

int main() {
    read( N ), read( M );
    rep( i, 0, N - 1 ) scanf( "%s", buf[i] + 1 );
    rep( j, 1, M ) {
        int val = 0;
        rep( i, 0, N - 1 )
            val = val << 1 | ( buf[i][j] ^ '0' );
        app[val] ++;
    }
    for( int s = 0 ; s < ( 1 << N ) ; s ++ )
        coe[s] = Min( __builtin_popcount( s ), N - __builtin_popcount( s ) );
    XOR( coe, N, 1 );
    XOR( app, N, 1 );
    rep( i, 0, ( 1 << N ) - 1 ) res[i] = coe[i] * app[i];
    XOR( res, N, -1 );
    LL ans = 1e18;
    rep( i, 0, ( 1 << N ) - 1 )
        ans = Min( ans, res[i] );
    write( ans ), putchar( '\n' );
    return 0;
}