#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 1e9 + 7;
const int MAXN = 1e5;

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

int fac[MAXN], ifac[MAXN];

int N, K;

inline int Qkpow( int, int );
inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Inv( const int a ) { return Qkpow( a, mod - 2 ); }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }
inline int C( int n, int m ) { return n < m ? 0 : Mul( fac[n], Mul( ifac[m], ifac[n - m] ) ); }

inline int Qkpow( int base, int indx ) {
    int ret = 1;
    while( indx ) {
        if( indx & 1 ) ret = Mul( ret, base );
        base = Mul( base, base ), indx >>= 1;
    }
    return ret;
}

inline void Init( const int n ) {
    fac[0] = 1; rep( i, 1, n ) fac[i] = Mul( fac[i - 1], i );
    ifac[n] = Inv( fac[n] ); per( i, n - 1, 0 ) ifac[i] = Mul( ifac[i + 1], i + 1 );
}

int main() {
    read( N ), read( K ), Init( N << 1 );
    int lo = ( N + 1 ) / 2 * 2 - 1 - ( N & 1 ), 
        le = N / 2 * 2 - ( N % 2 == 0 );

    int ans = 0, tmp;
    rep( p, 0, lo ) rep( q, 0, le ) {
        if( p + q < K ) continue;
        tmp = Mul( Mul( C( lo + 1 - p, p ), C( le + 1 - q, q ) ), fac[N - p - q] );
        ans = ( p + q - K ) & 1 ? Sub( ans, Mul( tmp, C( p + q, K ) ) ) : 
                                  Add( ans, Mul( tmp, C( p + q, K ) ) );
    }
    write( ans ), putchar( '\n' );
    return 0;
}