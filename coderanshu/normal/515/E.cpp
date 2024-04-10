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
ll val[N/2],h[N/2];

struct node
{
    ll mx1,mx2;
    ll idx1,idx2;
}fake;
ll n;
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    node tree[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.mx1=max(a.mx1,b.mx1);
        if(ret.mx1==a.mx1)
        {
            ret.idx1=a.idx1;
            if(a.mx2>b.mx1)
                ret.mx2=a.mx2,ret.idx2=a.idx2;
            else
                ret.mx2=b.mx1,ret.idx2=b.idx1;
        }
        else
        {
            ret.idx1=b.idx1;
            if(a.mx1>b.mx2)
                ret.mx2=a.mx1,ret.idx2=a.idx1;
            else
                ret.mx2=b.mx2,ret.idx2=b.idx2;
        }
        return ret;
    }
    inline node make_node(ll i,ll val)
    {
        node ret;
        ret.mx1=val;
        ret.idx1=i<=n?i:i-n;
        ret.mx2=-INF;
        ret.idx2=2e5+2;
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(st,a[st]);
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
}seg1,seg2;

int _runtimeTerror_()
{
    ll m;
    cin>>n>>m;
    fake.mx1=fake.mx2=-INF;
    fake.idx1=fake.idx2=2e5+2;
    for(int i=2;i<=n;++i)
        cin>>val[i];
    cin>>val[1];
    for(int i=1;i<=n;++i)
        cin>>h[i];
    seg1.a[0]=seg2.a[0]=0;
    ll cnt=0;
    for(int i=1;i<=2*n;++i)
    {
        ll j=(i<=n)?i:i-n;
        cnt+=val[j];
        seg1.a[i]=cnt+2*h[j];
        seg2.a[i]=2*h[j]-cnt;
    }
    seg1.buildTree(1,1,2*n);
    seg2.buildTree(1,1,2*n);
    for(int i=0;i<m;++i)
    {
        ll x,y;
        cin>>x>>y;
        ll ans;
        if(x<=y)
            x=n+x;
        node a=seg1.query(1,1,2*n,y+1,x-1);
        node b=seg2.query(1,1,2*n,y+1,x-1);
        if(a.idx1!=b.idx1)
            ans=a.mx1+b.mx1;
        else
           ans=max({a.mx1+b.mx2,a.mx2+b.mx1});
        cout<<ans<<endl;
    }
    return 0;
}
// circular array ko break kar de bas 
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