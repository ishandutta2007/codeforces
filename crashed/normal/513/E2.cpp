#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

typedef long long LL;

const LL INF = 1e18;
const int MAXN = 3e4 + 5, MAXK = 205;

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

LL dp[2][MAXN][2];
LL pref[MAXN];

int N, K;

inline void Upt( LL &x, const LL &v ) { x = std :: max( x, v ); }

int main() {
    Read( N ), Read( K );
    rep( i, 1, N ) Read( pref[i] );
    rep( i, 1, N ) pref[i] += pref[i - 1];
    int pre = 1, nxt = 0;
    rep( i, 0, N ) rep( j, 0, 1 )
        dp[0][i][j] = dp[1][i][j] = - INF;
    LL prefMn = INF, prefMx = - INF;
    rep( i, 0, N ) {
        dp[nxt][i][0] = pref[i] - prefMn;
        dp[nxt][i][1] = - pref[i] + prefMx;
        prefMn = std :: min( prefMn, pref[i] );
        prefMx = std :: max( prefMx, pref[i] );
    }
    LL ans = - INF;
    if( K == 1 ) {
        rep( i, 1, N ) Upt( ans, dp[nxt][i][0] );
    } else {
        rep( i, 2, K - 1 ) {
            pre ^= 1, nxt ^= 1;
            LL tsf[2][2] = { { - INF, - INF }, { - INF, - INF } };
            rep( i, 0, N ) {
                if( i ) {
                    Upt( dp[pre][i][0], dp[pre][i - 1][0] );
                    Upt( dp[pre][i][1], dp[pre][i - 1][1] );
                }
                dp[nxt][i][0] = dp[nxt][i][1] = - INF;
                Upt( dp[nxt][i][0], tsf[0][1] + 2 * pref[i] );
                Upt( dp[nxt][i][1], tsf[1][1] );
                Upt( dp[nxt][i][0], tsf[0][0] );
                Upt( dp[nxt][i][1], tsf[1][0] - 2 * pref[i] );

                Upt( tsf[0][1], dp[pre][i][1] - 2 * pref[i] );
                Upt( tsf[1][1], dp[pre][i][1] );
                Upt( tsf[0][0], dp[pre][i][0] );
                Upt( tsf[1][0], dp[pre][i][0] + 2 * pref[i] );
            }
        }
        prefMn = prefMx = - INF;
        rep( i, 0, N ) {
            if( i ) {
                Upt( dp[nxt][i][0], dp[nxt][i - 1][0] );
                Upt( dp[nxt][i][1], dp[nxt][i - 1][1] );
            }
            Upt( ans, - pref[i] + prefMn );
            Upt( ans, pref[i] + prefMx );
            Upt( prefMn, dp[nxt][i][0] + pref[i] );
            Upt( prefMx, dp[nxt][i][1] - pref[i] );
        }
    }
    Write( ans ), putchar( '\n' );
    return 0;
}