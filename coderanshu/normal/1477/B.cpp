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
    ll one=0,zero=0;
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
        ret.one = a.one + b.one;
        ret.zero = a.zero + b.zero;
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        if(val == 1)
            ret.one = 1;
        else
            ret.zero = 1;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        if(lazy[v] == 1)
        {
            tree[v].one = en-st+1;
            tree[v].zero = 0;
        }
        else
        {
            tree[v].zero = en-st+1;
            tree[v].one = 0;
        }
        if(st!=en)
        {
            lazy[v<<1]=lazy[v];
            lazy[v<<1 | 1]=lazy[v];
        }
        lazy[v]=-1;
        return ;
    }
    void buildTree(ll v,ll st,ll en)
    {
        lazy[v] = -1;
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
        if(lazy[v]!=-1)
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
        if(lazy[v]!=-1)
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
    int n,Q;
    string s,f;
    cin>>n>>Q>>s>>f;
    vector<pii> q(Q+1);
    for(int i=1;i<=Q;++i)
    {
        cin>>q[i].F>>q[i].S;
        --q[i].F,--q[i].S;
    }
    for(int i=0;i<n;++i)
        seg.a[i] = f[i]-'0';
    seg.buildTree(1,0,n-1);
    string ans;
    for(int i=Q;i>=1;--i)
    {
        node u = seg.query(1,0,n-1,q[i].F,q[i].S);
        int len = q[i].S-q[i].F+1;
        if(2*u.one<len)
        {
            seg.rupdate(1,0,n-1,q[i].F,q[i].S,0);
        }
        else if(2*u.zero<len)
        {
            seg.rupdate(1,0,n-1,q[i].F,q[i].S,1);
        }
        else
        {
            cout<<"NO\n";return 0;
        }
    }
    for(int i=0;i<n;++i)
    {
        auto u = seg.query(1,0,n-1,i,i);
        if(u.one)
            ans += "1";
        else
        {
            assert(u.zero);
            ans += "0";
        }
    }
    if(ans == s)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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