#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

int p[MAXN];
vector<pii> ee;
int t[MAXN];
vector<pii> g[MAXN];
int d[MAXN];
vector<int> qs1[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

bool join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return 0;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    return 1;
}

template <typename T>
struct ST{
    vector< T > st;
    int sz;

    ST (int n) : sz(n),st(4*n) {}

    T merge(T v1,T v2)
    {
        return max(v1,v2);
    }

    void up(int p,T v)
    {
        st[p]=v;
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

vector<int> nodes;
bool mk[MAXN];
int li[MAXN],ls[MAXN];
int cont;

void dfs(int u)
{
    mk[u]=1;
    li[u]=cont;
    cont++;
    nodes.push_back(u);
    for(auto y : g[u])
        if(!mk[y.f])
            dfs(y.f);
    ls[u]=cont-1;
}

struct LCA{
    vector< vector<int> > lca;
    vector< vector<int> > ccc;
    vector<int> level, parent, lg;

    LCA (int n) : ccc(n),level(n),parent(n),lg(n+1),lca(n) {
        lg[0]=-1;
        for(int i=1;i<=n;i++)
            lg[i]=lg[i-1]+!(i&(i-1));

        for(int i=0;i<n;i++)
        {
            lca[i].resize(lg[n]+1);
            ccc[i]=vector<int>(lg[n]+1,-1);
        }
    }

    void buildSparseTable(int root,vector<pii> *g)
    {
        queue< int > Q;
        level[root] = 0;
        parent[root] = -1;

        for ( Q.push( root ); !Q.empty(); Q.pop() )
        {
            int u = Q.front();

            for ( auto y : g[u])
            {
                int v=y.f;
                int w=y.s;
                if ( v == parent[u] ) continue;

                parent[v] = u;
                level[v] = level[u] + 1;
                Q.push( v );

                lca[v][0] = u;
                ccc[v][0] = w;
                for ( int j = 1; j <= lg[ level[v] ]; j++ )
                {
                    lca[v][j] = lca[ lca[v][ j - 1 ] ][ j - 1 ];
                    ccc[v][j]=min(ccc[v][j-1],ccc[lca[v][j-1]][j-1]);
                }
            }
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q;
    cin >> n >> m >> q;
    for(int i=0;i<n;i++)
        cin >> p[i];

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        ee.push_back(pii(u,v));
        t[i]=oo;
    }
//    db("xxx")
    for(int i=0;i<q;i++)
    {
        int ty,x;
        cin >> ty >> x;
        x--;
        if(ty==2)
            t[x]=i;
        if(ty==1)
            qs1[x].push_back(i);
    }

    vector<pii> es;
    for(int i=0;i<m;i++)
        es.push_back(pii(t[i],i));

    sort(allr(es));

    for(int i=0;i<2*n;i++)
        d[i]=-1;

//    db("xxx")
    cont=n;
    for(int i=0;i<m;i++)
    {
        int p=es[i].s;
        int u=ee[p].f;
        int v=ee[p].s;
//        db("")
//        db(i)
//        cout << u << ' ' << v << '\n';
        int x=find(u);
        int y=find(v);
        if(join(u,v))
        {
            int k=find(u);
            d[cont]+=d[k];
            d[k]=cont;
//            cout << cont << ' ' << x << ' ' << y << '\n';
            g[cont].push_back(pii(x,es[i].f));
            g[cont].push_back(pii(y,es[i].f));
            g[x].push_back(pii(cont,es[i].f));
            g[y].push_back(pii(cont,es[i].f));
            cont++;
        }
    }

    LCA lca(2*n);
//    db("xxx")
    vector<pii> res;
    for(int i=2*n-1;i>=0;i--)
    {
        if(mk[i])
            continue;
        cont=0;

        dfs(i);
        lca.buildSparseTable(i,g);

        vector<pii> qs;
        for(auto y : nodes)
            for(auto t : qs1[y])
                qs.push_back(pii(t,y));
        sort(all(qs));
//        db("")
//        db(i)
//        for(auto y : qs)
//            cout << y.f << ' ' << y.s << '\n';

        vector<pii> ini(nodes.size());
        for(auto y : nodes)
            ini[li[y]]=pii(p[y],li[y]);
        ST<pii> st(nodes.size());
        st.build(ini);

        for(auto y : qs)
        {
            int u=y.s;
            int t=y.f;
//            cout << u << ' ';
            for(int po=lca.ccc[0].size()-1;po>=0;po--)
                if(lca.ccc[u][po]>t)
                    u=lca.lca[u][po];
//            cout << u << '\n';
            pii x=st.query(li[u],ls[u]);
            res.push_back(pii(t,x.f));
            st.update(x.s,pii(0,x.s));
        }
        nodes.clear();
    }

    sort(all(res));

    for(auto y : res)
        cout << y.s << '\n';
//    cout << '\n';

    return 0;
}
/**
5 4 6
1 2 5 4 3
1 2
2 3
1 3
4 5
1 1
2 1
2 3
1 1
1 2
1 2

**/