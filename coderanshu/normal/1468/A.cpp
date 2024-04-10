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

const int N = 500005;

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
        ret.sum=max(a.sum,b.sum);
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
            tree[v]=make_node(max(a[st],val));
            amax(a[st],val);
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

vector<pii> v[N];

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<ll> dp(n+1,0),a(n+1),l(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=0;i<=n;++i)
        v[i].clear();
    vector<int> st;
    st.pb(n);
    for(int i=n-1;i>=1;--i)
    {
        while(!st.empty() && a[i]>=a[st.back()])
        {
            l[st.back()] = i;
            st.pop_back();
        }
        st.pb(i);
    }
    for(int i=0;i<=n;++i)
        seg.a[i] = 0;
    seg.buildTree(1,0,n);
    while(!st.empty())
    {
        l[st.back()] = 0;
        st.pop_back();
    }
    for(int i=1;i<=n;++i)
    {
        v[l[i]].pb({a[i],i});
    }
    for(int i=1;i<=n;++i)
    {
        int u = seg.query(1,0,n,0,a[i]).sum;
        amax(dp[i],u+1);
        for(auto [j,k]:v[i])
        {
            auto x = seg.query(1,0,n,0,j).sum;
            amax(dp[k],x + 2);
        }
        seg.update(1,0,n,a[i],dp[i]);
    }
    int ans = 0;
    for(int i=1;i<=n;++i)
        amax(ans,dp[i]);
    cout<<ans<<"\n";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}