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

vector<int> v[N];
int dep[N],dp[N];
int ans;

void dfs_(int s,int p)
{   
    if(sz(v[s]) == 1 && s!=1)
    {
        dp[s] = dep[s];
        return ;
    }
    dp[s] = 1e9;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dep[j] = dep[s] + 1;
            dfs_(j,s);
            amin(dp[s],dp[j]);
        }
    }
}

void dfs(int s,int p)
{
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dfs(j,s);
            if(s!=1)
                amax(ans,dp[j]-dep[s]+1);
        }
    }
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        dp[i] = 1e9;
        v[i].clear();
    }
    ans = 0;
    dep[1] = 0;
    for(int i=1;i<=n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y),v[y].pb(x);
    }
    dfs_(1,0);
    dfs(1,0);
    // for(int i=1;i<=n;++i)
        // cout<<dp[i]<<" ";
    // cout<<"\n";
    vector<int> u;
    for(auto j:v[1])
        u.pb(dp[j]);
    if(sz(u)==1)
        amax(ans,u[0]);
    sort(all(u),greater<ll>());
    if(sz(u)>1)
    {
        if(u[0]==u[1])
            ++u[0];
        amax(ans,u[0]);
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}