#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

const int maxa = 10000010;

int gcd( int a, int b )
{
    if ( b == 0 ) return a;
    return gcd( b, a%b );
}

int n;
int a[1000020];

int pos[10000020];
int par[1000020];

//int cd[3220][3920];

int uf_find( int v )
{
    vector<int> a;
    int i;
    while ( par[v] != -1 )
    {
        a.push_back( v );
        v = par[v];
    }
    for ( i = 0; i < a.size(); i++ )
    {
        par[ a[i] ] = v;
    }
    return v;
}

int main()
{
    int i, j, k;
    int c, d;
    vector<int> ho;

    memset( pos, -1, sizeof( pos ) );
    memset( par, -1, sizeof( par ) );

    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%d", &a[i] );
        pos[a[i]] = i;
    }

    for ( c = 1; c <= 3200; c++ )
    {
        for ( d = c+1; d <= 3900; d=d+2 )
        {
            if ( ( 2*c*d > maxa ) && ( c*c+d*d > maxa ) )
                continue;
            if ( gcd( c, d ) != 1 ) continue;
            ho.clear();
            if ( d*d-c*c <= maxa )
            {
                ho.push_back( pos[d*d-c*c] );
            }
            if ( 2*c*d <= maxa )
            {
                ho.push_back( pos[2*c*d] );
            }
            if ( c*c+d*d <= maxa )
            {
                ho.push_back( pos[c*c+d*d] );
            }
            for ( i = 0; i < ho.size(); i++ )
            {
                if ( ho[i] == -1 ) continue;
                for ( j = i+1; j < ho.size(); j++ )
                {
                    if ( ho[j] == -1 ) continue;
                    if ( uf_find( ho[i] ) != uf_find( ho[j] ) )
                    {
                        par[ uf_find( ho[i] ) ] = uf_find( ho[j] );
                    }
                }
            }
        }
    }
    int sol = 0;
    for ( i = 1; i <= n; i++ )
    {
        if ( par[i] == -1 )
            sol++;
    }
    printf( "%d\n", sol );
    return 0;
}