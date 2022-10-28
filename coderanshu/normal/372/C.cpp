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

const int N = 150005,NN = 302;

int a[NN],b[NN],t[NN];

ll dp[2][N];

int _runtimeTerror_()
{
    int n,m,d;
    cin>>n>>m>>d;
    for(int i=1;i<=m;++i)
        cin>>a[i]>>b[i]>>t[i];

    t[0] = 1;
    ll ans = 0;
    for(int i=1;i<=m;++i)
    {
        ll dt = (t[i]-t[i-1])*1LL*d;

        deque<int> dq;

        int r = 1,l = 1;
        auto add = [&](int x)
        {
            while(!dq.empty() && dp[(i-1)%2][dq.back()] <= dp[(i-1)%2][x])
                dq.pop_back();
            dq.push_back(x);
        };
        for(int j=1;j<=n;++j)
        {
            while(r<=n && r<=j+dt)
            {
                add(r++);
            }
            while(!dq.empty() && dq.front()<j-dt)
                dq.pop_front();
            // assert(!dq.empty());
            dp[i%2][j] = dp[(i-1)%2][dq.front()] - abs(a[i]-j);
        }
        ans += b[i];
    }
    ll val = -INF;
    for(int i=1;i<=n;++i)
        amax(val,dp[m%2][i]);
    ans += val;
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