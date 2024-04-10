//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

ll qp(ll b,ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
            ans=(ans*b)%mod;
        e>>=1;
        b=(b*b)%mod;
    }
    return ans;
}

ll inv(int x)
{
    return qp(x,mod-2);
}

vector<int> g[MAXN];
int level[MAXN];
bool mk[MAXN];
int p[MAXN];
ll pas[MAXN][MAXN];

struct LCA{

    vector< vector<int> > lca;
    vector<int> level, parent, lg;

    LCA (int n,vector<int> *adj,int r = 0) : level(n),parent(n),lg(n+1),lca(n) {
        lg[0]=-1;
        for(int i=1;i<=n;i++)
            lg[i]=lg[i-1]+!(i&(i-1));

        for(int i=0;i<n;i++)
            lca[i].resize(lg[n]+1);

        buildSparseTable(r,adj);
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
        if ( level[u] < level[v] ) swap( u, v );

        if ( level[u] != level[v] )
            for ( int i = lg[ level[u] ]; i >= 0; i-- )
                if ( level[u] - ( 1 << i ) >= level[v] )
                    u = lca[u][i];

        if ( u == v ) return u;

        for ( int i = lg[ level[u] ]; i >= 0; i-- )
            if ( lca[u][i] != lca[v][i] )
            {
                u = lca[u][i];
                v = lca[v][i];
            }

        return parent[u];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pas[0][0]=1;
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<=i;j++)
            pas[i][j]=(pas[i-1][j-1]+pas[i-1][j])%mod;

    for(int i=1;i<MAXN;i++)
        for(int j=1;j<=i;j++)
            pas[i][j]=(pas[i][j]+pas[i][j-1])%mod;

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        LCA lca(n,g,i);

//        db("xxx")
//        db(i)
        for(int j=0;j<n;j++)
            for(int k=j+1;k<n;k++)
            {
                int p=lca.query(j,k);
                int d1=lca.level[j]-lca.level[p]-1;
                int d2=lca.level[k]-lca.level[p]-1;
//                cout << j << ' ' << k << ' ' << p << '\n';
//                cout << d1 << ' ' << d2 << '\n';
                int sum=d1+d2+1;
                ll pr=(inv(n)*(((inv(qp(2,sum)))*(qp(2,sum)-pas[sum+1][sum-d1]+mod))%mod))%mod;
//                db(pr)
//                db("")
                ans=(ans+pr)%mod;
            }
    }
    db(ans)

    return 0;
}