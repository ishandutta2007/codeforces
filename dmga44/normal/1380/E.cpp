#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define dbg(x) cerr << #x ": " << (x)<< '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int> > adyList;

#define x first
#define y second
#define pb push_back
#define sqr(a) ((a) * (a))
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define MAXN 400007

const int INF = int(1e9);
const ll INF64 = ll(1e18);
const int MOD = int(1e9) + 7;
const ld EPS = 1e-9;
const ld PI = acos(-1.0);
vector<int> G[MAXN];
//adyList G;


struct LCA{

    vector< vector<int> > lca;
    vector<int> level, parent, lg;

    LCA (int n,vector<int> *adj) : level(n),parent(n),lg(n+1),lca(n) {
        lg[0]=-1;
        for(int i=1;i<=n;i++)
            lg[i]=lg[i-1]+!(i&(i-1));

        for(int i=0;i<n;i++)
            lca[i].resize(lg[n]+1);

     //   buildSparseTable(0,adj);
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
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    vi v;
    forn(i,n)
    {
        int a;
        cin>>a;
        v.push_back(a-1);
    }
    vi v2(m,0); v2[0] = 0;
    fore(i,1,m)
        v2[i] = v2[i-1]+1;;
    forn(i,m-1)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[i+m].push_back(v2[a]);
        G[i+m].push_back(v2[b]);
        G[v2[b]].push_back(i+m);
        G[v2[a]].push_back(i+m);
        v2[b] = i+m;
        v2[a] = i+m;
    }
    LCA lll(2*m-1,G);
    lll.buildSparseTable(2*m-2,G);
    vi vv(m);
    forn(i,n-1)
    {
        int x = lll.query(v[i],v[i+1]);
//        dbg(x)
        vv[max(0,x-m+1)]++;
    }
    ll ans = 0;
    fore(i,0,m)
    {
        ans+=vv[i];
        db(n-1 - ans)
    }


    return 0;
}