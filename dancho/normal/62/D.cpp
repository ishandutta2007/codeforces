#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

int n, m;
int a[2020];
int b[2020];
bool vis[128];

int e[2020];
vector< pii > g[128];

void dfs( int v )
{
    int i, u;
    for ( i = 0; i < g[v].size(); i++ )
    {
        if ( e[g[v][i].second] != 0 ) continue;
        u = g[v][i].first;
        if ( vis[u] == 0 )
        {
            vis[u] = 1;
            dfs( u );
        }
    }
}

int rec( int v, int sm, int pa )
{
    int i, j, k, u;
    int fl = 0;
    b[pa-1] = v;
    if ( sm == 0 )
    {
        for ( i = 0; i < g[v].size(); i++ )
        {
            k = g[v][i].second;
            if ( e[k] == 1 ) continue;
            u = g[v][i].first;
            if ( ( sm == 0 ) && ( u == a[pa] ) )
            {
                e[k] = 1;
                if ( rec( u, 0, pa+1 ) == 1 )
                    return 1;
                e[k] = 0;
            }
            else if ( u > a[pa] )
            {
                e[k] = 1;
                memset( vis, 0, sizeof( vis ) );
                dfs( v );
                for ( j = 1; j <= n; j++ )
                {
                    if ( j == v ) continue;
                    if ( vis[j] == 1 ) break;
                }
                if ( ( j > n ) || ( vis[u] == 1 ) )
                {
                    rec( u, 1, pa+1 );
                    return 1;
                }
                else e[k] = 0;
            }
        }
    }
    else
    {
        for ( i = 0; i < g[v].size(); i++ )
        {
            k = g[v][i].second;
            u = g[v][i].first;
            if ( e[k] == 1 ) continue;

                e[k] = 1;
                memset( vis, 0, sizeof( vis ) );
                dfs( v );
                for ( j = 1; j <= n; j++ )
                {
                    if ( j == v ) continue;
                    if ( vis[j] == 1 ) break;
                }
                if ( ( j > n ) || ( vis[u] == 1 ) )
                {
                    rec( u, 1, pa+1 );
                    return 1;
                }
                else e[k] = 0;
        }
    }
    return 0;
}

int main()
{
    int i, j, k;
    scanf( "%d %d", &n, &m );
    for ( i = 1; i <= m+1; i++ )
    {
        scanf( "%d", &a[i] );
        if ( i > 1 )
        {
            g[a[i]].push_back( make_pair( a[i-1], i ) );
            g[a[i-1]].push_back( make_pair( a[i], i ) );
        }
    }
    memset( e, 0, sizeof( e ) );
    for ( i = 1; i <= n; i++ )
    {
        sort( g[i].begin(), g[i].end() );
    }

    b[1] = a[1];
    if ( rec( a[1], 0, 2 ) == 0 )
    {
        printf( "No solution\n" );
        return 0;
    }
    for ( i = 1; i <= m; i++ )
    {
        printf( "%d ", b[i] );
    }
    printf( "%d\n", b[m+1] );
    return 0;
}