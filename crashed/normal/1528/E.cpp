#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353, inv2 = ( mod + 1 ) >> 1, inv6 = ( mod + 1 ) / 6;
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

int dp[MAXN], pre[MAXN];

int N;

inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

inline int C2( const int x ) { return Mul( inv2, Mul( x, Sub( x, 1 ) ) ); }
inline int C3( const int x ) { return Mul( inv6, Mul( x, Mul( Sub( x, 1 ), Sub( x, 2 ) ) ) ); }

int main() {
    read( N );
     dp[0] = 1,  dp[1] = 2;
    pre[0] = 1, pre[1] = 3;
    rep( i, 2, N ) {
        dp[i] = Add( Add( dp[i - 1], Mul( dp[i - 1], pre[i - 2] ) ), 
                     Add( C2( dp[i - 1] ), dp[i - 1] ) );
        pre[i] = Add( pre[i - 1], dp[i] );
    }
    int ans = dp[N];
    if( N > 1 ) ans = Add( ans, Mul( Add( pre[N - 2], C2( pre[N - 2] ) ), dp[N - 1] ) );
    if( N > 1 ) ans = Add( ans, Mul( pre[N - 2], Add( C2( dp[N - 1] ), dp[N - 1] ) ) );
    ans = Add( ans, Add( C3( dp[N - 1] ), Add( Mul( 2, C2( dp[N - 1] ) ), dp[N - 1] ) ) );
    ans = Sub( Mul( ans, 2 ), 1 );
    rep( i, 1, N - 1 )
        ans = Add( ans, Mul( Sub( dp[i], dp[i - 1] ), Sub( dp[N - 1 - i], 1 ) ) );
    write( ans ), putchar( '\n' );
    return 0;
}