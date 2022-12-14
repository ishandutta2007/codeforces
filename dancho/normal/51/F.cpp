#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;

int n, m;
int sol, s2;
vector<int> go[2020];
vector<int> g[2020];
int dep[2020], low[2020], par[2020];
int col[2020], bc[2020];
int comp[2020], scomp[2020], inc[2020];
bool br[2020][2020];

int sl[2020][2020], kill[2020][2020];

void dfsDL( int v )
{
    int i, u;

    low[v] = dep[v];
    for ( i = 0; i < go[v].size(); i++ )
    {
        u = go[v][i];
        if ( dep[u] == -1 )
        {
            dep[u] = dep[v] + 1;
            par[u] = v;
            dfsDL( u );
        }
    }
    for ( i = 0; i < go[v].size(); i++ )
    {
        u = go[v][i];
        if ( u != par[v] )
            low[v] = min( low[v], low[u] );
    }
    if ( ( low[v] == dep[v] ) && ( par[v] != 0 ) )
    {
        br[v][par[v]] = 1;
        br[par[v]][v] = 1;
    }
}

void dfsc( int v )
{
    int i, u;
    for ( i = 0; i < go[v].size(); i++ )
    {
        u = go[v][i];
        if ( ( col[u] == -1 ) && ( br[v][u] == 0 ) )
        {
            col[u] = col[v];
            dfsc( u );
        }
    }
}

void dfscomp( int v )
{
    int i, u;
    for ( i = 0; i < g[v].size(); i++ )
    {
        u = g[v][i];
        if ( comp[u] == -1 )
        {
            comp[u] = comp[v];
            dfscomp( u );
        }
    }
}

int getk( int v, int p )
{
    if ( kill[v][p] != -1 )
        return kill[v][p];

    int i, u;
    int k = 0;
    for ( i = 0; i < g[v].size(); i++ )
    {
        u = g[v][i];
        if ( u != p )
        {
            k = k + getk( u, v );
        }
    }
    if ( p > 0 )
    {
        if ( g[v].size() > 1 ) k++;
    }
    kill[v][p] = k;
//    cout << "KILL " << v << " " << p << " " << kill[v][p] << endl;
    return kill[v][p];
}

int getsl( int v, int p )
{
    if ( sl[v][p] != -1 )
        return sl[v][p];
    if ( g[v].size() == 1 )
        return 0;

    int i, u;
    int sk = 0, bs = (1<<29);
    for ( i = 0; i < g[v].size(); i++ )
    {
        u = g[v][i];
        if ( u != p )
        {
            sk = sk + getk( u, v );
        }
    }
    for ( i = 0; i < g[v].size(); i++ )
    {
        u = g[v][i];
        if ( u != p )
        {
            if ( bs > sk + getsl( u, v ) - getk( u, v ) )
            {
                bs = sk + getsl( u, v ) - getk( u, v );
            }
        }
    }
    sl[v][p] = bs;
    return sl[v][p];
}

int main()
{
    int i, j, k, sk;
    int mi1, mi2;
    int bm1, bm2;
    int v, u;
    sol = 0;

    scanf( "%d %d", &n, &m );
    for ( i = 1; i <= m; i++ )
    {
        scanf( "%d %d", &j, &k );
        go[j].push_back( k );
        go[k].push_back( j );
    }
    memset( dep, -1, sizeof( dep ) );
    memset( par, -1, sizeof( par ) );
    memset( br, 0, sizeof( br ) );

    for ( i = 1; i <= n; i++ )
    {
        if ( dep[i] == -1 )
        {
            dep[i] = 1;
            par[i] = 0;
            dfsDL( i );
        }
    }

    memset( col, -1, sizeof( col ) );
    memset( bc, 0, sizeof( bc ) );

    k = 0;
    for ( i = 1; i <= n; i++ )
    {
        if ( col[i] == -1 )
        {
            k++;
            col[i] = k;
            dfsc( i );
        }
        bc[col[i]]++;
    }

    for ( i = 1; i <= k; i++ )
    {
        sol = sol + bc[i] - 1;
    }

    for ( i = 1; i <= n; i++ )
    {
        for ( j = i+1; j <= n; j++ )
        {
            if ( br[i][j] == 1 )
            {
                g[col[i]].push_back( col[j] );
                g[col[j]].push_back( col[i] );
            }
        }
    }

    memset( comp, -1, sizeof( comp ) );
    memset( scomp, 127, sizeof( scomp ) );
    memset( inc, 0, sizeof( inc ) );
    j = 0;
    for ( i = 1; i <= k; i++ )
    {
        if ( comp[i] == -1 )
        {
            j++;
            comp[i] = j;
            dfscomp( i );
        }
        inc[comp[i]]++;
    }

    memset( kill, -1, sizeof( kill ) );
    memset( sl, -1, sizeof( sl ) );

    for ( v = 1; v <= k; v++ )
    {
        sk = 0;
        bm1 = (1<<29);
        bm2 = (1<<29);
        for ( i = 0; i < g[v].size(); i++ )
        {
            u = g[v][i];
            sk = sk + getk( u, v );
//            cout << v << " " << u << " " << getsl( u, v ) << " " << getk( u, v ) << " " << getsl( u, v ) - getk( u, v ) << endl;
            if ( getsl( u, v ) - getk( u, v ) < bm1 )
            {
                bm2 = bm1;
                bm1 = getsl( u, v ) - getk( u, v );
            }
            else if ( getsl( u, v ) - getk( u, v ) < bm2 )
            {
                bm2 = getsl( u, v ) - getk( u, v );
            }
        }
        if ( g[v].size() > 1 )
            scomp[comp[v]] = min( scomp[comp[v]], sk + bm1 + bm2 );
        else if ( g[v].size() == 1 )
            scomp[comp[v]] = min( scomp[comp[v]], sk + bm1 );
    }
    for ( i = 1; i <= j; i++ )
    {
        if ( inc[i] > 1 )
            sol = sol + scomp[i];
    }
    sol = sol + j - 1;
    printf( "%d\n", sol );
    return 0;
}