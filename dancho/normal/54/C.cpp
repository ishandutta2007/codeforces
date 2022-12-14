#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;

int n;
double K;
long long l[1024], r[1024];
long long fi[32], la[32];
long long b1[1024];
double p1[1024];
double dp[1024][1024];

long long intersect( long long l1, long long r1, long long l2, long long r2 )
{
    if ( l1 > l2 )
        return intersect( l2, r2, l1, r1 );
    if ( ( r1 < l2 ) || ( r2 < l1 ) )
        return 0LL;
    if ( r2 < r1 )
    {
        return r2-l2+1;
    }
    return r1-l2+1;
}

int main()
{
    int i, j, k;

    fi[0] = 1; la[0] = 1;
    for ( i = 1; i <= 18; i++ )
    {
        fi[i] = fi[i-1]*10;
        la[i] = la[i-1]*10+9;
    }

    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%I64d %I64d", &l[i], &r[i] );
    }
    scanf( "%lf", &K );

    for ( i = 1; i <= n; i++ )
    {
        b1[i] = 0;
        for ( j = 0; j <= 18; j++ )
        {
            b1[i] = b1[i] + intersect( l[i], r[i], fi[j], la[j] );
        }
        p1[i] = (double)b1[i]/(double)(r[i]-l[i]+1);
    }

    dp[0][0] = 1;
    dp[0][1] = 0;
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 0; j <= i; j++ )
        {
            dp[i][j] = 0;
            dp[i][j] = dp[i][j] + dp[i-1][j]*(1-p1[i]);
            if ( j > 0 )
            {
                dp[i][j] = dp[i][j] + dp[i-1][j-1]*p1[i];
            }
        }
    }
    double sol = 0;
    for ( j = 0; j <= n; j++ )
    {
        if ( j >= (double)n*K/100.0 )
            sol = sol + dp[n][j];
    }
    printf( "%.15lf\n", sol );
    return 0;
}