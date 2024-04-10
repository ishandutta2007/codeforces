#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 5e5 + 5;

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
_T MAX( const _T a, const _T b ) {
    return a > b ? a : b;
}

int dp[MAXN], app[MAXN];

int lef[MAXN], rig[MAXN];
int A[MAXN];
int N;

int main() {
    read( N );
    rep( i, 1, N ) read( A[i] ), rig[A[i]] = i;
    per( i, N, 1 ) lef[A[i]] = i, app[A[i]] ++;
    rep( i, 1, N ) {
        dp[i] = dp[i - 1];
        if( i == rig[A[i]] )
            dp[i] = MAX( dp[i], dp[lef[A[i]] - 1] + app[A[i]] );
    }
    rep( i, 1, N ) app[i] = 0;
    int ans = dp[N];
    per( i, N, 1 )
        ans = MAX( ans, ( ++ app[A[i]] ) + dp[i - 1] );
    write( N - ans ), putchar( '\n' );
    return 0;
}