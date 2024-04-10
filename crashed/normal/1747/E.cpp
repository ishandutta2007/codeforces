#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 1e9 + 7, inv2 = ( mod + 1 ) >> 1;
const int MAXN = 1.5e7 + 10;

template<typename _T>
inline void Read( _T &x ) {
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    if( f ) x = -x;
}

template<typename _T>
inline void Write( _T x ) {
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) Write( x / 10 );
    putchar( x % 10 + '0' );
}

int inv[MAXN];
int fac[MAXN], ifac[MAXN];

int N, M;

inline int Qkpow( int, int );
inline int Inv( const int &a ) { return Qkpow( a, mod - 2 ); }
inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

inline int C( int n, int m ) { return n < m ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

inline int Qkpow( int base, int indx ) {
    int ret = 1;
    while( indx ) {
        if( indx & 1 ) MulEq( ret, base );
        MulEq( base, base ), indx >>= 1;
    }
    return ret;
}

inline void Init( const int &n ) {
    fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
    ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
    rep( i, 1, n ) inv[i] = Mul( ifac[i], fac[i - 1] );
}

int main() {
    Init( 1.5e7 + 5 );
    int T; Read( T );
    while( T -- ) {
        Read( N ), Read( M );
        int K = N + M + 1, coe = ( mod - K / 2 ) % mod, ans = 0;
        int bnm = K, tmp, val1 = 1, val2 = 1;
        if( K & 1 ) AddEq( coe, K );
        rep( j, 1, K - 1 ) {
            tmp = Mul( bnm, Mul( K - j, inv[j + 1] ) );
            coe = ( K - j - 1 ) & 1 ? Sub( coe, Add( bnm, tmp ) ) :
                                      Add( coe, Add( bnm, tmp ) );
            MulEq( coe, inv2 ), bnm = tmp;
            AddEq( ans, Mul( Mul( coe, j + 1 ), Mul( val1, val2 ) ) );
            MulEq( val1, Mul( N + j, inv[j] ) );
            MulEq( val2, Mul( M + j, inv[j] ) );
        }
        Write( ans ), putchar( '\n' );
    }
    return 0;
}