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

const int N = 100005;

vector<int> v[N];
int sub[N];

void dfs_sz(int s,int p)
{
    sub[s] = 1;
    for(auto &j:v[s])
        if(j!=p)
            dfs_sz(j,s),sub[s] += sub[j];
}

struct node
{
    ll sum = 0;
}fake;
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
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
            tree[v]=make_node(a[st]+val);
            a[st] += val;
            // cout<<st<<" "<<val<<"\n";
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
        tree[v]=combine(tree[v<<1],tree[v<<1 | 1]);
    }
    int query(ll v,ll st,ll en,int i)
    {
        assert(tree[v].sum >= 0);
        if(tree[v].sum == 0)
            return 1e8;
        if(en < i)
            return 1e8;
        if(st == en)
            return st;
        ll mid=(st+en)>>1;
        int u = query(v<<1,st,mid,i);
        if(u != 1e8)
            return u;
        return query(v<<1|1,mid+1,en,i);
    }
}seg1,seg2,seg3;

int ans[N],n;
vector<int> vec[N];
int root = 0,in[N],cur = 1;

void dfs(int s,int p,bool keep)
{
    in[s] = cur++;
    int mx = -1,bc = -1;
    for(auto &j:v[s])
        if(j!=p && sub[j] > mx)
            mx = sub[j],bc = j;
    seg1.update(1,1,n,sub[s],-1);
    seg3.update(1,1,n,sub[s],1);
    for(auto &j:v[s])
    {
        if(j!=p && j!=bc)
        {
            dfs(j,s,0);
        }
    }
    if(bc != -1)
        dfs(bc,s,1),swap(vec[s],vec[bc]);
    for(auto &j:v[s])
    {
        if(j!=p && j!=bc)
        {
            for(auto &k:vec[j])
                vec[s].push_back(k),seg1.update(1,1,n,sub[k],-1);
        }
    }
    vec[s].push_back(s);
    vector<pii> g;
    if(p)
        g.push_back({n-sub[s],root});
    for(auto &j:v[s])
        if(j!=p)
            g.push_back({sub[j],j});
    sort(all(g),greater<pii>());
    if(sz(g) == 1)
        ans[s] = g[0].first;
    else if(g[0].second == root)
    {
        ans[s] = g[0].first;
        int small = g.back().first;
        int lo = g[1].first,hi = g[0].first;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            if(mid == g[0].first)
                break;
            int val = g[0].first - mid;
            int mn = seg1.query(1,1,n,val);
            amin(mn,seg3.query(1,1,n,val+sub[s])-sub[s]);
            if(small + mn <= mid)
                amin(ans[s],mid),hi = mid-1;
            else
                lo = mid+1;
        }
    }
    else
    {
        ans[s] = g[0].first;
        int small = g.back().first;
        int lo = g[1].first,hi = g[0].first;
        while(lo <= hi)
        {
            int mid = (lo + hi)/2;
            if(mid == g[0].first)
                break;
            int val = g[0].first - mid;
            val = seg2.query(1,1,n,val);
            if(small + val <= mid)
                amin(ans[s],mid),hi = mid-1;
            else
                lo = mid+1;
        }
    }
    seg3.update(1,1,n,sub[s],-1);
    if(keep)
    {
        seg2.update(1,1,n,sub[s],1);
        for(auto &j:v[s])
            if(j!=p && j!=bc)
                for(auto &k:vec[j])
                    seg2.update(1,1,n,sub[k],1);

    }
    else
    {
        for(auto &j:vec[s])
        {
            if(bc != -1 && in[j] >= in[bc])
                seg2.update(1,1,n,sub[j],-1);
            seg1.update(1,1,n,sub[j],1);
        }
    }
}

int _runtimeTerror_()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x,y;
        cin>>x>>y;
        if(x == 0)
            root = y;
        else
            v[x].push_back(y),v[y].push_back(x);
    }
    if(n == 1)
    {
        cout<<"0\n";return 0;
    }
    dfs_sz(root,0);
    for(int i=1;i<=n;++i)
        seg1.a[i] = seg2.a[i] = seg3.a[i] = 0;
    for(int i=1;i<=n;++i)
    {
        ++seg1.a[sub[i]];
    }
    seg1.buildTree(1,1,n);
    seg2.buildTree(1,1,n);
    seg3.buildTree(1,1,n);
    dfs(root,0,0);
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<"\n";
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