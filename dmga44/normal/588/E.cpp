#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(1e5+5)
#define MAXP (ll)(1e7+5)
///up to change
typedef int T;
struct node{
    int l,r;
    T v;
};

node pool[MAXP];
int actual;

int next()
{
    actual++;
    return actual;
}

//template<typename T>
struct pst{
    vector<int> versions;
    int n;
    pst() : n(0) {}
    pst(int n) : n(n) {}
    pst(vector<T> &a) : n(a.size()) { versions.push_back(build(0,n-1,a)); }

    T merge(T v1,T v2)
    {
        return v1+v2;
    }

    void up(int p,T v)
    {
        pool[p].v+=v;
    }

    int build(int l,int r,vector<T> &a)
    {
        int ans=next();
        if(l==r)
        {
            pool[ans].v=a[l];
            return ans;
        }
        int mid=(l+r)>>1;
        pool[ans].l=build(l,mid,a);
        pool[ans].r=build(mid+1,r,a);
        pool[ans].v=merge(pool[pool[ans].l].v,pool[pool[ans].r].v);
        return ans;
    }

    int build(int l,int r,T* a)
    {
        int ans=next();
        if(l==r)
        {
            pool[ans].v=a[l];
            return ans;
        }
        int mid=(l+r)>>1;
        pool[ans].l=build(l,mid,a);
        pool[ans].r=build(mid+1,r,a);
        pool[ans].v=merge(pool[pool[ans].l].v,pool[pool[ans].r].v);
        return ans;
    }

    int clone(int p)
    {
        int ans=next();
        pool[ans].l=pool[p].l;
        pool[ans].r=pool[p].r;
        pool[ans].v=pool[p].v;
        return ans;
    }

    void update(int ver,int pos,T v) { versions.push_back(update(versions[ver],0,n-1,pos,v)); }
    void update(int pos,T v) { versions.push_back(update(versions.back(),0,n-1,pos,v)); }

    int update(int p,int l,int r,int pos,T v)
    {
        p=clone(p);

        if(r==l)
        {
            up(p,v);
            return p;
        }
        int mid=(l+r)>>1;
        if(pos<=mid)
            pool[p].l=update(pool[p].l,l,mid,pos,v);
        else
            pool[p].r=update(pool[p].r,mid+1,r,pos,v);
        pool[p].v=merge(pool[pool[p].l].v,pool[pool[p].r].v);
        return p;
    }

    T query(int t,int l,int r) { return query(versions[t],0,n-1,l,r); }

    T query(int p,int l,int r,int L,int R)
    {
        if(L<=l && r<=R)
            return pool[p].v;

        int mid=(l+r)>>1;
        if(R<=mid)
            return query(pool[p].l,l,mid,L,R);
        if(L>mid)
            return query(pool[p].r,mid+1,r,L,R);
        return merge(query(pool[p].l,l,mid,L,R),query(pool[p].r,mid+1,r,L,R));
    }

    int qq(int vu,int vv,int vlca,int vplca,int k)
    {
        vector<int> pp={versions[vu],versions[vv],versions[vlca],versions[vplca]};
        vector<int> pp2={1,1,-1,-1};
        return multi_kth(pp,pp2,0,n-1,k);
    }

    int multi_kth(vector<int> &p,vector<int> &sg,int l,int r,int k)
    {
        if(l==r)
            return l;

        int mid=(l+r)>>1;
        int sl=0;
        for(int i=0;i<p.size();i++)
            sl+=(pool[pool[p[i]].l].v)*(sg[i]);
        if(sl>=k)
        {
            vector<int> next;
            for(auto pp : p)
                next.push_back(pool[pp].l);
            return multi_kth(next,sg,l,mid,k);
        }
        k-=sl;

        vector<int> next;
        for(auto pp : p)
            next.push_back(pool[pp].r);
        return multi_kth(next,sg,mid+1,r,k);
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

vector<int> g[MAXN];
vector<int> ts[MAXN];
int ve[MAXN];
bool mk[MAXN];

void dfs(int u,int ver,pst &st)
{
    mk[u]=1;
//    db("")
//    db(ver)
    for(auto y : ts[u])
    {
        st.update(ver,y,1);
        ver=st.versions.size()-1;
    }
//    cout << u << ' ' << ver << ' ' << pool[ver].v << '\n';
    ve[u]=ver;
    for(auto v : g[u])
        if(!mk[v])
            dfs(v,ver,st);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q;
    cin >> n >> m >> q;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int i=0;i<m;i++)
    {
        int c;
        cin >> c;
        c--;
        ts[c].push_back(i);
    }

    vector<int> ini(m);
    pst st(ini);
    LCA lca(n,g);

    dfs(0,0,st);

    while(q--)
    {
        int u,v,a;
        cin >> u >> v >> a;
        u--,v--;
        int plca=lca.query(u,v);
        int pplca=lca.parent[plca];
//        cout << u << ' ' << v << ' ' << plca << ' ' << pplca << '\n';
        int vu=ve[u];
        int vv=ve[v];
        int vlca=ve[plca];
        int vplca=0;
        if(pplca!=-1)
            vplca=ve[pplca];
        a=min(a,pool[st.versions[vu]].v+pool[st.versions[vv]].v-pool[st.versions[vlca]].v-pool[st.versions[vplca]].v);
//        db(pool[st.versions[vu]].v+pool[st.versions[vv]].v-pool[st.versions[vlca]].v-pool[st.versions[vplca]].v)
        cout << a;
        for(int i=1;i<=a;i++)
            cout << ' ' << st.qq(vu,vv,vlca,vplca,i)+1;
        cout << '\n';
    }

    return 0;
}
/**
5 4 5
1 3
1 2
1 4
4 5
2 1 4 3
4 5 6
1 5 2
5 5 10
2 3 3
5 3 1
**/