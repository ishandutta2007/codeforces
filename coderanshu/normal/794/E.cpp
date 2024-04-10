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

const int N = 300005;

struct node
{
    array<ll,2> max{-INF,-INF};
}fake;
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    ll b[N];
    SEGTREE(){ }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        for(int i=0;i<2;++i)
            amax(ret.max[i],max(a.max[i],b.max[i]));
        return ret;
    }
    inline node make_node(ll val1,ll val2)
    {
        node ret;
        ret.max[0] = val1, ret.max[1] = val2;
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(a[st],b[st]);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
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
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
    {
        seg.a[i] = seg.b[i] = -INF;
        cin>>a[i];
        seg.a[i] = a[i];
    }
    for(int i=2;i<=n-1;++i)
        seg.b[i] = min(a[i],max(a[i-1],a[i+1]));
    seg.buildTree(1,1,n);
    for(int k=0;k<=n-1;++k)
    {
        int len = n - k;
        if(len == 1)
        {
            cout<<*max_element(all(a))<<" ";
        }
        else if(len % 2 == 0)
        {
            cout<<seg.query(1,1,n,len/2,n - len/2 + 1).max[0]<<" ";
        }
        else
        {
            cout<<seg.query(1,1,n,len/2+1,n-len/2).max[1]<<" ";
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