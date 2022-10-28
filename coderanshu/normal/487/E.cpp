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

struct BCT
{
    int n;
    vector<vector<int>> g;
    vector<bool> cut;
    vector<int> comp;

    BCT(){}

    BCT(int N): n(N) {
        g.resize(N+1);
        cut.resize(N+1,0);
        comp.resize(N+1);
        iota(all(comp),0);
    }

    void add_edge(int x,int y) {
        g[x].push_back(y),g[y].push_back(x);
    }

    vector<vector<int>> biconnected_comps()
    {
        vector<bool> vis(n+1);
        vector<int> dep(n+1),low(n+1);
        vector<int> st;

        vector<vector<int>> cmp;

        function<void(int,int)> dfs = [&](int s,int p)
        {
            vis[s] = true;
            st.push_back(s);
            int cnt = 0;
            low[s] = dep[s];
            for(auto j:g[s])
            {
                if(j == p)
                    continue;
                if(vis[j])
                    low[s] = min(low[s],dep[j]);
                else
                {
                    dep[j] = dep[s] + 1;
                    dfs(j,s);
                    low[s] = min(low[s],low[j]);
                    if(low[j] >= dep[s])
                    {
                        ++cnt;
                        cmp.push_back({s});
                        if(p || cnt >= 2)
                            cut[s] = true;
                        while(st.back() != j)
                        {
                            cmp.back().push_back(st.back());
                            st.pop_back();
                        }
                        st.pop_back();
                        cmp.back().push_back(j);
                    }
                }
            }
        };
        dfs(1,0);
        return cmp;
    }

    int build(vector<vector<int>> &g)
    {
        int cur = n+1;
        auto f = biconnected_comps();
        g.resize(n + f.size() + 2);
        for(auto &j:f)
        {
            for(auto &i:j)
            {
                if(!cut[i])
                    comp[i] = cur;
                if(cut[i])
                    g[cur].push_back(i),g[i].push_back(cur);
            }
            ++cur;
        }
        return --cur;
    }

    bool is_cut(int u)
    {
        if(u <= n)
            return cut[u];
        return false;
    }

    int& operator[](int u) {
        if(u > comp.size())
            assert(false);
        return comp[u];
    }
}bct;


const int N = 200005;
int sub[N],dep[N],par[N];

void dfs_size(int s,int p,vector<vector<int>>&v)
{
    sub[s]=1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j]=dep[s]+1;
            par[j]=s;
            dfs_size(j,s,v);
            sub[s]+=sub[j];
        }
    }
}

int head[N],pos[N],in[N],out[N],cur=1;
void hld(int s,int p,int h,vector<vector<int>> &v)
{
    head[s]=h;
    int hv=-1,mx=-1;
    pos[s]=cur++;
    //seg.a[pos[s]]=val[s];
    in[s]=pos[s];
    for(auto j:v[s])
        if(j!=p)
            if(sub[j]>mx)
                mx=sub[j],hv=j;

    if(hv!=-1)
        hld(hv,s,h,v);
    for(auto j:v[s])
        if(j!=p && j!=hv)
            hld(j,s,j,v);
    out[s]=cur-1;
}


struct node
{
    ll sum;
}fake={INF};
    // base value is assigned to fake node
struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    node tree[4*N];
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
    node query(ll v,ll st,ll en,ll l,ll r)
    {
        if(en<l || st>r)
            return fake;
        if(st>=l && en<=r)
            return tree[v];
        ll mid=(st+en)>>1;
        return combine(query(v<<1,st,mid,l,r),query(v<<1 | 1,mid+1,en,l,r));
    }
}seg;

int _runtimeTerror_()
{
    int n,m,Q;
    cin>>n>>m>>Q;
    vector<int> w(n+1);
    vector<multiset<int>> A(2*n+1);
    for(int i=1;i<=n;++i)
        cin>>w[i];
    BCT G(n);
    for(int i=1;i<=m;++i)
    {
        int x,y;
        cin>>x>>y;
        G.add_edge(x,y);
    }
    vector<vector<int>> g;
    int root = G.build(g);
    dfs_size(root,0,g);
    hld(root,0,root,g);
    // cout<<"Comp : ";
    // for(int i=1;i<=n;++i)
    //     cout<<G[i]<<" ";
    // cout<<"\n";
    // return 0;
    for(int i=1;i<=n;++i)
    {
        if(G.is_cut(i))
            A[par[i]].insert(w[i]);
        A[G[i]].insert(w[i]);
    }
    for(int i=1;i<=root;++i)
        seg.a[i] = INF;
    for(int i=1;i<=root;++i)
    {
        if(!A[i].empty())
        {
            seg.a[in[i]] = *A[i].begin();
        }
    }
    seg.buildTree(1,1,root);
    auto updd = [&](int u,int rm,int x)
    {
        A[u].erase(A[u].find(rm));
        A[u].insert(x);
        seg.update(1,1,root,in[u],*A[u].begin());
    };
    auto upd = [&](int u,int x)
    {
        if(!G.is_cut(u))
        {
            updd(G[u],w[u],x);
            w[u] = x;
            return ;
        }
        updd(u,w[u],x);
        updd(par[u],w[u],x);
        w[u] = x;
    };

    auto query = [&](int a,int b)
    {
        if(a == b)
            return 1ll*w[a];
        a = G[a],b = G[b];
        ll ans = INF;
        for(;head[a] != head[b];b = par[head[b]])
        {
            if(dep[head[a]] > dep[head[b]])
                swap(a,b);
            // cout<<pos[head[b]]<<" "<<pos[b]<<"\n";
            amin(ans,seg.query(1,1,root,pos[head[b]],pos[b]).sum);
        }
        // cout<<a<<" "<<b<<"\n";
        // cout<<pos[a]<<" "<<pos[b]<<"\n";
        if(dep[a] > dep[b])
            swap(a,b);
        amin(ans,seg.query(1,1,root,pos[a],pos[b]).sum);
        if(!G.is_cut(a))
            amin(ans,seg.query(1,1,root,pos[par[a]],pos[par[a]]).sum);
        return ans;
    };
    for(int _=0;_<Q;++_)
    {
        char c;
        int x,y;
        cin>>c>>x>>y;
        if(c == 'C')
            upd(x,y);
        else
            cout<<query(x,y)<<"\n";
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