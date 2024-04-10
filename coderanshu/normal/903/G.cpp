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


const int N = 200005;
struct node
{
    ll min = INF;
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
        ret.min = val;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        tree[v].min+=lazy[v];
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
        lazy[v] = 0;
        if(st==en)
        {
            tree[v]=make_node(a[st]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
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

int _runtimeTerror_()
{
    int n,m,Q;
    cin>>n>>m>>Q;
    vector<ll> a(n+1,0),b(n+1,0);
    for(int i=1;i<=n-1;++i)
        cin>>a[i]>>b[i];
    vector<vector<pii>> g(n+1);
    for(int i=1;i<=m;++i)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g[x].push_back({y,z});
    }
    for(int i=1;i<=n;++i)
        seg.a[i] = b[i];
    seg.buildTree(1,1,n);
    vector<ll> good(n+1,INF);
    for(int i=1;i<=n;++i)
    {
        for(auto [j,k]:g[i])
        {
            seg.rupdate(1,1,n,1,j-1,k);
            seg.rupdate(1,1,n,n,n,k);
        }
        good[i] = seg.query(1,1,n,1,n).min;
    }
    for(int i=1;i<=n;++i)
        seg.a[i] = good[i] + a[i];
    seg.buildTree(1,1,n);
    cout<<seg.tree[1].min<<"\n";
    while(Q--)
    {
        ll v,w;
        cin>>v>>w;
        seg.rupdate(1,1,n,v,v,-a[v]);
        a[v] = w;
        seg.rupdate(1,1,n,v,v,a[v]);
        cout<<seg.query(1,1,n,1,n).min<<"\n";
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