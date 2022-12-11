#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int mod = 998244353, INF = 1e9;
const int MAXN = 30, MAXS = ( 1 << 23 ) + 5, MAXH = ( 1 << 12 ) + 5, MAXL = 2e4 + 5;

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

int g[MAXS];

char str[MAXL];
int lApp[MAXH][MAXN], rApp[MAXH][MAXN];

int N, L, R;

inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

int main() {
    read( N );
    L = N >> 1, R = N - L;
    for( int i = 0 ; i < N ; i ++ ) {
        scanf( "%s", str );
        for( int j = 0, x ; str[j] ; j ++ ) {
            x = str[j] - 'a';
            ( i < L ? lApp[1 << i][x] : rApp[1 << ( i - L )][x] ) ++;
        }
    }
    for( int j = 0 ; j < 26 ; j ++ )
        lApp[0][j] = rApp[0][j] = INF;
    for( int S = 1 ; S < ( 1 << L ) ; S ++ )
        if( __builtin_popcount( S ) > 1 )
            for( int j = 0 ; j < 26 ; j ++ )
                lApp[S][j] = MIN( lApp[S & ( S - 1 )][j],
                                  lApp[S & ( - S )][j] );
    for( int S = 1 ; S < ( 1 << R ) ; S ++ )
        if( __builtin_popcount( S ) > 1 )
            for( int j = 0 ; j < 26 ; j ++ )
                rApp[S][j] = MIN( rApp[S & ( S - 1 )][j],
                                  rApp[S & ( - S )][j] );
    for( int S = 1 ; S < ( 1 << N ) ; S ++ ) {
        g[S] = 1;
        int lS = S & ( ( 1 << L ) - 1 ), 
            rS = ( S >> L ) & ( ( 1 << R ) - 1 );
        for( int j = 0 ; j < 26 ; j ++ ) {
            int o = MIN( lApp[lS][j], rApp[rS][j] );
            if( o == 1e9 ) continue;
            g[S] = Mul( g[S], o + 1 );
        }
    }
    for( int i = 0 ; i < N ; i ++ )
        for( int S = 1 ; S < ( 1 << N ) ; S ++ )
            if( ! ( S >> i & 1 ) ) g[S] = Sub( g[S], g[S | ( 1 << i )] );
    LL ans = 0; int all = 0;
    for( int S = 1 ; S < ( 1 << N ) ; S ++ )
        all = Add( all, g[S] );
    for( int i = 0 ; i < N ; i ++ )
        for( int S = 0 ; S < ( 1 << N ) ; S ++ )
            if( S >> i & 1 ) g[S] = Add( g[S], g[S ^ ( 1 << i )] );
    for( int S = 1 ; S < ( 1 << N ) ; S ++ ) {
        int res = Sub( all, g[S ^ ( ( 1 << N ) - 1 )] ), coe = 0;
        for( int i = 0 ; i < N ; i ++ )
            if( S >> i & 1 ) coe += i + 1;
        coe *= __builtin_popcount( S );
        ans ^= 1ll * coe * res;
    }
    write( ans ), putchar( '\n' );
    return 0;
}