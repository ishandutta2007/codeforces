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
ll dp[N],a[N],pos[N],neg[N];

int dep[N];
int d = 0;

vector<int> lf[N];
int par[N];

void dfs(int s,int p)
{
    par[s] = p;
    amax(d,dep[s]);
    lf[dep[s]].push_back(s);
    for(auto j:v[s])
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
    d = 0;
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)
    {
        v[i].clear();
        lf[i].clear();
        dep[i] = 0;
        dp[i] = 0;
    }
    for(int i=2;i<=n;++i)
    {
        int x;
        cin >> x;
        v[x].pb(i),v[i].pb(x);
    }
    for(int i=2;i<=n;++i)
        cin >> a[i];
    for(int i=1;i<=n;++i)
        pos[i] = -INF,neg[i] = -INF;
    dep[1] = 1;
    dfs(1,0);
    dp[1] = pos[1] = neg[1] = 0;
    vector<ll> mx(n+1,-INF),mn(n+1,INF);
    for(int i=1;i<=n;++i)
        amax(mx[dep[i]],a[i]),amin(mn[dep[i]],a[i]);

    ll ans = 0;
    for(int i=2;i<=d;++i)
    {
        for(auto &j:lf[i])
        {
            // if up is red
            amax(dp[j],dp[par[j]] + max(mx[i-1]-a[par[j]],a[par[j]]-mn[i-1]));
            amax(dp[j],pos[i-1] - a[par[j]]);
            amax(dp[j],neg[i-1] + a[par[j]]);
            amax(ans,dp[j] + max(mx[i]-a[j],a[j]-mn[i]));
            amax(pos[i],dp[j] + a[j]);
            amax(neg[i],dp[j] - a[j]);
        }
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