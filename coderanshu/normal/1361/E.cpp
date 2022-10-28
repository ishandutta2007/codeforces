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

const int N = 100005;
vector<int> v[N];

pii back[N];
int dep[N],in[N],cur,out[N],dp[N],par[N];
bool vis[N];

vector<int> t;

void dfs(int s)
{
    t.pb(s);
    vis[s] = true;
    in[s] = cur++;
    dp[s] = 0;
    back[s] = {N,N};
    for(auto j:v[s])
    {
        if(!vis[j])
        {
            dep[j] = dep[s] + 1;
            par[j] = s;
            dfs(j);
            dp[s] += dp[j];
            amin(back[s],back[j]);
        }
        else
        {
            ++dp[s];
            --dp[j];
            amin(back[s],make_pair(dep[j],j));   
        }
    }
    out[s] = cur-1;
}

int _runtimeTerror_()
{
    int n,m;
    cin>>n>>m;
    vector<pii> ed;
    for(int i=1;i<=n;++i)
    {
        v[i].clear();
        back[i] = {N,N};
        dep[i] = 0;
    }
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        ed.pb({x,y});
    }
    auto ancestor = [&](int x,int y)
    {
        return in[y] >= in[x] && in[y] <= out[x];
    };
    //  graph is strongly connected
    int cutoff = 1;
    while(cutoff*5<n)
        ++cutoff;
    vector<bool> checked(n+1,false),interested(n+1,true);
    vector<int> ans;
    for(int it = 0;it<=35;++it)
    {
        int u = rng()%n+1;
        if(checked[u])
            continue;
        for(int i=1;i<=n;++i)
            dep[i] = 0,back[i] = {N,N},in[i] = 0,vis[i] = false,dp[i] = 0,par[i] = 0;
        cur = 0;
        t.clear();
        dfs(u);
        checked[u] = true;
        bool can = true;
        for(auto &j:ed)
        {
            if(j.F == par[j.S] || j.S == par[j.F])
                continue;
            if(!ancestor(j.S,j.F))
            {
                can = false;
                break;
            }
        }
        if(!can)
            continue;
        // done ans here
        interested[u] = true;
        ans.pb(u);
        for(int i=1;i<n;++i)
        {
            if(dp[t[i]]>=2)
            {
                interested[t[i]] = false;
            }
            else
            {
                assert(dp[t[i]] == 1);
                interested[t[i]] = interested[back[t[i]].S];
            }
            if(interested[t[i]])
                ans.pb(t[i]);
        }
        if(sz(ans)<cutoff)
            ans.clear();
        break;
    }
    if(ans.empty())
    {
        cout<<"-1\n";return 0;
    }
    sort(all(ans));
    for(auto j:ans)
        cout<<j<<" ";
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}