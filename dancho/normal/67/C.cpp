#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;
char A[4020], B[4020];
int ti, td, tr, te;
int dp[4020][4020];
int la[32], lb[32];

int price( int x, int y )
{
    if ( A[x] == B[y] ) return 0;
    return tr;
}

int main()
{
    int i, j, k;
    int x, y;

    scanf( "%d %d %d %d", &ti, &td, &tr, &te );
    scanf( "%s", A );
    scanf( "%s", B );

//    memset( best, 127, sizeof( best ) );

    n = strlen( A ); m = strlen( B );
    dp[0][m] = m*ti;
    for ( i = 0; i < m; i++ )
        dp[0][i] = i*ti;
    dp[n][0] = n*td;
    for ( i = 0; i < n; i++ )
        dp[i][0] = i*td;
    memset( la, -1, sizeof( la ) );
    for ( i = 0; i < n; i++ )
    {
        memset( lb, -1, sizeof( lb ) );
        for ( j = 0; j < m; j++ )
        {
            x = i+1; y = j+1;
            dp[x][y] = (1<<29);
            dp[x][y] = min( dp[x][y], dp[x][y-1] + ti );
            dp[x][y] = min( dp[x][y], dp[x-1][y] + td );
            dp[x][y] = min( dp[x][y], dp[x-1][y-1] + price( i, j ) );
            if ( ( la[B[j]-'a'] != -1 ) && ( lb[A[i]-'a'] != -1 ) )
                dp[x][y] = min( dp[x][y], dp[la[B[j]-'a']][lb[A[i]-'a']] + td*(i-la[B[j]-'a']-1) + ti*(j-lb[A[i]-'a']-1) + te );

            //cout << "DP " << x << " " << y << " " << dp[x][y] << endl;
            lb[B[j]-'a'] = j;
        }
        la[A[i]-'a'] = i;
    }
    printf( "%d\n", dp[n][m] );
    return 0;
}