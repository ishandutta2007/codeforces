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

const int N = 5001;
vector<int> v[N];

ll dp[N][N][2];
ll b;
int c[N],d[N],sub[N];

void dfs(int s,int p)
{
    sub[s] = 1;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            dfs(j,s);
            sub[s] += sub[j];
        }
    }
    int cur = 0;
    dp[s][0][0] = dp[s][0][1] = 0;
    for(auto j:v[s])
    {
        if(j!=p)
        {
            for(int i=cur;i>=0;--i)
            {
                for(int k=sub[j];k>=0;--k)
                {
                    amin(dp[s][i+k][0],dp[s][i][0] + dp[j][k][0]);
                    amin(dp[s][i+k][1],dp[s][i][1] + min(dp[j][k][0],dp[j][k][1]));
                }
            }
            cur += sub[j];
        }
    }
    for(int i=sub[s]-1;i>=0;--i)
        amin(dp[s][i+1][0],dp[s][i][0] + c[s]);
    for(int i=sub[s];i>=1;--i)
        dp[s][i][1] = dp[s][i-1][1] +c[s]-d[s];
}

int _runtimeTerror_()
{
    int n;
    cin>>n>>b;
    cin>>c[1]>>d[1];
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            dp[i][j][0] = dp[i][j][1] = INF;
    for(int i=2;i<=n;++i)
    {
        cin>>c[i]>>d[i];
        int x;
        cin>>x;
        v[i].pb(x),v[x].pb(i);
    }
    dfs(1,0);
    int ans = 0;
    for(int i=1;i<=n;++i)
        if(dp[1][i][0] <= b || dp[1][i][1] <= b)
            ans = i;
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