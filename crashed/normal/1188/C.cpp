#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 998244353;
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

template<typename _T>
_T ABS( const _T a ) {
    return a < 0 ? -a : a;
}

int dp[2][MAXN], pref[MAXN];

int A[MAXN];

int N, K;

inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }

int Work( const int v ) {
    int pre = 1, nxt = 0;
    rep( i, 1, N ) dp[nxt][i] = 1;
    rep( t, 2, K ) {
        pre ^= 1, nxt ^= 1, pref[0] = 0;
        for( int i = 1, j = 0 ; i <= N ; i ++ ) {
            while( j < N && A[i] - A[j + 1] >= v ) j ++;
            dp[nxt][i] = pref[j], pref[i] = Add( pref[i - 1], dp[pre][i] );
        }
    }
    int ret = 0;
    rep( i, 1, N ) ret = Add( ret, dp[nxt][i] );
    return ret;
}

int main() {
    read( N ), read( K );
    rep( i, 1, N ) read( A[i] );
    std :: sort( A + 1, A + 1 + N );
    int lim = A[N] / ( K - 1 ), ans = 0;
    rep( i, 1, lim ) ans = Add( ans, Work( i ) );
    write( ans ), putchar( '\n' );
    return 0;
}