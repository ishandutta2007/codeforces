#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a)    memset(a,0,sizeof(a))
#define mem1(a)    memset(a,-1,sizeof(a))
#define memf(a)    memset(a,false,sizeof(a))
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
#define runSieve
bool notPrime[1000005];
ll divPrime[1000005];
void sieve(int n=1000000)
{
    int k=sqrt(n);
    memf(notPrime);
    notPrime[1]=true;
    for(int i=2;i<=k;++i)
    {
        if(!notPrime[i])
        {
            for(int k=i*i;k<=n;k+=i)
            {
                notPrime[k]=true;
                divPrime[k]=i;
            }
        }
    }
}
const int N=100005;
vector<ll> v[N];
int cur=0;
ll val[N],m,in[N],out[N];
struct node
{
    bitset<1001> bit;
};
bitset<1001> fake,ultimate;
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
        ret.bit=a.bit|b.bit;
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        val%=m;
        ret.bit[val]=1;
        return ret;
    }
    inline void rotate(bitset<1001> &b,ll val)
    {
        b=(b<<val)|(b>>(m-val));
        b = b&ultimate;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        rotate(tree[v].bit,lazy[v]);
        if(st!=en)
        {
            lazy[v<<1]+=lazy[v];
            lazy[v<<1]%=m;
            lazy[v<<1 | 1]+=lazy[v];
            lazy[v<<1 |1 ]%=m;
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
            lazy[v]%=m;
            if(lazy[v]!=0)
                pushdown(v,st,en);
            return ;
        }
        ll mid=(st+en)>>1;
        rupdate(v<<1,st,mid,l,r,val);
        rupdate(v<<1 | 1,mid+1,en,l,r,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    bitset<1001> query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(lazy[v]!=0)
        {
            pushdown(v,st,en);
        }
        if(st>=l && en<=r)
            return tree[v].bit;
        ll mid=(st+en)>>1;
        return (query(v<<1,st,mid,l,r)|query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;
void dfs(int s=1,int p=-1)
{
    in[s]=cur;
    seg.a[cur]=val[s];
    ++cur;
    for(auto j:v[s])
        if(j!=p)
            dfs(j,s);
    out[s]=cur-1;
}
bitset<1001> legend,ff;
int _runtimeTerror_()
{
    ll n;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>val[i];
    for(int i=0;i<n-1;++i)
    {
        ll x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=0;i<m;++i)
        ultimate[i]=1;
    for(int i=2;i<=1000;++i)
    {
        if(!notPrime[i])
            legend[i]=1;
    }
    dfs();
    ll q;
    seg.buildTree(1,0,n-1);
    cin>>q;
    //cout<<seg.tree[1].bit;
    for(int i=0;i<q;++i)
    {
        ll tt,vv;
        cin>>tt>>vv;
        if(tt==1)
        {
            ll x;cin>>x;
            seg.rupdate(1,0,n-1,in[vv],out[vv],x);
        }
        else
        {
            ff=seg.query(1,0,n-1,in[vv],out[vv]);
            ff= ff & legend;
            cout<<ff.count()<<endl;
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
    cerr<<"\n"<<_time_;
    return 0;
}