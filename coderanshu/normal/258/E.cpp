#include<bits/stdc++.h>
using namespace std ;

#define ll              int
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

vector<int> v[N],q[N];

struct node
{
    int min=2e9,cnt=0;
}fake;
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.min=min(a.min,b.min);
        ret.cnt = 0;
        if(ret.min == a.min)
            ret.cnt += a.cnt;
        if(ret.min == b.min)
            ret.cnt += b.cnt;
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.min=val;
        ret.cnt = 1;
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

int cur = 0,in[N],out[N],ans[N];

void dfs(int s,int p)
{
    in[s] = cur++;
    for(auto &j:v[s])
        if(j!=p)
            dfs(j,s);
    out[s] = cur-1;
}

void dfs2(int s,int p)
{
    for(auto j:q[s])
        seg.rupdate(1,0,cur-1,in[j],out[j],1);
    if(sz(q[s]))
        seg.rupdate(1,0,cur-1,in[s],out[s],1);
    node u = seg.tree[1];
    if(u.min == 0)
        ans[s] = cur - u.cnt;
    else
        ans[s] = cur;
    for(auto j:v[s])
        if(j!=p)
            dfs2(j,s);
    for(auto j:q[s])
        seg.rupdate(1,0,cur-1,in[j],out[j],-1);
    if(sz(q[s]))
        seg.rupdate(1,0,cur-1,in[s],out[s],-1);
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    dfs(1,0);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        q[x].pb(y),q[y].pb(x);
    }
    assert(cur == n);
    for(int i=0;i<n;++i)
        seg.a[i] = 0;
    seg.buildTree(1,0,n-1);
    dfs2(1,0);
    for(int i=1;i<=n;++i)
        cout<<ans[i] - (ans[i]>0)<<" ";
    cout<<"\n";
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