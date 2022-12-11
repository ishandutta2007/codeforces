#include <cmath>
#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXN = 1005;

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

int prime[MAXN], pn;
bool isPrime[MAXN];

void EulerSieve( const int n ) {
    for( int i = 2 ; i <= n ; i ++ ) {
        if( ! isPrime[i] ) prime[++ pn] = i;
        for( int j = 1 ; j <= pn && 1ll * i * prime[j] <= n ; j ++ ) {
            isPrime[i * prime[j]] = true;
            if( ! ( i % prime[j] ) ) break;
        }
    }
}

LL Qkpow( LL base, int indx ) {
    LL ret = 1;
    while( indx ) {
        if( indx & 1 ) ret *= base;
        base *= base, indx >>= 1;
    }
    return ret;
}

int main() {
    int T; read( T ), EulerSieve( 1e3 );
    int lim; for( lim = 1 ; Qkpow( prime[lim], 4 ) <= 1e9 ; lim ++ );
    while( T -- ) {
        LL prm = 1;
        for( int l = 1, r ; l < lim ; l = r ) {
            LL prod = 1, d;
            for( r = l ; r < lim && prime[r] <= 1e18 / prod ; prod *= prime[r ++] );
            printf( "? %lld\n", prod ), fflush( stdout );
            read( d ), prm *= d;
        }
        LL dvs = 1, alr = 1;
        for( int i = 1 ; i < lim ; i ++ ) {
            if( prm % prime[i] ) continue;
            int idx = floor( 18 / log10( prime[i] ) );
            printf( "? %lld\n", Qkpow( prime[i], idx ) ), fflush( stdout );
            LL d; read( d ), alr *= d, idx = 0;
            for( ; d > 1 ; d /= prime[i], idx ++ );
            dvs *= idx + 1;
        }
        if( dvs <= 2 ) printf( "! %lld\n", dvs + 7 );
        else {
            int upp; for( upp = 1 ; Qkpow( prime[upp], 3 ) * alr <= 1e9 ; upp ++ );
            for( int l = lim, r ; l < upp ; l = r ) {
                LL prod = 1, d;
                for( r = l ; r < upp && prime[r] <= 1e18 / prod ; prod *= prime[r ++] );
                printf( "? %lld\n", prod ), fflush( stdout );
                read( d ), prm *= d;
            }
            for( int i = lim ; i < upp ; i ++ ) {
                if( prm % prime[i] ) continue;
                int idx = floor( 18 / log10( prime[i] ) );
                printf( "? %lld\n", Qkpow( prime[i], idx ) ), fflush( stdout );
                LL d; read( d ), idx = 0;
                for( ; d > 1 ; d /= prime[i], idx ++ );
                dvs *= idx + 1;
            }
            printf( "! %lld\n", dvs << 1 );
        }
    }
    return 0;
}