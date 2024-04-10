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

const int N = 1005,E = 30005;
vector<pii> v[N];

ll w[E];
vector<pii> ed;
vector<int> back,tr;

bitset<N> vis;
bitset<E> br,av;
int par[N],dp[N],dep[N],par_ed[N];
int root;

void dfs(int s,int p,int edge,bool push = true)
{
    vis[s] = true;
    par[s] = p;
    par_ed[s] = edge;
    dp[s] = 0;
    for(auto [j,k]:v[s])
    {
        if(!av[k])
            continue;
        if(!vis[j])
        {
            if(push)
                tr.pb(k);
            dep[j] = dep[s] + 1;
            dfs(j,s,k,push);
            dp[s] += dp[j];
        }
        else if(k!=edge)
        {
            if(dep[j]<dep[s])
            {
                back.pb(k);
                ++dp[s];
            }
            else if(dep[j]>dep[s])
            {
                --dp[s];
            }
        }
    }
    if(s!=root && dp[s]==0)
    {
        br[edge] = true;
    }
}

pair<ll,vector<int>> ans;

pair<ll,int> get(int u)
{
    pair<ll,int> ans = {INF,-1};
    while(u!=root)
    {
        int v = par_ed[u];
        if(br[v])
        {
            amin(ans,make_pair(w[v],v));
        }
        u = par[u];
    }
    return ans;
}

int _runtimeTerror_()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    root = s;
    for(int i=0;i<m;++i)
    {
        av[i] = 1;
        int x,y;
        cin>>x>>y;
        v[x].pb({y,i});
        v[y].pb({x,i});
        cin>>w[i];
        ed.pb({x,y});
    }
    dfs(s,0,0);
    if(!vis[t])
    {
        cout<<"0\n0\n";
        return 0;
    }
    ans.F = INF;
    auto x = get(t);
    amin(ans,make_pair(x.F,vector<int>{x.S}));
    for(auto &j:back)
    {
        ll val = w[j];
        int u = ed[j].F,v = ed[j].S;
        if(dep[v]<dep[u])
            swap(u,v);
        while(v!=u)
        {
            --dp[v];
            if(dp[v]==0)
                br[par_ed[v]] = true;
            v = par[v];
        }
        auto x = get(t);
        val += x.F;
        amin(ans,make_pair(val,vector<int>{x.S,j}));
        v = ed[j].F^ed[j].S^u;
        while(v!=u)
        {
            if(dp[v]==0)
                br[par_ed[v]] = false;
            ++dp[v];
            v = par[v];
        }
    }
    for(auto &j:tr)
    {
        ll val = w[j];
        av[j] = false;
        back.clear();
        vis.reset();
        br.reset();
        dfs(s,0,0,false);
        if(vis[t])
        {
            auto x = get(t);
            val += x.F;
            amin(ans,make_pair(val,vector<int>{x.S,j}));
        }
        av[j] = true;
    }   
    if(ans.F>=1e10)
    {
        cout<<"-1\n";return 0;
    }
    cout<<ans.F<<"\n"<<ans.S.size()<<"\n";
    for(auto &j:ans.S)
        cout<<j+1<<" ";
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