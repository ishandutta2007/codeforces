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
const int N=100005;
vector<ll> v[N];
ll in[N],out[N];
ll a[N];
int cur=0;
ll d[100005],par[100005][20];

void dfs(int s,int p)
{
    in[s]=cur++;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            d[j]=d[s]+1;
            par[j][0]=s;
            dfs(j,s);
        }
    }
    out[s]=cur-1;
}

struct node
{
    ll sum;
}fake={0};
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
        ret.sum=a.sum+b.sum;
        return ret;
    }
    inline node make_node(ll val)
    {
        node ret;
        ret.sum=val;
        return ret;
    }
    inline void pushdown(ll v,ll st,ll en)
    {
        tree[v].sum+=(en-st+1)*lazy[v];
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

void sparseMatrix(ll n)
{
    for(ll i=1;i<20;++i)
    {
        for(ll j=1;j<=n;++j)
        {
            if(par[j][i-1]!=-1)
                par[j][i]=par[par[j][i-1]][i-1];
        }
    }
}
ll lca(ll u,ll v)
{
    if(d[u]>d[v])swap(u,v);
    ll df=d[v]-d[u];
    for(ll i=0;i<20;++i)
        if(df&(1<<i))v=par[v][i];
    if(u==v)return u;
    for (ll i=20-1; i>=0; i--) 
    {
        if (par[u][i] != par[v][i]) 
        { 
            u = par[u][i]; 
            v = par[v][i]; 
        } 
      }
    return par[u][0]; 
}
ll kthpar(ll u,ll k)
{
    for(int i=0;i<20;++i)
        if(k&(1<<i))
            u=par[u][i];
    return u;
}
ll pl(ll a,ll b)
{
    return d[a]+d[b]-2*d[lca(a,b)];
}
void init(ll n)
{
    sparseMatrix(n);
}
int _runtimeTerror_()
{
    ll n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);v[y].pb(x);
    }
    mem1(par);
    dfs(1,-1);
    init(n);
    for(int i=1;i<=n;++i)
        seg.a[in[i]]=a[i];
    seg.buildTree(1,0,n-1);
    int root=1;
    while(q--)
    {
        int tt,u,vv,x;
        cin>>tt;
        if(tt==1)
        {
            cin>>vv;
            root=vv;
        }
        else if(tt==2)
        {
            cin>>u>>vv>>x;
            bool xx= in[u]>=in[root] && in[u]<=out[root];
            bool yy= in[vv]>=in[root] && in[vv]<=out[root];
            if(xx==1 && yy==1)
            {
                int lc=lca(u,vv);
                if(lc!=root)
                    seg.rupdate(1,0,n-1,in[lc],out[lc],x);
                else seg.rupdate(1,0,n-1,0,n-1,x);
            }
            else if(xx^yy)
            {
                seg.rupdate(1,0,n-1,0,n-1,x);
            }
            else
            {
                ll ancestor=-1,dep=-1;
                ll ff=lca(u,vv);
                if(d[ff]>dep)
                    dep=d[ff],ancestor=ff;
                ff=lca(u,root);
                if(d[ff]>dep)
                    dep=d[ff],ancestor=ff;
                ff=lca(vv,root);
                if(d[ff]>dep)
                    dep=d[ff],ancestor=ff;
                if( in[ancestor]<=in[root] && out[ancestor]>=in[root])
                {
                    ll lc=kthpar(root,d[root]-d[ancestor]-1);
                    seg.rupdate(1,0,n-1,0,n-1,x);
                    seg.rupdate(1,0,n-1,in[lc],out[lc],-x);
                }
                else
                    seg.rupdate(1,0,n-1,in[ancestor],out[ancestor],x);
            }
        }
        else
        {
            cin>>vv;
            if(vv==root)
            {
                cout<<seg.query(1,0,n-1,0,n-1).sum<<endl;
                continue;
            }
            bool xx= in[vv]<=in[root] && out[vv]>=in[root];
            if(!xx)
            {
                cout<<seg.query(1,0,n-1,in[vv],out[vv]).sum<<"\n";
            }
            else
            {
                ll diff=d[root]-d[vv];
                ll x=kthpar(root,diff-1);
                cout<<seg.query(1,0,n-1,0,n-1).sum-seg.query(1,0,n-1,in[x],out[x]).sum<<"\n";
            }
        }
    }
    return 0;
}
// bas sahi se observe karna hai 
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