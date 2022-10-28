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

const int N = 1005;

int n,m;

double dp[N][N][2];

int a[N];

int _runtimeTerror_()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            dp[i][j][1] = a[i]>a[j],dp[i][j][0] = a[j]>a[i];
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        if(x>y)
            swap(x,y);
        dp[x][y][1] = dp[x][y][0] = (dp[x][y][0] + dp[x][y][1])/2;
        for(int i=1;i<x;++i)
        {
            dp[i][x][1] = dp[i][y][1] = (dp[i][x][1]/2 + dp[i][y][1]/2);
            dp[i][x][0] = dp[i][y][0] = (dp[i][x][0]/2 + dp[i][y][0]/2);
        }
        for(int i=y+1;i<=n;++i)
        {
            dp[x][i][1] = dp[y][i][1] = (dp[x][i][1] + dp[y][i][1])/2;
            dp[x][i][0] = dp[y][i][0] = (dp[x][i][0] + dp[y][i][0])/2;
        }
        for(int i=x+1;i<y;++i)
        {
            dp[x][i][1] = dp[i][y][0] = (dp[x][i][1]/2 + dp[i][y][0]/2);
            dp[x][i][0] = dp[i][y][1] = (dp[x][i][0]/2 + dp[i][y][1]/2);
        }
    }
    double ans = 0;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            ans += dp[i][j][1];
    cout<<fixed<<setprecision(10);
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