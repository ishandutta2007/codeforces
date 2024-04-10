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

struct Matrix
{
    ll val[3][3];
    // Matrix (ll n) : n_(n)
    // {
    //     val.resize(n_);
    //     for(ll i=0;i<n_;++i)
    //         val[i].resize(n_);
    // }
    Matrix () {
        for(int i=0;i<3;++i)
            for(int j=0;j<3;++j)
                val[i][j] = 0;
    }
    void print()
    {
        for(ll i=0;i<3;++i)
        {
            for(ll j=0;j<3;++j)
                cout<<val[i][j]<<" ";
            cout<<"\n";
        }
    }
    void set(ll x)
    {
        for(ll i=0;i<3;++i)
            for(ll j=0;j<3;++j)
                val[i][j]=x;
    }
    Matrix operator*(const Matrix& b) const 
    {
        Matrix ans;
        for(ll i=0;i<3;++i)
        {
            for(ll j=0;j<3;++j)
            {
                ans.val[i][j]=-INF;
                for(ll k=0;k<3;++k)
                {
                    amax(ans.val[i][j], val[i][k] + b.val[k][j]);
                }
            }
        }
        return ans;
    }
};

const int N = 100005;

vector<pll> v[N];

int sub[N],par[N],dep[N],head[N],in[N],out[N],pos[N],cur = 1,id[N];

ll w[N];
ll g[N][2],f[N][2];
multiset<ll> H[N][2];

void dfs(int s,int p)
{
    par[s] = p;
    sub[s] = 1;
    for(auto [j,k]:v[s])
    {
        if(j!=p)
        {
            w[j] = k;
            dep[j] = dep[s] + 1;
            dfs(j,s);
            sub[s] += sub[j];
        }
    }
}
int leaf[N];
void get(int u)
{
    g[u][0] = g[u][1] = 0;
    if(!H[u][0].empty())
        amax(g[u][0],*H[u][0].rbegin());
    if(!H[u][1].empty())
    {
        if(H[u][1].size() == 1)
            amax(g[u][0],*H[u][1].rbegin());
        else
            amax(g[u][0],*H[u][1].rbegin() + *(++H[u][1].rbegin()));
        amax(g[u][1],*H[u][1].rbegin());
    }
    // cout<<"u : ";
    // cout<<g[u][1]<<"\n";
}
void hld(int s,int p,int h)
{
    head[s]=h;
    int hv=-1,mx=-1;
    pos[s]=cur++;
    in[s]=pos[s];
    leaf[h] = s;
    id[pos[s]] = s;
    for(auto [j,k]:v[s])
        if(j!=p)
            if(sub[j]>mx)
                mx=sub[j],hv=j;

    if(hv!=-1)
    {
        hld(hv,s,h);
    }
    for(auto [j,k]:v[s])
    {
        if(j!=p && j!=hv)
        {
            hld(j,s,j);
            H[s][0].insert(f[j][0]);
            H[s][1].insert(f[j][1]);
        }
    }
    get(s);
    if(hv != -1)
    {
        f[s][0] = max({f[hv][0],g[s][0],f[hv][1]+g[s][1]});
        f[s][1] = max(f[hv][1],g[s][1]) + w[s];
    }
    else
    {
        f[s][0] = 0,f[s][1] = w[s];
    }
    out[s]=cur-1;
}

struct SEGTREE
{
    ll a[N];
    SEGTREE(){ }
    Matrix tree[4*N];
    inline Matrix make_node(ll val)
    {
        val = id[val];
        Matrix ret;
        ret.val[0][0] = 0,ret.val[0][1] = g[val][1], ret.val[0][2] = g[val][0];
        ret.val[1][0] = -INF,ret.val[1][1] = w[val],ret.val[1][2] = g[val][1] + w[val];
        ret.val[2][0] = ret.val[2][1] = -INF,ret.val[2][2] = 0;
        return ret;
    }
    void buildTree(ll v,ll st,ll en)
    {
        if(st==en)
        {
            tree[v]=make_node(st);
            return ;
        }
        ll mid=(st+en)>>1;
        buildTree(v<<1,st,mid);
        buildTree(v<<1 | 1,mid+1,en);
        tree[v] = tree[v<<1] * tree[v<<1 | 1];
    }
    void update(ll v,ll st,ll en,int in)
    {
        ll mid=(st+en)>>1;
        if(st==en)
        {
            tree[v]=make_node(st);
            return ;
        }
        if(in<=mid)
            update(v<<1,st,mid,in);
        else
            update(v<<1 | 1,mid+1,en,in);
        tree[v] = tree[v<<1] * tree[v<<1 | 1];
    }
    void query(ll v,ll st,ll en,ll l,ll r,Matrix &ans)
    {
        if(en<l || st>r)
            return ;
        if(st>=l && en<=r)
        {
            int cnt = 0;
            for(int i=0;i<3;++i)
                for(int j=0;j<3;++j)
                    cnt += ans.val[i][j] == 0;
            if(cnt == 9)
                ans = tree[v];
            else
                ans = ans * tree[v];
            return ;
        }
        ll mid=(st+en)>>1;
        query(v<<1,st,mid,l,r,ans); 
        query(v<<1 | 1,mid+1,en,l,r,ans);
        return ;
    }
}seg;

int _runtimeTerror_()
{
    int n,Q;
    ll W;
    cin>>n>>Q>>W;
    vector<pii> ed;
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        ll w;
        cin>>x>>y>>w;
        v[x].pb({y,w});
        v[y].pb({x,w});
        ed.pb({x,y});
    }
    dfs(1,0);
    hld(1,0,1);
    seg.buildTree(1,1,n);
    ll last = 0;
    auto ans = [&]()
    {
        Matrix u;
        seg.query(1,1,n,pos[1],pos[leaf[1]],u);
        // u.print();
        return (last = max({u.val[0][0],u.val[0][1],u.val[0][2]}));
    };
    auto upd = [&](int u,ll W)
    {
        int uu = u;
        while(u)
        {
            int h = head[u];
            if(par[h] == 0)
                break;
            Matrix qq;
            seg.query(1,1,n,pos[h],pos[leaf[h]],qq);
            ll t1 = max({qq.val[0][0],qq.val[0][1],qq.val[0][2]});
            ll t2 = max({qq.val[1][0],qq.val[1][1],qq.val[1][2]});
            H[par[h]][0].erase(H[par[h]][0].find(t1));
            H[par[h]][1].erase(H[par[h]][1].find(t2));
            u = par[h];
        }
        u = uu;
        w[u] = W;
        seg.update(1,1,n,pos[u]);
        while(u)
        {
            int h = head[u];
            if(par[h] == 0)
                break;
            Matrix qq;
            seg.query(1,1,n,pos[h],pos[leaf[h]],qq);
            ll t1 = max({qq.val[0][0],qq.val[0][1],qq.val[0][2]});
            ll t2 = max({qq.val[1][0],qq.val[1][1],qq.val[1][2]});
            H[par[h]][0].insert(t1);
            H[par[h]][1].insert(t2);
            get(par[h]);
            seg.update(1,1,n,pos[par[h]]);
            u = par[h];
        }
    };
    for(int i=1;i<=Q;++i)
    {
        int x;
        ll w;
        cin>>x>>w;
        x = (x + last)%(n-1);
        w = (w + last)%W;
        int u = par[ed[x].S] == ed[x].F?ed[x].S : ed[x].F;
        upd(u,w);
        cout<<(ans())<<"\n";
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