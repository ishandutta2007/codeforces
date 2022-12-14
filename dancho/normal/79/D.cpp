#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, k, l;

int d[10020];
int len[10020];
int a[128], x[16];

int ln[32][32];

vector<int> nec;
vector<int> g[10020];

int dp[1<<20];

int getDP( int mask )
{
    if ( dp[mask] != -1 )
        return dp[mask];
    int i, j, k;
    for ( i = 0; i < nec.size(); i++ )
    {
        if ( (mask&(1<<i)) == 0 )
            break;
    }
    if ( i >= nec.size() )
    {
        dp[mask] = 0;
        return dp[mask];
    }
    k = (1<<29);
    for ( j = i+1; j < nec.size(); j++ )
    {
        if ( (mask&(1<<j)) == 0 )
        {
            if ( ln[i][j] > -1 )
            {
                k = min( k, ln[i][j] + getDP( mask|(1<<j)|(1<<i) ) );
            }
        }
    }
    dp[mask] = k;
    return dp[mask];
}

void bfs( int st )
{
    int i, j, u;
    int v;
    queue<int> q;
    memset( len, -1, sizeof( len ) );

    q.push( st );
    len[st] = 0;
    while ( q.size() > 0 )
    {
        v = q.front();
        q.pop();
        for ( i = 0; i < g[v].size(); i++ )
        {
            u = g[v][i];
            if ( len[u] == -1 )
            {
                len[u] = len[v] + 1;
                q.push( u );
            }
        }
    }

    for ( i = 0; i < nec.size(); i++ )
    {
        if ( nec[i] == st ) break;
    }
    v = i;
    for ( i = 0; i < nec.size(); i++ )
    {
        if ( i == v ) continue;
        ln[v][i] = len[nec[i]];
    }
}

int main()
{
    int i, j;

    memset( d, -1, sizeof( d ) );

    scanf( "%d %d %d", &n, &k, &l );

    for ( j = 1; j <= k; j++ )
        scanf( "%d", &x[j] );
    for ( i = 1; i <= l; i++ )
        scanf( "%d", &a[i] );

    for ( i = 1; i <= k; i++ )
    {
        if ( x[i] == 1 )
        {
            d[1] = 1;
            break;
        }
    }
    if ( d[1] == -1 ) d[1] = 0;

    for ( i = 1; i <= k; i++ )
    {
        if ( x[i] > 1 )
        {
            for ( j = 1; j <= k; j++ )
            {
                if ( x[i]-1 == x[j] )
                {
                    d[x[i]] = 0;
                    break;
                }
            }
            if ( d[x[i]] == -1 ) d[x[i]] = 1;
        }
    }
    for ( i = 2; i <= n+1; i++ )
    {
        if ( d[i] == -1 )
        {
            for ( j = 1; j <= k; j++ )
            {
                if ( i-1 == x[j] )
                {
                    d[i] = 1;
                    break;
                }
            }
            if ( d[i] == -1 ) d[i] = 0;
        }
    }

    for ( i = 1; i <= n+1; i++ )
    {
        if ( d[i] == 1 )
        {
            nec.push_back( i );
//            cout << "NEC " << i << endl;
        }
    }

    for ( i = 1; i <= l; i++ )
    {
        for ( j = 1; j+a[i] <= n+1; j++ )
        {
            g[j].push_back( j+a[i] );
            g[j+a[i]].push_back( j );
        }
    }
    if ( nec.size() % 2 == 1 )
    {
        printf( "-1\n" );
        return 0;
    }

    memset( ln, -1, sizeof( ln ) );
    for ( i = 0; i < nec.size(); i++ )
    {
        bfs( nec[i] );
    }
    memset( dp, -1, sizeof( dp ) );
    i = getDP( 0 );
    if ( i < (1<<29) )
        printf( "%d\n", getDP( 0 ) );
    else printf( "-1\n" );
    return 0;
}