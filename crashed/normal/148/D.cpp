#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1005;

long double dp[MAXN << 1][MAXN];

int W, B;

int main() {
    // freopen( "", "r", stdin );
    // freopen( "", "w", stdout );
    scanf( "%d %d", &W, &B );
    dp[0][W] = 1;
    long double ans = 0;
    rep( i, 0, W + B - 1 ) {
        int all = W + B - i - ( i >> 1 );
        if( all <= 0 ) break;
        for( int j = 0 ; j <= W && j <= all ; j ++ ) {
            int k = all - j;
            if( dp[i][j] == 0 ) continue;
            if( ( i + 1 ) & 1 ) {
                ans += dp[i][j] * j / all;
                dp[i + 1][j] += dp[i][j] * k / all;
            } else {
                if( all == 1 ) {
                    dp[i + 1][j] += dp[i][j] * k / all;
                    if( j ) dp[i + 1][j - 1] += dp[i][j] * j / all;
                } else {
                    dp[i + 1][j] += dp[i][j] * k / all * ( k - 1 ) / ( all - 1 );
                    if( j ) dp[i + 1][j - 1] += dp[i][j] * k / all * j / ( all - 1 );
                }
            }
        }
    }
    printf( "%.9Lf\n", ans );
    return 0;
}