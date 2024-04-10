#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

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
const int N=200005;
int n;
struct node
{
    ll mi;
}fake={INF};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ mem0(a); }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.mi=min(a.mi,b.mi);
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.mi=val;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        tree[v].mi+=lazy[v];
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
int p[N],pos[N];
ll val[N];
int _runtimeTerror_()
{
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>p[i];
        pos[p[i]]=i;
    }
    for(int i=0;i<n;++i)
    {
        cin>>seg.a[i];
        val[i]=seg.a[i];
    }
    ll ans=INF;
    amin(ans,seg.a[0]);
    amin(ans,seg.a[n-1]);
    for(int i=1;i<n;++i)
        seg.a[i]+=seg.a[i-1];
    seg.buildTree(1,0,n-1);
    for(int i=1;i<=n-1;++i)
    {
        seg.rupdate(1,0,n-1,pos[i],n-1,-val[pos[i]]);
        if(pos[i]!=0)
            seg.rupdate(1,0,n-1,0,pos[i]-1,val[pos[i]]);
        amin(ans,seg.query(1,0,n-1,0,n-2).mi);
    }
    cout<<ans<<'\n';
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