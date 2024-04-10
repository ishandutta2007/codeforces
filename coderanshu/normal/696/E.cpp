#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll> 
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;
const long double PI = acos(-1);

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 100005;
vector<int> v[N];

vector<pll> guls[N];

struct node
{
    pll min = {INF,INF};
}fake;
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.min = min(a.min,b.min);
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.min.F = val;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        tree[v].min.F += lazy[v];
        if(st!=en)
        {
            lazy[v<<1]+=lazy[v];
            lazy[v<<1 | 1]+=lazy[v];
        }
        lazy[v]=0;
        return ;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st]);
            tree[v].min.S = st;
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void update(ll v,ll st,ll en,ll in,ll val)
    {
        pushdown(v,st,en);
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val);
            tree[v].min.S = st;
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val),pushdown(v<<1|1,mid+1,en);
        else
            update(v<<1 | 1,mid+1,en,in,val),pushdown(v<<1,st,mid);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    void rupdate(ll v,ll st,ll en,ll l,ll r,ll val)
    {
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(en<l || st>r)return ;
        if(st>=l && en<=r)
        {
            lazy[v]=val;
            pushdown(v,st,en);
            return ;
        }
        ll mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,r,val);
        rupdate(v<<1 | 1,mid+1,en,l,r,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;


template<typename T=long long>
struct fenwick {
    T a[N],bit[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            a[i] = T(0),bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;j+=j&-j)
                bit[j] += a[i];
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
};

fenwick<ll> fenw;
// call fenw.build(n);

int sub[N],dep[N],par[N];

void dfs_size(int s=1,int p=-1)
{
    sub[s]=1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1;
            par[j]=s;
            dfs_size(j,s);
            sub[s]+=sub[j];
        }
    }
}

int head[N],pos[N],in[N],out[N],cur=0,idx[N];
void hld(int s,int p,int h)
{
    head[s]=h;
    int hv=-1,mx=-1;
    pos[s]=cur++;
    in[s]=pos[s];
    idx[in[s]] = s;
    for(auto j:v[s])
        if(j!=p)
            if(sub[j]>mx)
                mx=sub[j],hv=j;

    if(hv!=-1)
        hld(hv,s,h);
    for(auto j:v[s])
        if(j!=p && j!=hv)
            hld(j,s,j);
    out[s]=cur-1;
}

int _runtimeTerror_()
{
    int n,m,Q;
    cin>>n>>m>>Q;
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=1;i<=m;++i)
    {
        int x;
        cin>>x;
        guls[x].pb({i,i});
    }
    for(int i=1;i<=n;++i)
    {
        guls[i].pb({INF,-1});
        sort(all(guls[i]));
        reverse(all(guls[i]));
    }
    dfs_size(1,0);
    hld(1,0,1);
    for(int i=1;i<=n;++i)
    {
        seg.a[in[i]] = guls[i].back().F;
    }
    assert(cur == n);
    seg.buildTree(1,0,n-1);
    fenw.build(n);
    auto getmin = [&](int a,int b)
    {
        pll ans = {INF,INF};
        for(;head[a]!=head[b];b = par[head[b]])
        {
            if(dep[head[a]]>dep[head[b]])
                swap(a,b);
            amin(ans,seg.query(1,0,n-1,pos[head[b]],pos[b]).min);
        }
        if(dep[a]>dep[b])
            swap(a,b);
        amin(ans,seg.query(1,0,n-1,pos[a],pos[b]).min);
        return ans;
    };
    while(Q--)
    {
        int tt;
        cin>>tt;
        if(tt == 1)
        {
            int v,u,k;
            cin>>v>>u>>k;
            vector<ll> ans;
            for(;k;--k)
            {
                auto x = getmin(v,u);
                if(x.F>=INF)
                    break;
                ans.pb(guls[idx[x.S]].back().S);
                x.S = idx[x.S];
                guls[x.S].pop_back();
                seg.update(1,0,n-1,in[x.S],guls[x.S].back().F + fenw.get(in[x.S]+1));
            }
            cout<<sz(ans)<<" ";
            for(auto j:ans)
                cout<<j<<" ";
            cout<<"\n";
        }
        else
        {
            int v,k;
            cin>>v>>k;
            seg.rupdate(1,0,n-1,in[v],out[v],k);
            fenw.update(in[v]+1,k);
            fenw.update(out[v]+2,-k);
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}