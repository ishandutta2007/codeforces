#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
const int MAXN = 405;

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

template<typename _T>
inline _T Min( const _T &a, const _T &b ) {
    return a < b ? a : b;
}

int dp[2][MAXN][MAXN][3][3];
int suf[MAXN][MAXN];

int N, lim[26];

inline int Qkpow( int, int );
inline int Inv( const int &a ) { return Qkpow( a, mod - 2 ); }
inline int Mul( int x, const int &v ) { return 1ll * x * v % mod; }
inline int Sub( int x, const int &v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, const int &v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int& MulEq( int &x, const int &v ) { return x = 1ll * x * v % mod; }
inline int& SubEq( int &x, const int &v ) { return ( x -= v ) < 0 ? ( x += mod ) : x; }
inline int& AddEq( int &x, const int &v ) { return ( x += v ) >= mod ? ( x -= mod ) : x; }

inline int Qkpow( int base, int indx ) {
    int ret = 1;
    while( indx ) {
        if( indx & 1 ) MulEq( ret, base );
        MulEq( base, base ), indx >>= 1;
    }
    return ret;
}

int main() {
    Read( N );
    rep( i, 0, 25 ) Read( lim[i] );
    int pre = 1, nxt = 0;
    rep( i, 0, 25 ) rep( j, 0, 25 )
        AddEq( dp[nxt][( i == 0 ) + ( j == 0 )][( i == 1 ) + ( j == 1 )][Min( i, 2 )][Min( j, 2 )], 1 );
    rep( i, 3, N ) {
        pre ^= 1, nxt ^= 1;
        rep( j, 0, i - 1 ) 
            rep( k, 0, i - j - 1 )
                rep( c, 0, 2 ) rep( d, 0, 2 ) {
                    if( ! dp[pre][j][k][c][d] ) continue;
                    if( c ) AddEq( dp[nxt][j + 1][k][d][0], dp[pre][j][k][c][d] );
                    if( c ^ 1 ) AddEq( dp[nxt][j][k + 1][d][1], dp[pre][j][k][c][d] );
                    AddEq( dp[nxt][j][k][d][2], Mul( dp[pre][j][k][c][d], 24 - ( c == 2 ) ) );
                    dp[pre][j][k][c][d] = 0;
                }
    }
    int ans = 0;
    rep( j, 0, N )
        rep( k, 0, N - j )
            rep( c, 0, 2 ) rep( d, 0, 2 )
                AddEq( suf[j][k], dp[nxt][j][k][c][d] );
    per( j, N, 0 ) per( k, N, 0 )
        AddEq( suf[j][k], Sub( Add( suf[j + 1][k], suf[j][k + 1] ), suf[j + 1][k + 1] ) );
    AddEq( ans, suf[0][0] );
    rep( j, 0, 25 ) SubEq( ans, suf[lim[j] + 1][0] );
    rep( j, 0, 25 ) 
        rep( k, j + 1, 25 ) 
            AddEq( ans, suf[lim[j] + 1][lim[k] + 1] );
    Write( ans ), putchar( '\n' );
    return 0;
}