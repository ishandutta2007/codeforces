#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int INF = 0x3f3f3f3f;
const int MAXN = 4005;

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

int cost[MAXN][MAXN];
int dp[2][MAXN], pre, nxt;

int N, K;

int Cost( const int l, const int r ) {
    return ( cost[r][r] - cost[l - 1][r] - cost[r][l - 1] + cost[l - 1][l - 1] ) / 2;
}

void Divide( const int l, const int r, const int qL, const int qR ) {
    if( l > r || qL > qR ) return ;
    if( qL == qR ) {
        rep( j, l, r )
            dp[nxt][j] = dp[pre][qL] + Cost( qL + 1, j );
        return ;
    }
    int mid = ( l + r ) >> 1;
    int bst = -1; dp[nxt][mid] = INF;
    for( int i = qL ; i <= qR && i <= mid ; i ++ ) {
        int tmp = dp[pre][i] + Cost( i + 1, mid );
        if( tmp < dp[nxt][mid] ) bst = i, dp[nxt][mid] = tmp;
    }
    Divide( l, mid - 1, qL, bst );
    Divide( mid + 1, r, bst, qR );
}

int main() {
    read( N ), read( K );
    rep( i, 1, N ) rep( j, 1, N ) {
        int tmp; read( tmp );
        cost[i][j] = tmp + cost[i - 1][j] + cost[i][j - 1] - cost[i - 1][j - 1];
    }
    pre = 1, nxt = 0;
    rep( i, 0, N ) dp[nxt][i] = INF;
    dp[nxt][0] = 0;
    rep( i, 1, K ) {
        pre ^= 1, nxt ^= 1;
        Divide( 1, N, 0, N - 1 );
    }
    write( dp[nxt][N] ), putchar( '\n' );
    return 0;
}