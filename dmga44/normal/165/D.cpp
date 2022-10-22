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
const ll mod=(ll)(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(3e5+5)

vector<int> g[MAXN];
vector<pii> gp[MAXN];
bool mk[MAXN];
int pose[MAXN];

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
        return v1+v2;
    }

    void up(int p,T v)
    {
        st[p]+=v;
    }

    void build(T *arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,T *arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    void build(vector<T> &arr) { build(1,0,sz-1,arr); }

    void build(int p,int l,int r,vector<T> &arr)
    {
        if(l==r)
        {
            st[p]=arr[l];
            return ;
        }
        int mid=(l+r)>>1;

        build(p<<1,l,mid,arr);
        build((p<<1)+1,mid+1,r,arr);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    void update(int pos,T v) { update(1,0,sz-1,pos,v); }

    void update(int p,int l,int r,int pos,T v)
    {
        if(pos<=l && r<=pos)
        {
            up(p,v);
            return ;
        }
        int mid=(l+r)>>1;

        if(pos<=mid)
            update(p<<1,l,mid,pos,v);
        if(pos>mid)
            update((p<<1)+1,mid+1,r,pos,v);

        st[p]=merge(st[p<<1],st[(p<<1)+1]);
    }

    T query(int L,int R) { return query(1,0,sz-1,L,R); }

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
            return st[p];

        int mid=(l+r)>>1;

        if(R<=mid)
            return query(p<<1,l,mid,L,R);
        if(L>mid)
            return query((p<<1)+1,mid+1,r,L,R);
        return merge(query(p<<1,l,mid,L,R),query((p<<1)+1,mid+1,r,L,R));
    }
};

int heavy[MAXN], root[MAXN], depth[MAXN];
int pos[MAXN], ipos[MAXN], parent[MAXN];

struct heavy_light{
    int n;

    int dfs(int s, int f,vector<int>* G){
        parent[s] = f, heavy[s] = -1;
        int size = 1, maxSubtree = 0;

        for (auto u : G[s]) if (u != f){
            depth[u] = depth[s] + 1;
            int subtree = dfs(u, s, G);

            if (subtree > maxSubtree)
                heavy[s] = u, maxSubtree = subtree;

            size += subtree;
        }

        return size;
    }

    void go(vector<int>* G, int nn){
        n = nn;
        int ROOT=0;
        depth[ROOT] = 0;
        dfs(ROOT, -1, G);

        vector<pii> nodes;
        for(int i=0;i<n;i++)
            if (parent[i] == -1 || heavy[parent[i]] != i)
                nodes.push_back(pii(depth[i],i));

        sort(all(nodes));
        for (int ii = 0, currentPos = 0; ii < nodes.size(); ++ii)
        {
            int i=nodes[ii].s;
            for (int u = i; u != -1; u = heavy[u], currentPos++)
            {
                root[u] = i;
                pos[u] = currentPos;
                ipos[currentPos] = u;
            }
        }
    }

    int lca(int u, int v, ST<int> &st){
        int ans = 0;
        for (; root[u] != root[v]; v = parent[root[v]]) {
            if (depth[root[u]] > depth[root[v]]) swap(u, v);
            ans += st.query(1, 0, n-1, pos[root[v]], pos[v]);
        }
        if (depth[u] > depth[v]) swap(u, v);
        ans += st.query(1, 0, n-1, pos[u], pos[v]);

        return ans;
    }

    int go_up(int u, int k){
        // The kth node (0 indexed) in the path from (u to root)
        for (;pos[u] - pos[root[u]] < k; u = parent[root[u]])
            k -= pos[u] - pos[root[u]] + 1;
        return ipos[pos[u] - k];
    }
};

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

void dfs(int u)
{
    mk[u]=1;
    for(auto p : gp[u])
    {
        int v=p.f;
        int id=p.s;
        if(!mk[v])
        {
            pose[id]=v;
            dfs(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
        gp[u].push_back(pii(v,i));
        gp[v].push_back(pii(u,i));
    }

    dfs(0);

    vector<int> base(n,1);
    base[0]=0;
    ST<int> st(n);
    st.build(base);

    heavy_light hld;
    hld.go(g,n);

    LCA lca(n,g);

    int q;
    cin >> q;
    while(q--)
    {
        int ty;
        cin >> ty;
        if(ty==1)
        {
            int id;
            cin >> id;
            id--;
            st.update(pos[pose[id]],1);
        }
        if(ty==2)
        {
            int id;
            cin >> id;
            id--;
            st.update(pos[pose[id]],-1);
        }
        if(ty==3)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
//            db("xxxx")
            int p=lca.query(u,v);
            int sum=lca.level[u]+lca.level[v]-(2*lca.level[p]);
            int sum2=hld.lca(u,v,st);
            sum2-=st.query(pos[p],pos[p]);
            if(sum2==sum)
                db(sum)
            else
                db(-1)
        }
    }

    return 0;
}