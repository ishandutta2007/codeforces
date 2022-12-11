#include <map>
#include <cmath>
#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1e5 + 5;

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

template<typename _T>
_T Min( const _T a, const _T b ) {
    return a < b ? a : b;
}

LL val[MAXN];
int A[MAXN];

int N, mx = 0;

int main() {
    // freopen( ".in", "r", stdin );
    // freopen( ".out", "w", stdout );
    read( N );
    rep( i, 1, N ) read( A[i] ), mx = Max( mx, A[i] );
    int lim = sqrt( mx ), ans = 0;
    rep( d, - lim, lim ) {
        rep( i, 1, N ) val[i] = A[i] - 1ll * i * d;
        std :: sort( val + 1, val + 1 + N );
        for( int l = 1, r ; l <= N ; l = r ) {
            for( r = l ; r <= N && val[l] == val[r] ; r ++ );
            ans = Max( ans, r - l );
        }
    }
    rep( i, 1, N ) {
        int tot = 0;
        rep( j, Max( 1, i - lim ), i - 1 )
            if( ! ( ( A[i] - A[j] ) % ( i - j ) ) )
                val[++ tot] = ( A[i] - A[j] ) / ( i - j );
        rep( j, i + 1, Min( i + lim, N ) )
            if( ! ( ( A[j] - A[i] ) % ( j - i ) ) )
                val[++ tot] = ( A[j] - A[i] ) / ( j - i );
        std :: sort( val + 1, val + 1 + tot );
        for( int l = 1, r ; l <= tot ; l = r ) {
            for( r = l ; r <= tot && val[l] == val[r] ; r ++ );
            ans = Max( ans, r - l + 1 );
        }
    }
    write( N - ans ), putchar( '\n' );
    return 0;
}