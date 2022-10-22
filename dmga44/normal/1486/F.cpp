#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

vector<int> g[MAXN];
ll ceros[MAXN];
vector<int> unos[MAXN];
vector<pii> dos[MAXN];
int type_last;
ll ini[MAXN];
bool mk[MAXN];

struct LCA{

    vector< vector<int> > lca;
    vector<int> level, parent, lg;

    LCA (int n,vector<int> *adj) : level(n),parent(n),lg(n+1),lca(n) {
        lg[0]=-1;
        for(int i=1;i<=n;i++)
            lg[i]=lg[i-1]+!(i&(i-1));

        for(int i=0;i<n;i++)
            lca[i].resize(lg[n]+1);

        buildSparseTable(0,adj);
    }

    void buildSparseTable(int root,vector<int> *g)
    {
        queue< int > Q;
        level[root] = 0;
        parent[root] = -1;

        for ( Q.push( root ); !Q.empty(); Q.pop() )
        {
            int u = Q.front();

            for ( auto v : g[u])
            {
                if ( v == parent[u] ) continue;

                parent[v] = u;
                level[v] = level[u] + 1;
                Q.push( v );

                lca[v][0] = u;
                for ( int j = 1; j <= lg[ level[v] ]; j++ )
                    lca[v][j] = lca[ lca[v][ j - 1 ] ][ j - 1 ];
            }
        }
    }

    int query( int u, int v )
    {
        if(u==v)
        {
            type_last=0;
            ceros[u]++;
            return u;
        }
        if ( level[u] < level[v] ) swap( u, v );

        int cpy=u;
        if ( level[u] != level[v] )
            for ( int i = lg[ level[u] ]; i >= 0; i-- )
                if ( level[u] - ( 1 << i ) >= level[v] )
                    u = lca[u][i];

        if ( u == v )
        {
            type_last=1;
            for ( int i = lg[ level[cpy] ]; i >= 0; i-- )
                if ( level[cpy] - ( 1 << i ) > level[v] )
                    cpy = lca[cpy][i];
            unos[u].push_back(cpy);
            return u;
        }
        for ( int i = lg[ level[u] ]; i >= 0; i-- )
            if ( lca[u][i] != lca[v][i] )
            {
                u = lca[u][i];
                v = lca[v][i];
            }

        type_last=2;
        if(u>v)
            swap(u,v);
        dos[parent[u]].push_back(pii(u,v));
        return parent[u];
    }
};

ll res;
ll sons[MAXN];

int dfs(int u)
{
    mk[u]=1;
    ll t1=unos[u].size();
    ll t2=dos[u].size();
    ///tipo 1, 2 y 3
    ll active=0;

    map<pii,int> f;
    for(auto p : dos[u])
        f[p]++;

    for(auto v : g[u])
        if(!mk[v])
        {
            int x=dfs(v);
            active+=x;
            sons[v]=x;
        }

    active-=t2;
    ///ceros
    res+=(ceros[u]*(ceros[u]-1))/2;
    res+=ceros[u]*active;
    res+=ceros[u]*ini[u];

    ///ini
    res+=ini[u]*(t1+t2);

    for(auto v : unos[u])
    {
        res+=active-sons[v];
        sons[v]--;
        active--;
    }

    for(auto p : dos[u])
    {
        int v=p.f;
        int w=p.s;
        res+=active-sons[v]-sons[w]+f[pii(v,w)];
        sons[v]--;
        sons[w]--;
        f[pii(v,w)]--;
        active--;
    }

    return active+ini[u];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    LCA lca(n,g);

    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        if(lca.level[u]<lca.level[v])
            swap(u,v);
        int p=lca.query(u,v);
        if(type_last==1)
            ini[u]++;
        if(type_last==2)
        {
            ini[u]++;
            ini[v]++;
        }
    }

    dfs(0);

    db(res)

    return 0;
}
/**
5
1 2
1 3
1 4
3 5
4
2 3
2 4
3 4
3 5

5
1 2
1 3
1 4
1 5
7
2 3
4 3
4 5
2 5
2 4
3 5
5 5
**/