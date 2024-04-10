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
const int N = 100005;

vector<int> v[N];
int n,k;
int par[N][20],in[N],out[N],cur = 1,dep[N];

template<typename T=long long>
struct fenwick {
    T a[N],bit[N];
    int n;
    fenwick() 
    {
        for(int i=1;i<=N-2;++i)
            a[i] = T(0),bit[i] = T(0);
    }
    void build(int n_)
    {
        n = n_;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;j+=j&-j)
                bit[j] += a[i];
    }
    void update(int j,T val)
    {
        for(;j<=n;j+=j&-j)
            bit[j] += val;
    }
    T get(int r)
    {
        T u = 0;
        for(;r;r-=r&-r)
            u += bit[r]; 
        return u;
    }
    T query(int l,int r)
    {
        return get(r)-get(l-1);
    }
};
// call fenw.build(n);
fenwick<> fenw;
void dfs(int s,int p)
{
    in[s] = cur++;
    par[s][0] = p;
    for(int j=1;j<20;++j)
        par[s][j] = par[par[s][j-1]][j-1];
    for(int &j:v[s])
    {
        if(j!=p)
        {
            dep[j] = dep[s] + 1;
            dfs(j,s);
        }
    }
    out[s] = cur-1;
}

int _runtimeTerror_()
{
    cin>>n>>k;
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    int ans = 1;
    fenw.build(n);
    dfs(1,0);
    assert(cur==n+1);
    int l = 1,r = 1;
    fenw.update(in[1],1);
    int val = 1;
    auto get = [&](int u)
    {
        if(u==0)
            u = 1;
        return fenw.query(in[u],out[u]);
    };
    auto del = [&](int u,int v)
    {
        int x = u;
        fenw.update(in[u],-1);
        for(int j=19;j>=0;--j)
        {
            if(get(par[u][j])==0)
                u = par[u][j];
        }
        if(get(u)==0)
            u = par[u][0];
        val -= dep[x] - dep[u];
        for(int j=19;j>=0;--j)
        {
            if(get(par[v][j]) < r-l)
                v = par[v][j];
        }
        if(get(v)<r-l)
            v = par[v][0];
        if(dep[v] >= dep[u])
            val -= dep[v] - dep[u];
    };
    auto possible = [&](int u,int v)
    {
        int x = u;
        for(int j=19;j>=0;--j)
        {
            if(get(par[u][j])==0)
                u = par[u][j];
        }
        if(get(u)==0)
            u = par[u][0];
        int fx = 0;
        fx += dep[x] - dep[u];
        for(int j=19;j>=0;--j)
        {
            if(get(par[v][j]) < r-l+1)
                v = par[v][j];
        }
        if(get(v) < r-l+1)
            v = par[v][0];
        if(dep[v] >= dep[u])
            fx += dep[v] - dep[u];
        if(val + fx<=k)
        {
            val += fx,fenw.update(in[x],1);
            return true;
        }
        return false;
    };
    for(int i=1;i<=n;++i)
    {
        if(r==n)
            break;
        if(r<i)
        {
            assert(r==i-1 && l==i-1);
            fenw.update(in[i-1],-1);
            fenw.update(in[i],1);
            l = r = i;
        }
        else if(r>=i)
        {
            if(l<i)
            {
                del(l,i);
                l = i;
            }
        }
        while(r<n && possible(r+1,r))
        {
            ++r;
        }
        amax(ans,r-l+1);
    }
    cout<<ans<<"\n";
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