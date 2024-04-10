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

const int N = 200005;

struct node
{
    ll sum;
}fake={0};
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
            tree[v]=make_node(val+a[st]);
            a[st]+=val;
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in,val);
        else
            update(v<<1 | 1,mid+1,en,in,val);
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
    int lessThan(int v,int st,int en,int l)
    {
        if(tree[v].sum == 0)
            return -1;
        if(st > l)
            return -1;
        if(st == en)
            return st;
        int mid = (st + en)/2;
        int le = lessThan(v<<1|1,mid+1,en,l);
        if(le != -1)
            return le;
        return lessThan(v<<1,st,mid,l);
    }
    int greaterThan(int v,int st,int en,int l)
    {
        if(tree[v].sum == 0)
            return -1;
        if(en < l)
            return -1;
        if(st == en)
            return st;
        int mid = (st + en)/2;
        int le = greaterThan(v<<1,st,mid,l);
        if(le != -1)
            return le;
        return greaterThan(v<<1 | 1,mid+1,en,l);
    }
}seg;

vector<int> g[N];
int in[N],out[N],cur = 1,pos[N],dep[N];
int par[N][20];

ll a[N],b[N],dp[N],cnt[N],dpp[N],cntp[N];

void dfs(int s)
{
    in[s] = cur++;
    pos[in[s]] = s;
    for(int i=1;i<20;++i)
        par[s][i] = par[par[s][i-1]][i-1];
    for(auto &j:g[s])
    {
        par[j][0] = s;
        dep[j] = dep[s] + 1;
        dfs(j);
    }
    out[s] = cur-1;
}
int lca(int x,int y)
{
    if(dep[x] > dep[y])
        swap(x,y);
    int d = dep[y] - dep[x];
    for(int i=0;i<20;++i)
        if(d&(1<<i))
            y = par[y][i];
    if(x == y)
        return x;
    for(int i=19;i>=0;--i)
        if(par[x][i] != par[y][i])
            x = par[x][i],y = par[y][i];
    return par[y][0];
}

void dfs_dp(int s)
{
    dp[s] = b[s];
    ll x = 0;
    for(auto &j:g[s])
    {
        dfs_dp(j);
        x += dp[j];
    }
    amin(dp[s],x + a[s]);
    cnt[s] = x + a[s];
}

void dfs2(int s,ll u,ll v)
{
    u += dp[s];
    dpp[s] = u;
    v += cnt[s];
    cntp[s] = v;
    for(auto &j:g[s])
    {
        dfs2(j,u,v);
    }
}

int _runtimeTerror_()
{
    int n,Q;
    cin>>n>>Q;
    vector<int> p(n+1),l(n+2);
    for(int i=1;i<=n;++i)
        cin>>p[i];
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        cin>>b[i];
    vector<int> st;
    st.pb(n);
    for(int i=n-1;i>=1;--i)
    {
        while(!st.empty() && p[st.back()] < p[i])
        {
            l[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    while(!st.empty())
    {
        l[st.back()] = n+1;
        st.pop_back();
    }
    for(int i=1;i<=n;++i)
        g[l[i]].push_back(i);
    // root is n+1
    dfs(n+1);
    dfs_dp(n+1);
    dfs2(n+1,0,0);
    seg.buildTree(1,1,n+1);
    vector<bool> done(n+2,false);
    done[n+1] = true;
    ll ans = 0;
    seg.update(1,1,n+1,in[n+1],1);
    ans = cnt[n+1];
    auto add = [&](int u)
    {
        u = par[u][0];
        if(seg.query(1,1,n+1,in[u],out[u]).sum > 0)
        {
            seg.update(1,1,n+1,in[u],1);
            return ;
        }
        int left = seg.lessThan(1,1,n+1,in[u]);
        int right = seg.greaterThan(1,1,n+1,in[u]);
        pii deep = {-1,n+100};
        if(left != -1)
        {
            int l = lca(u,pos[left]);
            amax(deep,make_pair(dep[l],l));
        }
        if(right != -1)
        {
            int l = lca(u,pos[right]);
            amax(deep,make_pair(dep[l],l));
        }
        if(deep.S <= n+1)
        {
            ans += cntp[u] - cntp[deep.S] - (dpp[u] - dpp[deep.S]);
        }
        seg.update(1,1,n+1,in[u],1);
    };
    auto del = [&](int u)
    {
        u = par[u][0];
        seg.update(1,1,n+1,in[u],-1);
        if(seg.query(1,1,n+1,in[u],out[u]).sum > 0)
            return ;
        int left = seg.lessThan(1,1,n+1,in[u]);
        int right = seg.greaterThan(1,1,n+1,in[u]);
        pii deep = {-1,n+100};
        if(left != -1)
        {
            int l = lca(u,pos[left]);
            amax(deep,make_pair(dep[l],l));
        }
        if(right != -1)
        {
            int l = lca(u,pos[right]);
            amax(deep,make_pair(dep[l],l));
        }
        if(deep.S <= n+1)
        {
            ans -= cntp[u] - cntp[deep.S] - (dpp[u] - dpp[deep.S]);
        }
    };
    for(int i=0;i<Q;++i)
    {
        int x;
        cin>>x;
        if(done[x])
        {
            del(x);
            done[x] = false;
        }
        else
        {
            add(x);
            done[x] = true;
        }
        cout<<ans<<"\n";
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