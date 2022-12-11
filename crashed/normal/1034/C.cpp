#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int mod = 1e9 + 7;
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

int contri[MAXN], dp[MAXN];

LL su[MAXN];
int fath[MAXN];

int N;

inline LL Gcd( LL x, LL y ) { for( LL z ; y ; z = x, x = y, y = z % y ); return x; }

int main() {
    read( N );
    rep( i, 1, N ) read( su[i] );
    rep( i, 2, N ) read( fath[i] );
    per( i, N, 2 ) su[fath[i]] += su[i];
    rep( i, 1, N ) {
        LL tmp = su[1] / Gcd( su[1], su[i] );
        if( tmp <= N ) contri[tmp] ++;
    }
    for( int d = N ; d ; d -- )
        for( int k = d << 1 ; k <= N ; k += d )
            contri[k] += contri[d];
    for( int d = N ; d ; d -- ) {
        dp[d] = 1;
        for( int k = d << 1 ; k <= N ; k += d )
            ( dp[d] += dp[k] ) %= mod;
        dp[d] *= ! ( su[1] % d ) && contri[d] == d;
    }
    write( dp[1] ), putchar( '\n' );
    return 0;
}