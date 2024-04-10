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

const int N = 200005;

struct node
{
    int mx;
}fake{(int)-2e9};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE()
    {
        for(int i=0;i<4*N;++i)
            tr2[i] = 2e9; 
    }
    node tree[4*N];
    int tr2[4*N];
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
    void rupdate(int v,int st,int en,int l,int r,ll val)
    {
        if(st>r || en<l)
            return ;
        ll mid=(st+en)>>1;
        if(st>=l && en<=r)
        {
            amin(tr2[v],val);
            return ;
        }
        rupdate(v<<1,st,mid,l,r,val);
        rupdate(v<<1 | 1,mid+1,en,l,r,val);
    }
    int query_max(int v,int st,int en,int l,int r)
    {
        if(st>r || en<l)
            return -2e9;
        if(st>=l && en<=r)
            return tree[v].mx;
        int mid = (st+en)/2;
        return max(query_max(v<<1,st,mid,l,r),query_max(v<<1 | 1,mid+1,en,l,r));
    }
    void query_min(int v,int st,int en,int id,int &val)
    {
        amin(val,tr2[v]);
        if(st==en)
            return ;
        int mid = (st+en)/2;
        if(id<=mid)
            query_min(v<<1,st,mid,id,val);
        else
            query_min(v<<1 | 1,mid+1,en,id,val);
    }
}seg;

int ans[N],w[N];
vector<pii> v[N];
int sub[N],dep[N],par[N],ped[N];

void dfs_size(int s=1,int p=-1)
{
    sub[s]=1;
    for(auto [j,k]:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1;
            par[j]=s;
            dfs_size(j,s);
            sub[s]+=sub[j];
        }
    }
}

int head[N],pos[N],in[N],out[N],cur=0;
void hld(int s,int p,int h,int vx)
{
    head[s]=h;
    int hv=-1,mx=-1,we=-1;
    pos[s]=cur++;
    seg.a[pos[s]]=w[vx];
    // cout<<"w "<<w[vx]<<"\n";
    ped[s] = vx;
    in[s]=pos[s];
    for(auto [j,k]:v[s])
        if(j!=p)
            if(sub[j]>mx)
                mx=sub[j],hv=j,we=k;

    if(hv!=-1)
        hld(hv,s,h,we);
    for(auto [j,k]:v[s])
        if(j!=p && j!=hv)
            hld(j,s,j,k);
    out[s]=cur-1;
}

struct edge
{
    int x,y,w,idx;
    bool un = false;
};

int p[N],rnk[N];
int parent(int i)
{
    return p[i] = (p[i]==i)?i:parent(p[i]);
}

bool merge(int x,int y)
{
    x = parent(x),y = parent(y);
    if(x==y)
        return false;
    if(rnk[x]>rnk[y])
        swap(x,y);
    p[x] = y;
    if(rnk[x] == rnk[y])
        ++rnk[y];
    return true;
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<edge> ed(m);
    for(int i=0;i<m;++i)
    {
        cin>>ed[i].x>>ed[i].y>>ed[i].w;
        w[i] = ed[i].w;
        ed[i].idx = i;
    }
    sort(all(ed),[&](edge &a,edge &b){
        return a.w<b.w;
    });
    for(int i=1;i<=n;++i)   
        rnk[i] = 0,p[i] = i;
    for(int i=0;i<m;++i)
    {
        if(merge(ed[i].x,ed[i].y))
        {
            ed[i].un = true;
            v[ed[i].x].pb({ed[i].y,ed[i].idx});
            v[ed[i].y].pb({ed[i].x,ed[i].idx});
        }
    }
    dfs_size(1,0);
    hld(1,0,1,0);
    seg.buildTree(1,0,n-1);
    for(int i=0;i<m;++i)
    {
        if(ed[i].un)
            continue;
        int a = ed[i].x,b = ed[i].y;
        int mx = -1;
        for(;head[a] != head[b];b = par[head[b]])
        {
            if(dep[head[a]]>dep[head[b]])
                swap(a,b);
            amax(mx,seg.query_max(1,0,n-1,pos[head[b]],pos[b]));
            seg.rupdate(1,0,n-1,pos[head[b]],pos[b],ed[i].w);
        }
        if(dep[a]>dep[b])
            swap(a,b);
        amax(mx,seg.query_max(1,0,n-1,pos[a]+1,pos[b]));
        seg.rupdate(1,0,n-1,pos[a] + 1,pos[b],ed[i].w);
        assert(mx != -1);
        ans[ed[i].idx] = mx - 1;
    }
    for(int i=2;i<=n;++i)
    {
        int l = 2e9;
        seg.query_min(1,0,n-1,in[i],l);
        --l;
        ans[ped[i]] = l>=1e9+100?-1:l;
    }
    for(int i=0;i<m;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
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