#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int mod = 998244353, phi = mod - 1, g = 3;
const int MAXN = 3e5 + 5;

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

int fac[MAXN], ifac[MAXN], inv[MAXN];

int P[MAXN], A[MAXN], B[MAXN];

int N; LL M;

inline int Qkpow( int, LL );
inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int Qkpow( int base, LL indx ) {
    int ret = 1;
    while( indx ) {
        if( indx & 1 ) ret = Mul( ret, base );
        base = Mul( base, base ), indx >>= 1;
    }
    return ret;
}

namespace Basic {
    const int L = 18;

    int w[( 1 << L ) + 5];

    void NTTInit( const int n = 1 << L ) {
        w[0] = 1, w[1] = Qkpow( g, phi / n );
        rep( i, 2, n - 1 ) w[i] = Mul( w[i - 1], w[1] );
    }

    void DIF( int *coe, const int n ) {
        int *wp, p, e, o;
        for( int s = n >> 1 ; s ; s >>= 1 )
            for( int i = 0 ; i < n ; i += s << 1 ) {
                wp = w, p = ( 1 << L ) / ( s << 1 );
                for( int j = 0 ; j < s ; j ++, wp += p ) {
                    e = coe[i + j], o = coe[i + j + s];
                    coe[i + j] = Add( e, o );
                    coe[i + j + s] = Mul( *wp, Sub( e, o ) );
                }
            }
    }

    void DIT( int *coe, const int n ) {
        int *wp, p, k;
        for( int s = 1 ; s < n ; s <<= 1 )
            for( int i = 0 ; i < n ; i += s << 1 ) {
                wp = w, p = ( 1 << L ) / ( s << 1 );
                for( int j = 0 ; j < s ; j ++, wp += p )
                    k = Mul( *wp, coe[i + j + s] ),
                    coe[i + j + s] = Sub( coe[i + j], k ),
                    coe[i + j] = Add( coe[i + j], k );
            }
        int inv = Inv( n );
        std :: reverse( coe + 1, coe + n );
        for( int i = 0 ; i < n ; i ++ ) coe[i] = Mul( coe[i], inv );
    }
}

void Init( const int n ) {
    fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
    ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
    rep( i, 1, n ) inv[i] = Mul( ifac[i], fac[i - 1] );
}

void Transform( int *p ) {
    int L = 1; for( ; L < 2 * N ; L <<= 1 );
    rep( i, 0, L - 1 ) A[i] = B[i] = 0;
    rep( i, 0, N - 1 ) 
        A[i] = Mul( P[i], fac[i] ), B[i] = ifac[i];
    std :: reverse( A, A + N );
    Basic :: DIF( A, L ), Basic :: DIF( B, L );
    rep( i, 0, L - 1 ) A[i] = Mul( A[i], B[i] );
    Basic :: DIT( A, L );
    rep( i, 0, N - 1 ) {
        int res = Mul( ifac[i], A[N - 1 - i] );
        p[i] = i & 1 ? Sub( 0, res ) : res;
    }
}

int main() {
    read( N ), read( M );
    rep( i, 0, N ) read( P[i] );
    Init( ++ N ), Basic :: NTTInit();
    Transform( P );
    rep( i, 0, N - 1 ) 
        P[i] = Mul( P[i], Qkpow( inv[i + 1], M ) );
    Transform( P );
    rep( i, 0, N - 1 ) write( P[i] ), putchar( i == N - 1 ? '\n' : ' ' );
    return 0;
}