#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 505, MAXS = MAXN * MAXN;

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

int pool[3][MAXS << 1]; 
int *dp = pool[0] + MAXS, *real = pool[1] + MAXS, *tmp = pool[2] + MAXS;

int C[MAXN][MAXN], fac[MAXN];

int N, mod;

inline int Qkpow( int, int );
inline int Inv( const int &a ) { return Qkpow( a, mod - 2 ); }
inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

inline int Fix( const int &x ) { return ( x % mod + mod ) % mod; }

inline int Qkpow( int base, int indx ) {
    int ret = 1;
    while( indx ) {
        if( indx & 1 ) MulEq( ret, base );
        MulEq( base, base ), indx >>= 1;
    }
    return ret;
}

int main() {
    Read( N ), Read( mod );
    rep( i, 0, N ) {
        C[i][0] = C[i][i] = 1 % mod;
        rep( j, 0, i - 1 ) 
            C[i][j] = Add( C[i - 1][j], C[i - 1][j - 1] );
    }
    fac[0] = 1 % mod; rep( i, 1, N ) fac[i] = Mul( fac[i - 1], i );
    int R = ( N + 1 ) * N / 2;
    rep( i, -R, R ) real[i] = Fix( i );

    int ans = 0;
    dp[0] = 1, R = 0;
    rep( n, 1, N ) {
        int res = 0, su = 0, s1, s2;
        rep( i, n, R ) AddEq( su, dp[i] );
        per( d, n - 1, 1 )
            AddEq( res, Mul( n - d, su ) ), AddEq( su, dp[d] );
        AddEq( ans, Mul( res, Mul( C[N][n], fac[N - n] ) ) );
        R += n - 1, s1 = 0, s2 = 0;
        rep( i, -R, R ) {
            if( i - n >= -R ) {
                SubEq( s1, dp[i - n] );
                SubEq( s2, Mul( real[i - n], dp[i - n] ) );
            }
            tmp[i] = Add( Mul( real[n - i], s1 ), s2 );
            AddEq( s1, dp[i] ), AddEq( s2, Mul( real[i], dp[i] ) );
        }
        s1 = s2 = 0;
        per( i, R, -R ) {
            if( i + n <= R ) {
                SubEq( s1, dp[i + n] );
                SubEq( s2, Mul( real[i + n], dp[i + n] ) );
            }
            AddEq( tmp[i], Sub( Mul( real[n + i], s1 ), s2 ) );
            AddEq( s1, dp[i] ), AddEq( s2, Mul( real[i], dp[i] ) );
        }
        rep( i, -R, R ) AddEq( MulEq( dp[i], n ), tmp[i] );
    }
    Write( ans ), putchar( '\n' );
    return 0;
}