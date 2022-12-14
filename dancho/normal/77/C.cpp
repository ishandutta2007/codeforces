#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<long long, long long> pii;

int n, s;
vector<int> g[100020];
long long val[100020];

bool us[100020];
long long ans;

pii dfs( int v )
{
//    cout << "INDFS " << v << endl;
    int i, u;
    int bs = 0, as = 0;
    long long fi = 0, se = 0;
    long long sl, re;
    pii a;
    vector<long long> vl;

    if ( ( val[v] == 1 ) && ( v != s ) )
        return make_pair( 0, 1 );

    for ( i = 0; i < g[v].size(); i++ )
    {
        u = g[v][i];
        if ( us[u] == 0 )
        {
            us[u] = 1;
            a = dfs( u );
            if ( a.first > 0 )
                vl.push_back( a.first );
            fi = fi + a.first;
            if ( a.first > 0 ) bs++;
            se = se + a.second;
            as++;
        }
    }
    sort( vl.begin(), vl.end(), greater<long long>() );
    sl = 0;
    for ( i = 0; i < vl.size() && i < val[v]-1; i++ )
    {
        sl = sl + vl[i] + 2;
    }
    re = val[v]-1-i;
    if ( as == 0 ) re++;
//    cout << v << " " << re << " " << se << " " << sl << " " << << endl;
    long long k = min( re, se );
    sl = sl + 2*k;
    re = re - k;
    se = se - k;
    if ( v == s )
    {
        re++;
        if ( i < vl.size() )
        {
            sl = sl + vl[i] + 2;
        }
        else
        {
            sl = sl + 2*min( re, se );
        }
        ans = sl;
    }
//    cout << "ou " << v << " " << sl << " " << re << endl;
    return make_pair( sl, re );
}

int main()
{
    int i, j, k;

    scanf( "%d", &n );
    for ( i = 1; i <= n; i++ )
    {
        scanf( "%I64d", &val[i] );
    }

    for ( i = 1; i < n; i++ )
    {
        scanf( "%d %d", &j, &k );
        g[j].push_back( k );
        g[k].push_back( j );
    }
    scanf( "%d", &s );

    memset( us, 0, sizeof( us ) );
    us[s] = 1;
    dfs( s );
    printf( "%I64d\n", ans );
    return 0;
}