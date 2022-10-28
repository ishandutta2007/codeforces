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

//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());


const int NN = 15000000;
struct node{
    ll val;
    int L,R;
    node (): L(-1),R(-1),val(0){};
    node(ll x) : L(-1),R(-1),val(x){};
};
struct PERTREE{
    node tree[NN];
    int cursz=0;
    int buildTree(ll st,ll en)
    {
        ll v = cursz++;
        tree[v]=node();
        if(st==en)
            return v;
        ll mid=(st+en)>>1;
        tree[v].L=buildTree(st,mid);
        tree[v].R=buildTree(mid+1,en); 
        return v;
    }
    int update(ll v,ll st,ll en,ll pos,ll val)
    {
        ll u=cursz++;
        tree[u] = tree[v];
        if(st==en)
        {
            tree[u].val ^= val;
            return u;
        }
        ll mid=(st+en)>>1;
        if(pos<=mid)
            tree[u].L=update(tree[v].L,st,mid,pos,val);
        else 
            tree[u].R=update(tree[v].R,mid+1,en,pos,val);
        tree[u].val = tree[tree[u].L].val ^ tree[tree[u].R].val;
        return u;
    }
    int query(int r1,int r2,int st,int en,int l,int r)
    {
        if(st>r || en<l)
            return -1;
        if((tree[r1].val ^ tree[r2].val) == 0)
            return -1;
        if(st == en)
            return st;
        int mid=(st+en)>>1;
        int u = query(tree[r1].L,tree[r2].L,st,mid,l,r);
        if(u != -1)
            return u;
        return query(tree[r1].R,tree[r2].R,mid+1,en,l,r);
    }
}seg;

const int N = 600005;

int a[N];
vector<int> v[N];
 
int par[N][20],dep[N];
int pos[N];
int roots[N];
int n;
ll h[N];

void dfs(int s,int p)
{
    roots[s] = seg.update(roots[p],1,n,a[s],h[a[s]]);
    par[s][0] = p;
    for(int i=1;i<20;++i)
        par[s][i] = par[par[s][i-1]][i-1];
    for(auto &j:v[s])
    {
        if(j!=p)
        {
            dep[j] = dep[s] + 1;
            dfs(j,s);
        }
    }
}

int _runtimeTerror_()
{
    int Q;
    cin>>n>>Q;
    for(int i=1;i<=n;++i)
        cin >> a[i];
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin >> x >> y;
        v[x].pb(y),v[y].pb(x);
    }
    for(int i=1;i<=n;++i)
        h[i] = rng()%(1LL<<62);
    roots[0] = seg.buildTree(1,n);
    dfs(1,0);
    auto lca = [&](int u,int v)
    {
        if(dep[u]>dep[v])
            swap(u,v);
        int d = dep[v] - dep[u];
        for(int i=0;i<20;++i)
            if(d&(1<<i))
                v = par[v][i];
        if(u == v)
            return u;
        for(int i=19;i>=0;--i)
        {
            if(par[u][i] != par[v][i])
                u = par[u][i],v = par[v][i];
        }
        return par[u][0];
    };
    for(int i=1;i<=Q;++i)
    {
        int u,v,l,r;
        cin>>u>>v>>l>>r;
        int lc = lca(u,v);
        int t = seg.update(roots[u],1,n,a[lc],h[a[lc]]);
        cout << seg.query(roots[v],t,1,n,l,r) << "\n";
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