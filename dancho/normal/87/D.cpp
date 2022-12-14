#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

typedef pair<int,long long> pii;

struct edge
{
    int a, b, on;
    int d;
    bool operator<( const edge& x ) const
    {
        if ( d != x.d )
            return d < x.d;
        if ( a != x.a )
            return a < x.a;
        if ( b != x.b )
            return b < x.b;
//        return on < x.on;
    }
};

edge make_edge( int a, int b, int on, int d )
{
    edge e;
    e.a = a; e.b = b; e.on = on; e.d = d;
    return e;
}

int n;
int D;
edge ed[100020];
long long esz[100020];

int par[100020];
long long usz[100020];

long long all;
set<edge> mg;
set<int> pv, hv;

vector<int> aa;

long long sum( int v )
{
    int i, u;
    long long sm = 0, km = 0;
//    cout << "DFS " << v << endl;
    set<edge>::iterator it, jt, kt;
    it = mg.lower_bound( make_edge( v, 0, D, D ) );
    jt = mg.upper_bound( make_edge( v, n+1, D, D ) );
//    cout << v << " " << n+1 << " " << D << " " << -1 << endl;
//    cout << "ED? " << (*it).a << " " << (*it).b << endl;
//    cout << "ED? " << (*jt).a << " " << (*jt).b << " " << (*jt).d << endl;
    for ( kt = it; kt != jt; kt++ )
    {
        u = (*kt).b;
        i = (*kt).on;
        if ( hv.find( u ) != hv.end() )
        {
            hv.erase( u );
            pv.insert( u );
            km = sum( u );
            sm = sm + km;
        }
//        esz[i] = (all-km)*(km)*2;
    }
    sm = sm + usz[v];
    return sm;
}

long long dfs( int v )
{
    int i, u;
    long long sm = 0, km = 0;
//    cout << "DFS " << v << endl;
    set<edge>::iterator it, jt, kt;
    it = mg.lower_bound( make_edge( v, 0, D, D ) );
    jt = mg.upper_bound( make_edge( v, n+1, D, D ) );
//    cout << v << " " << n+1 << " " << D << " " << -1 << endl;
//    cout << "ED? " << (*it).a << " " << (*it).b << endl;
//    cout << "ED? " << (*jt).a << " " << (*jt).b << " " << (*jt).d << endl;
    for ( kt = it; kt != jt; kt++ )
    {
        u = (*kt).b;
        i = (*kt).on;
        if ( pv.find( u ) != pv.end() )
        {
            pv.erase( u );
            km = dfs( u );
            sm = sm + km;
        }
        esz[i] = (all-km)*(km)*2;
    }
    sm = sm + usz[v];
    return sm;
}

inline int uf_find( int v )
{
    aa.clear();
    int i;
    while ( par[v] != -1 )
    {
        aa.push_back( v );
        v = par[v];
    }
    for ( i = 0; i < aa.size(); i++ )
    {
        par[aa[i]] = v;
    }
    return v;
}

int main()
{
    int i, j, k;
    int a, b, d;
    long long bs = 0;

    scanf( "%d", &n );
    for ( i = 1; i < n; i++ )
    {
        scanf( "%d %d %d", &a, &b, &d );
        ed[i] = make_edge( a, b, i, d );
    }
    sort( ed + 1, ed + n );

    for ( i = 1; i <= n; i++ )
    {
        par[i] = -1;
        usz[i] = 1;
    }

    for ( i = 1; i < n; )
    {
        j = i;
        all = 0;
        mg.clear();
        hv.clear();
        while ( ed[j].d == ed[i].d )
        {
            //..
            a = uf_find( ed[j].a );
            b = uf_find( ed[j].b );
            mg.insert( make_edge( a, b, ed[j].on, ed[i].d ) );
            mg.insert( make_edge( b, a, ed[j].on, ed[i].d ) );
            if ( hv.find( a ) == hv.end() )
            {
                all = all + usz[a];
                hv.insert( a );
            }
            if ( hv.find( b ) == hv.end() )
            {
                all = all + usz[b];
                hv.insert( b );
            }
//            cout << "HO " << (long long)usz[a]*usz[b]*2LL << endl;
//            esz[ed[j].on] = (long long)usz[a]*usz[b]*2LL;
            j++;
        }
        D = ed[i].d;
//        cout << "AA " << all << endl;
//        for ( set<edge>::iterator it = mg.begin(); it != mg.end(); it++ )
//        {
//            cout << "INSET " << (*it).a << " " << (*it).b << " " << (*it).d << " " << usz[(*it).a] << endl;
//        }
        set<int>::iterator it;
        while ( hv.size() > 0 )
        {
            it = hv.begin();
            a = (*it);
            hv.erase( it );
            all = sum( a );
            dfs( a );
        }
        for ( k = i; k < j; k++ )
        {
            a = uf_find( ed[k].a );
            b = uf_find( ed[k].b );
            par[a] = b;
            usz[b] = usz[b] + usz[a];
//            cout << ed[k].a << " " << ed[k].b << " " << a << " " << b << " " << usz[b] << endl;
        }
        i = j;
    }

    aa.clear();
    for ( i = 1; i < n; i++ )
    {
        if ( esz[i] > bs )
        {
            bs = esz[i];
            aa.clear();
        }
        if ( esz[i] == bs )
        {
            aa.push_back( i );
        }
    }
    printf( "%I64d %d\n", bs, aa.size() );
    printf( "%d", aa[0] );
    for ( i = 1; i < aa.size(); i++ )
        printf( " %d", aa[i] );
    printf( "\n" );
    return 0;
}