// Har Har Mahadev
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
ll dp[N][2];
ll l[N],r[N];

void dfs(int s,int p)
{
    dp[s][0] = dp[s][1] = 0;
    for(auto j:v[s])
    {
        if(j == p)
            continue;
        dfs(j,s);
        dp[s][0] += max(abs(l[s]-l[j]) + dp[j][0],dp[j][1] + abs(l[s] - r[j]));
        dp[s][1] += max(abs(r[s] - l[j]) + dp[j][0], dp[j][1] + abs(r[s] - r[j]));
    }
}

int _runtimeTerror_()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        v[i].clear();
    }
    for(int i=1;i<=n;++i)
        cin>>l[i]>>r[i];
    for(int i=0;i<n-1;++i)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y),v[y].push_back(x);
    }
    dfs(1,0);
    // cout<<dp[2][1]<<"\n";
    cout<<max(dp[1][0],dp[1][1])<<"\n";
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