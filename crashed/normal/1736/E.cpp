#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 1e9;
const int MAXN = 505;

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

int dp[2][MAXN][MAXN], tag[MAXN][MAXN];

int A[MAXN];

int N;

inline void Upt( int &x, const int &v ) {
    x = std :: max( x, v );
}

int main() {
    Read( N );
    rep( i, 1, N ) Read( A[i] );
    int pre = 1, nxt = 0;
    rep( i, 0, N ) rep( j, 0, N )
        dp[0][i][j] = dp[1][i][j] = tag[i][j] = - INF;
    dp[nxt][0][0] = 0, A[0] = - INF;
    rep( i, 1, N ) {
        pre ^= 1, nxt ^= 1;
        rep( j, 0, i - 1 ) rep( k, 0, N ) {
            if( dp[pre][j][k] < 0 ) continue;
            if( k ) Upt( dp[nxt][j + 1][k], dp[pre][j][k] + A[k] );
            int t = std :: max( k + 1, i );
            if( t <= N && j + t - i <= i )
                Upt( tag[j + t - i][t], dp[pre][j][k] );
            dp[pre][j][k] = - INF;
        }
        rep( j, 0, i ) rep( k, 1, N ) {
            Upt( dp[nxt][j][k], tag[j][k] + A[k] );
            if( j < i && k < N ) Upt( tag[j + 1][k + 1], tag[j][k] );
            tag[j][k] = - INF;
        }
    }
    int ans = - INF;
    rep( j, 0, N ) rep( k, 0, N )
        Upt( ans, dp[nxt][j][k] );
    Write( ans ), putchar( '\n' );
    return 0;
}