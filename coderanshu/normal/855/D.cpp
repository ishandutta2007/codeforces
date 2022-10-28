#include<bits/stdc++.h>
using namespace std ;

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

const int M=1000000007;
const int MM=998244353;
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
const int LOGN=20;
vector<pair<int,int>> v[N];
int n;
vector<int> roots;
int cmp[N],cno=1;

int sub[N],dep[N],par[N][LOGN];

void dfs_size(int s=1,int p=-1)
{
    sub[s]=1;
    cmp[s]=cno;
    for(auto j:v[s])
    {
        if(j.F!=p)
        {
            dep[j.F]=dep[s]+1;
            par[j.F][0]=s;
            dfs_size(j.F,s);
            sub[s]+=sub[j.F];
        }
    }
}

void sparseMatrix(ll n)
{
    for(ll i=1;i<LOGN;++i)
        for(ll j=1;j<=n;++j)
                par[j][i]=par[par[j][i-1]][i-1];
}
ll lca(ll u,ll v)
{
    if(dep[u]>dep[v])swap(u,v);
    ll df=dep[v]-dep[u];
    for(ll i=0;i<LOGN;++i)
        if(df&(1<<i))v=par[v][i];
    if(u==v)return u;
    for (ll i=LOGN-1; i>=0; i--) 
    {
        if(par[u][i]!=par[v][i]) 
        { 
            u=par[u][i]; 
            v=par[v][i];
        } 
    }
    return par[u][0]; 
}

int head[N],pos[N],in[N],out[N],cur=0;
void hld(int s,int p,int h,int w)
{
    head[s]=h;
    int hv=-1,mx=-1;
    pos[s]=cur++;
    seg.a[pos[s]]=w;
    //seg.a[pos[s]]=val[s];
    in[s]=pos[s];
    int pass=-1;
    for(auto j:v[s])
        if(j.F!=p)
            if(sub[j.F]>mx)
                mx=sub[j.F],hv=j.F,pass=j.S;

    if(hv!=-1)
        hld(hv,s,h,pass);
    for(auto j:v[s])
        if(j.F!=p && j.F!=hv)
            hld(j.F,s,j.F,j.S);
    out[s]=cur-1;
}
int query(int a,int b)
{
    int ans=0;
    for(;head[a]!=head[b];b=par[head[b]][0])
    {
        if(dep[head[a]]>dep[head[b]])
            swap(a,b);
        ans+=seg.query(1,0,n-1,pos[head[b]],pos[b]).sum;
    }
    if(dep[a]>dep[b])
        swap(a,b);
    ans+=seg.query(1,0,n-1,pos[a]+1,pos[b]).sum;
    return ans;
}
int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int pp,tt;
        cin>>pp>>tt;
        if(pp==-1)
            roots.pb(i);
        else
        {   
            tt^=1;
            v[pp].pb({i,tt});
            v[i].pb({pp,tt});
        }
    }
    for(auto k:roots)
    {
        dfs_size(k,0);
        hld(k,0,k,0);
        ++cno;
    }
    sparseMatrix(n);
    seg.buildTree(1,0,n-1);
    assert(cur==n);
    int q;
    cin>>q;
    while(q--)
    {
        int tt,x,y;
        cin>>tt>>x>>y;
        if(cmp[x]!=cmp[y] || x==y)
        {
            cout<<"NO\n";continue;
        }
        int l=lca(x,y);
        if(tt==1)
        {
            if(l!=x)
            {
                cout<<"NO\n";continue;
            }
            int xx=query(y,x);
            if(xx==dep[y]-dep[x])
                cout<<"YES\n";
            else cout<<"NO\n";
        }
        else if(tt==2)
        {
            int xx=query(y,l);
            int yy=query(x,l);
            if(l!=y && xx==0 && yy==dep[x]-dep[l])
                cout<<"YES\n";
            else
                cout<<"NO\n";
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