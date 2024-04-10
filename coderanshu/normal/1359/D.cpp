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

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

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

const int N=100005;
struct node
{
    ll sum;
}fake1={-INF};
node fake2;
    // base value is assigned to fake node
struct SEGTREE1
{
    ll a[N];
    SEGTREE1(){ mem0(a); }
    node tree[4*N];
    ll lazy[4*N];
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
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake1;
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg1;
    // base value is assigned to fake node
struct SEGTREE2
{
    ll a[N];
    SEGTREE2(){ mem0(a); }
    node tree[4*N];
    ll lazy[4*N];
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
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake2;
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg2;
ll a[N],p[N],s[N];
map<ll,vector<ll>> m;
map<ll,set<ll>> mm;
int _runtimeTerror_()
{
    ll n;
    cin>>n;
    fake2.sum=INF;
    for(int i=0;i<n;++i)
        cin>>a[i];
    p[0]=0,s[0]=0,s[n]=0;
    for(int i=0;i<n;++i)
        p[i+1]=p[i]+a[i],s[i+1]=s[i]+a[i];
    for(int i=0;i<n;++i)
        m[a[i]].pb(i),mm[a[i]].insert(i),mm[a[i]].insert(n),mm[a[i]].insert(-1);
    for(int i=0;i<n;++i)
    {
        seg2.a[i+1]=p[i+1];
    }
    for(int i=n;i>=0;--i)
    {
        seg1.a[i]=s[i];
    }
    seg1.buildTree(1,0,n);
    seg2.buildTree(1,0,n);
    ll ans=-INF;
    for(auto j:m)
    {
        for(auto k:j.S)
        {
            ll lo=0,hi=n-1;
            for(int i=j.F+1;i<=30;++i)
            {
                if(mm[i].empty())continue;
                ll x = *mm[i].upper_bound(k);
                amin(hi,x-1);
                auto  y= mm[i].lower_bound(k);
                --y;
                amax(lo,*y+1);
            }
            ll val=seg1.query(1,0,n,k+1,hi+1).sum;
            ll y=0;
            if(k>0)
                val-=seg2.query(1,0,n,lo,k).sum;
            val-=j.F;
            amax(ans,val);
        }
    }
    cout<<ans<<endl;
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
    cerr<<"\n"<<_time_;
    return 0;
}