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

ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }
template<typename T, typename U> ostream& operator<<(ostream &os, const pair<T, U> &p)
{ 
    return os<<'('<<p.F<< ","<<p.S<<')'; 
}

const int N = 100005;

struct node
{
    ll sum;
}fake={0};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum=min(a.sum,b.sum);
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.sum=val;
        return ret;
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
    void update(ll v,ll st,ll en,ll in,ll val)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(val);
            a[st]=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    int query(ll v,ll st,ll en,ll u)
    {
        if(tree[v].sum>=u)
            return en+1;
        if(st==en)
            return st;
        ll mid=(st+en)>>1;
        if(tree[v<<1].sum<u)
        {
            return query(v<<1,st,mid,u);
        }
        return query(v<<1|1,mid+1,en,u);
    }
}seg;

int a[N];
int last[N];
bool done[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        last[i] = -1;
        done[i] = false;
    }
    for(int i=1;i<=n;++i)
        seg.a[i] = -1;
    seg.buildTree(1,1,n);
    for(int i=1;i<=n;++i)
    {
        int u = last[a[i]]+1;
        last[a[i]] = i;
        if(u==0)
            u = 1;
        if(u<i)
        {
            int ans = seg.query(1,1,n,u);
            done[ans] = true;
        }
        seg.update(1,1,n,a[i],i);
    }
    for(int i=1;i<=n+1;++i)
    {
        int u = last[a[i]] + 1;
        if(u==0)
            u = 1;
        if(u<=n)
        {
            int ans = seg.query(1,1,n,u);
            done[ans] = true;
        }
        // cout<<ans<<"\n";
        
    }
    for(int i=1;i<=n+2;++i)
    {
        if(!done[i])
        {
            cout<<i<<"\n";return 0;
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