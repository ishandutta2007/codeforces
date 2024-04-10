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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2401
#endif


const int N = 200005;

struct node
{
    ll sum;
    ll ver;
}fake{-INF,-INF};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
    ll lazy[4*N];
    inline node combine(node a,node b)
    {
        node ret;
        ret.sum=max(a.sum,b.sum);
        if(ret.sum == a.sum) {
            ret.ver = a.ver;
        }
        else {
            ret.ver = b.ver;
        }
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
        tree[v].sum+=lazy[v];
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
            tree[v].ver = st;
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

int _runtimeTerror_()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=n-1;++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y), g[y].push_back(x);
    }
    vector<int> in(n+1), out(n+1), par(n+1), vis(n+1), dep(n+1), pos(n+1);
    dep[1] = 1;
    int lfs = 0;
    int cur = 0;
    function<void(int,int)> dfs = [&](int s, int p) {
        par[s] = p;
        in[s] = cur++;
        pos[in[s]] = s;
        int cnt = 0;
        for(auto &j:g[s]) {
            if(j == p) {
                continue;
            }
            ++cnt;
            dep[j] = dep[s] + 1;
            dfs(j, s);
        }
        if(cnt == 0) {
            ++lfs;
        }
        out[s] = cur - 1;
    };
    dfs(1, 0);

    // if(lfs <= k) {
    //     ll ans = -INF;
    //     for(int i=0;i<=k;++i) {
    //         amax(ans, (n - i) * 1ll * (i));
    //     }
    //     cout << ans << "\n";
    //     return 0;
    // }

    for(int i=0;i<n;++i) {
        seg.a[i] = dep[pos[i]];
    }
    seg.buildTree(1, 0, n-1);
    int done = 0;
    vis[0] = 1;
    ll ans = -INF;
    for(int i=1;i<=k;++i) {
        assert(seg.tree[1].ver >= 0 && seg.tree[1].ver < n);
        auto u = pos[seg.tree[1].ver];
        // debug(u);
        while(!vis[u]) {
            seg.rupdate(1,0,n-1,in[u],out[u],-1);
            vis[u] = true;
            ++done;
            u = par[u];
        }
        // (n - i - t) * (i - t) t = [0, n - done]
        ll f = n - i, g = i;
        if(f > g) {
            swap(f, g);
        }
        int l = 0, r = n - done;
        if((f + g) / 2 <= r) {
            amax(ans, (f - (f + g)/2) * (g - (f + g)/2));
        }
        else {
            amax(ans, (f - r) * (g - r));
        }
        // debug(i, ans);
    }
    cout << ans << "\n";
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
    int TESTS = 1;
    //cin >> TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}