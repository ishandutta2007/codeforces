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

const int N = 3005;

ll a[N][N];
ll sz[N];
ll sum[N];
int n,k;
ll ans = -INF;

void apply(vector<ll> &dp,int idx)
{
    for(int i=k;i>=sz[idx];--i)
        amax(dp[i],dp[i-sz[idx]] + sum[idx]);
}

void go_(vector<ll> dp,int l,int r)
{
    if(l==r)
    {
        for(int i=1;i<=sz[l];++i)
            amax(dp[k],dp[k-i] + a[l][i]);
        amax(ans,dp[k]);
        return ;
    }
    vector<ll> dp2 = dp;
    int mid = (l+r)/2;
    for(int i=l;i<=mid;++i)
        apply(dp,i);
    go_(dp,mid+1,r);
    dp = dp2;
    for(int i=mid+1;i<=r;++i)
        apply(dp,i);
    go_(dp,l,mid);
}

int _runtimeTerror_()
{
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    {
        cin>>sz[i];
        for(int j=1;j<=sz[i];++j)
        {
            int x;
            cin>>x;
            if(j<N)
                a[i][j] = a[i][j-1] + x;
        }
        amin(sz[i],k);
        sum[i] = a[i][sz[i]];
    }
    vector<ll> dp(k+1,-INF);
    dp[0] = 0;
    go_(dp,1,n);
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