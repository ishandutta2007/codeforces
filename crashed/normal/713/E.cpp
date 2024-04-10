#include <cstdio>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXN = 1e6 + 5;

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
inline _T Max( const _T &a, const _T &b ) {
    return a > b ? a : b;
}

int dp[MAXN];

int A[MAXN], tmp[MAXN];

int N, M;

inline void Regularize() {
    std :: sort( A + 1, A + 1 + N );

    int idx = 1, mxLen = A[2] - A[1];
    rep( i, 2, N )
        if( A[i % N + 1] - A[i] + M * ( i == N ) > mxLen )
            idx = i, mxLen = A[i % N + 1] - A[i] + M * ( i == N );
    int layer = idx == N;
    for( int i = 1, j = idx % N + 1 ; i <= N ; i ++, j = j % N + 1 ) {
        tmp[i] = A[j] + layer * M;
        if( j == N ) layer ++;
    }
    rep( i, 1, N ) A[i] = tmp[i];
    per( i, N, 1 ) A[i] -= A[1] - 1;
}

inline bool Chk( const int &L ) {
    dp[1] = 1;
    // 1 to the left
    rep( i, 2, N ) {
        dp[i] = - INF;
        if( dp[i - 1] >= A[i] - 1 ) dp[i] = Max( dp[i], A[i] + L );
        if( dp[i - 1] >= A[i] - L - 1 ) dp[i] = Max( dp[i], A[i] );
        if( i > 2 && dp[i - 2] >= A[i] - L - 1 ) dp[i] = Max( dp[i], A[i - 1] + L );
    }
    if( dp[N] + L >= M ) return true;
    if( A[1] + L < A[2] - L ) return false;
    dp[1] = dp[2] = Max( A[1] + L, A[2] );
    rep( i, 3, N ) {
        dp[i] = - INF;
        if( dp[i - 1] >= A[i] - 1 ) dp[i] = Max( dp[i], A[i] + L );
        if( dp[i - 1] >= A[i] - L - 1 ) dp[i] = Max( dp[i], A[i] );
        if( i > 2 && dp[i - 2] >= A[i] - L - 1 ) dp[i] = Max( dp[i], A[i - 1] + L );
    }
    if( dp[N] + Max( L - A[2] + 1, 0 ) >= M ) return true;
    return false;
}

int main() {
    // freopen( "expansion.in", "r", stdin );
    // freopen( "expansion.out", "w", stdout );
    Read( M ), Read( N );
    rep( i, 1, N ) Read( A[i] );
    if( N == 1 ) {
        Write( M - 1 ), putchar( '\n' );
        return 0;
    }
    // if( N == 2 ) {
    //     Write( Max( A[2] - A[1], A[1] - A[2] + M ) - 1 ), putchar( '\n' );
    //     return 0;
    // }
    Regularize();

    int l = 0, r = A[1] + M - A[N] - 1, mid;
    while( l < r ) {
        mid = ( l + r ) >> 1;
        if( Chk( mid ) ) r = mid;
        else l = mid + 1;
    }
    Write( l ), putchar( '\n' );
    return 0;
}