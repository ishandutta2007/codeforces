#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const int MAXM = 25, MAXS = ( 1 << 20 ) + 5;

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

LL E[MAXS], coe[MAXS], B[MAXM];

int N, M; LL mod, T;

inline LL Qkpow( LL, LL );
inline LL Inv( const LL &a ) { return Qkpow( a, mod - 2 ); }

inline LL Mul( const LL &a, const LL &b ) {
    return ( a * b - ( LL ) ( ( long double ) a / mod * b ) * mod + mod ) % mod;
}

inline LL Sub( LL x, const LL &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline LL Add( LL x, const LL &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline LL& MulEq( LL &x, const LL &v ) { return x = Mul( x, v ); }
inline LL& SubEq( LL &x, const LL &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline LL& AddEq( LL &x, const LL &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

inline LL Qkpow( LL base, LL indx ) {
    LL ret = 1;
    while( indx ) {
        if( indx & 1 ) MulEq( ret, base );
        MulEq( base, base ), indx >>= 1;
    }
    return ret;
}

void XOR( LL *coe, const int &n, const int &typ ) {
    int L = 1 << n;
    for( int s = 1 ; s < L ; s <<= 1 )
        for( int i = 0 ; i < L ; i += s << 1 )
            for( int j = 0 ; j < s ; j ++ ) {
                LL a = coe[i + j], b = coe[i + j + s];
                coe[i + j] = Add( a, b );
                coe[i + j + s] = Sub( a, b );
            }
}

int main() {
    read( M ), read( T ), read( mod ); 
    N = 1 << M, mod *= N;
    rep( i, 0, N - 1 ) read( E[i] );
    rep( i, 0, M ) read( B[i] );
    rep( i, 0, N - 1 ) coe[i] = B[__builtin_popcount( i )];
    XOR( E, M, 1 );
    XOR( coe, M, 1 );
    rep( i, 0, N - 1 ) MulEq( E[i], Qkpow( coe[i], T ) );
    XOR( E, M, -1 );
    rep( i, 0, N - 1 )
        write( E[i] >> M ), putchar( '\n' );
    return 0;
}