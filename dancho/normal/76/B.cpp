#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int N, M;
int y0, y1;
int m[100020], c[100020];
bool usc[100020], usm[100020];
bool vis[100020];
int ma[100020];
int pr[100020];
vector<int> mc[100020];
vector<int> cm[100020];

int sol;

int ia( int x )
{
    if ( x < 0 ) return -x;
    return x;
}

bool augment( int v )
{
    if ( vis[v] == 1 ) return 0;
    vis[v] = 1;
    int i, u;
    for ( i = 0; i < mc[v].size(); i++ )
    {
        u = mc[v][i];
        if ( usc[u] == 1 ) continue;
        if ( ma[u] == -1 )
        {
            ma[u] = v;
            return 1;
        }
        else if ( augment( ma[u] ) == 1 )
        {
            ma[u] = v;
            return 1;
        }
    }
    return 0;
}

int match()
{
    int mm = 0;
    int i, j, k;
    memset( ma, -1, sizeof( ma ) );
    for ( i = 1; i <= N; i++ )
    {
        if ( usm[i] == 1 ) continue;
        memset( vis, 0, sizeof( vis ) );
        if ( augment( i ) )
        {
            mm++;
//            cout << i << " " << "WAT\n";
        }
    }
    return mm;
}

int main()
{
    int i, j, k;
    int pm, pc;

    sol = 0;
    memset( usc, 0, sizeof( usc ) );
    memset( usm, 0, sizeof( usm ) );

    scanf( "%d %d %d %d", &N, &M, &y0, &y1 );
    for ( i = 1; i <= N; i++ )
        scanf( "%d", &m[i] );
    for ( i = 1; i <= M; i++ )
        scanf( "%d", &c[i] );

    pm = 1; pc = 1;
    for ( i = 1; i <= N; i++ )
    {
        while ( ia( c[pc+1] - m[i] ) < ia( c[pc] - m[i] ) )
            pc++;
        mc[i].push_back( pc );
        cm[pc].push_back( i );
        while ( ia( c[pc+1]-m[i] ) == ia( c[pc]-m[i] ) )
        {
            pc++;
            mc[i].push_back( pc );
            cm[pc].push_back( i );
        }
    }

    for ( i = 1; i <= M; i++ )
    {
        for ( j = 1; j < cm[i].size(); j++ )
        {
            if ( ia( c[i] - m[cm[i][j-1]] ) == ia( c[i] - m[cm[i][j]] ) )
            {
                usc[i] = 1;
                sol = sol + 2 - usm[cm[i][j-1]] - usm[cm[i][j]];
                usm[cm[i][j-1]] = 1; usm[cm[i][j]] = 1;
                break;
            }
        }
    }

    sol = sol + match();

    printf( "%d\n", N-sol );

    return 0;
}