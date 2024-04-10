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

const int N = 500005;
struct node
{
    ll mx;
}fake{-INF};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.mx=max(a.mx,b.mx);
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.mx=val;
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
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1),idx(n+1),q(n+1);
    vector<pll> v;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i] -= i;
        v.pb({a[i],i});
    }
    sort(all(v));
    for(int i=1;i<=n;++i)
    {
        idx[v[i-1].S] = i;
    }
    q[v.back().S] = n;
    for(int i=n-1;i>=1;--i)
    {
        if(v[i-1].F == v[i].F)
            q[v[i-1].S] = q[v[i].S];
        else
            q[v[i-1].S] = i;
    }
    seg.a[0] = 0;
    for(int i=1;i<=n;++i)
        seg.a[i] = -INF;
    vector<ll> dp(n+1,-INF);
    dp[0] = 0;
    int cur = 0;
    idx[0] = 0;
    seg.buildTree(1,0,n);
    vector<bool> fuck(n+1,false);
    for(int i=0;i<k;++i)
    {
        int x;
        cin>>x;
        fuck[x] = true;
    }
    for(int i=1;i<=n;++i)
    {
        dp[i] = seg.query(1,0,n,0,q[i]).mx + 1;
        if(dp[i]<-2e9)
            dp[i] = -INF;
        seg.update(1,0,n,idx[i],dp[i]);
        if(fuck[i])
        {
            if(dp[i]==-INF)
            {
                cout<<"-1\n";return 0;
            }
            while(cur<i){
                seg.update(1,0,n,idx[cur],-INF);
                ++cur;
            }
        }
    }
    for(int i=1;i<=n;++i)
        amax(dp[n],dp[i]);
    cout<<n-dp[n]<<"\n";
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