#include <cmath>
#include <cstdio>
#include <iostream>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2005;

double dp[MAXN][MAXN];

double P;
int N, T;

int main() {
    scanf( "%d%lf%d", &N, &P, &T );
    dp[0][0] = 1;
    rep( i, 1, T ) {
        dp[i][0] = dp[i - 1][0] * ( 1 - P );
        rep( j, 1, N - 1 )
            dp[i][j] = dp[i - 1][j - 1] * P + dp[i - 1][j] * ( 1 - P );
        dp[i][N] = dp[i - 1][N] + dp[i - 1][N - 1] * P;
    }
    double ans = 0;
    rep( j, 1, N ) ans += j * dp[T][j];
    printf( "%.6f\n", ans );
    return 0;
}