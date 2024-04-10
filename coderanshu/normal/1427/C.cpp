#include<bits/stdc++.h>
using namespace std ;

#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
#define popcount(x) __builtin_popcountll(x)
#define pll pair<ll,ll> 
#define ld long double

const int M=1000000007;
const int MM=998244353;
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

ll dp[N];
ll pfx[N];

ll l[N],r[N],t[N];

int _runtimeTerror_()
{
    ll n,R;
    cin>>R>>n;
    t[0] = 0;
    l[0] = r[0] = 1;
    ll ans = 0;
    dp[0] = 0;
    pfx[0] = 0;
    for(int i=1;i<=n;++i)
        cin>>t[i]>>l[i]>>r[i];
    for(int i=1;i<=n;++i)
    {
        dp[i] = -1;

        for(int cnt = 0,j=i-1;j>=0 && cnt<1000;++cnt,--j)
        {
            if(dp[j]==-1)
                continue;
            ll time = t[i]-t[j];
            ll dis = abs(l[i]-l[j])+abs(r[i]-r[j]);
            if(dis<=time)
                amax(dp[i],1+dp[j]);
        }
        if(i>1000)
            amax(dp[i],1+pfx[i-1000]);
        pfx[i] = max(pfx[i-1],dp[i]);
        amax(ans,dp[i]);
        // cout<<dp[i]<<" ";
    }
    // cout<<"\n";
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