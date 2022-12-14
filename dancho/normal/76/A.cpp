#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct edge
{
    int a, b;
    int g, s;
    bool operator<( const edge &x ) const
    {
        return s < x.s;
    }
};

bool cmp( edge a, edge b )
{
    return a.g < b.g;
}

typedef pair<int,int> pii;

int n, m;
long long G, S;
edge e[50020];

multiset<edge> MS;

int len[256], par[256], col[256];
bool rem[256][50020];
vector<pii> gr[256];

int upar[256];
int a[256];

inline int ufind( int v )
{
    int l = 0;
    int i;
    while ( upar[v] != -1 )
    {
        a[++l] = v;
        v = upar[v];
    }
    for ( i = 1; i <= l; i++ )
        upar[a[i]] = v;
    return v;
}

int fixit( edge ed )
{
    int i, j, k;
    int rm = 0, nr = 0;
    int lc = 0;
    edge e1, e2;

    if ( ufind( ed.a ) != ufind( ed.b ) )
    {
        upar[ ufind( ed.a ) ] = ed.b;
        MS.insert( ed );
        for ( i = 1; i <= n; i++ )
        {
            if ( ufind( i ) != ufind( ed.b ) )
                return -1;
        }
        return (*MS.rbegin()).s;
    }

    memset( upar, -1, sizeof( upar ) );
    MS.insert( ed );
    multiset<edge>::iterator it, jt;
    for ( it = MS.begin(); it != MS.end(); )
    {
        e1 = *it;
        if ( ufind( e1.a ) != ufind( e1.b ) )
        {
            upar[ ufind( e1.a ) ] = e1.b;
            it++;
        }
        else
        {
            jt = it;
            it++;
            MS.erase( jt );
        }
    }
    for ( i = 1; i <= n; i++ )
    {
        if ( ufind( i ) != ufind( ed.b ) )
            return -1;
    }
    return (*MS.rbegin()).s;
}

int main()
{
    int i, j, k;
    long long ans = (1LL<<62);
//    cout << ans << endl;

    scanf( "%d %d", &n, &m );
    scanf( "%I64d %I64d", &G, &S );
    for ( i = 1; i <= m; i++ )
    {
        scanf( "%d %d %d %d", &e[i].a, &e[i].b, &e[i].g, &e[i].s );
    }
    sort( e + 1, e + m + 1, cmp );

    memset( rem, 0, sizeof( rem ) );
    memset( upar, -1, sizeof( upar ) );
    memset( par, -1, sizeof( par ) );
    memset( len, -1, sizeof( len ) );

    for ( i = 1; i <= m; i++ )
    {
        gr[e[i].a].push_back( make_pair( e[i].b, e[i].s ) );
        gr[e[i].b].push_back( make_pair( e[i].a, e[i].s ) );
        k = fixit( e[i] );
        if ( k > 0 )
        {
            ans = min( ans, G*e[i].g + S*k );
        }
    }
    if ( ans == (1LL<<62) )
        printf( "-1\n" );
    else printf( "%I64d\n", ans );
    return 0;
}