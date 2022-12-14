#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n, m;
char s[200020][25];
char make[4000100];

int pbeg[200020], pend[200020];

int dp[200020];
int tdp[200020];
int mi[1<<20][21];

int toNumBeg( int x, int ln )
{
    int i, res = 0;
    for ( i = 0; i < ln; i++ )
    {
        if ( s[x][i] == '1' )
            res = res + (1<<i);
    }
    return res;
}

int toNumEnd( int x, int ln )
{
    int i, res = 0;
    for ( i = m-ln; i < m; i++ )
    {
        if ( s[x][i] == '1' )
            res = res + (1<<(i-(m-ln)));
    }
    return res;
}

int main()
{
    int i, j, k;
    int en;

    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%s", s[i] );
    }
    m = strlen( s[1] );
    pbeg[1] = 0;
    pend[1] = m-1;
    for ( i = 0; i < m; i++ )
    {
        make[i] = s[1][i];
    }
    en = m;
    for ( i = 2; i <= n; i++ )
    {
        for ( j = m; j > 0; j-- )
        {
            for ( k = 0; k < j; k++ )
            {
                if ( make[en-j+k] != s[i][k] )
                    break;
            }
            if ( k >= j ) break;
        }
        pbeg[i] = en-j;
        for ( k = j; k < m; k++ )
        {
            make[en++] = s[i][k];
        }
        pend[i] = en-1;
//        cout << "POS " << i << " " << pbeg[i] << " " << pend[i] << endl;
    }

    memset( mi, 127, sizeof( mi ) );
    memset( dp, 127, sizeof( dp ) );

    dp[1] = m;

    for ( i = 2; i <= n; i++ )
    {
        dp[i] = pend[i-1]+1+m;
//        dp[i] = pend[i]+1;
        for ( j = 0; j <= m; j++ )
        {
            k = toNumBeg( i, j );
//            cout << "QUE " << i << " " << k << " " << j << " " << mi[k][j] << endl;
            if ( pend[i-1]+1 + mi[k][j] + m-j < dp[i] )
                dp[i] = pend[i-1]+1 + mi[k][j] + m-j;
        }
        for ( j = 0; j <= m; j++ )
        {
            k = toNumEnd( i-1, j );
            mi[k][j] = min( mi[k][j], dp[i]-pbeg[i]-m );
//            cout << "MIU " << k << " " << j << " " << mi[k][j] << endl;
        }
//        cout << i << " " << dp[i] << " " << pend[i] << endl;
    }
    int ans = min( dp[n], pend[n]+1 );
    for ( i = 1; i < n; i++ )
    {
        ans = min( ans, dp[i] + pend[n] - pbeg[i]+1-m );
    }
    cout << ans << endl;
    return 0;
}