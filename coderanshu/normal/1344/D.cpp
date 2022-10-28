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

const int N = 100005;

ll a[N];
ll val[N];
ll ans[N];

int _runtimeTerror_()
{
    int n;
    ll k;
    cin>>n>>k;
    for(int i=1;i<=n;++i)
        cin>>a[i];

    auto calc = [&](ll a,ll delta)
    {
        ll u = a-delta;
        ll lo = 0,hi = 1e9;
        ll ans = 1e9;
        int it = 0;
        while(lo<=hi)
        {
            ++it;
            ll mid = (lo+hi)/2;
            if(3*mid*mid+3*mid+1>u)
                ans = mid,hi = mid-1;
            else
                lo = mid+1;
        }
        assert(it<=33);
        return ans;
    };

    ll lo = -5e18,hi = 5e18;
    ll answ = 0;
    int it = 0;
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        ll u = 0;
        for(int i=1;i<=n;++i)
        {
            val[i] = calc(a[i],mid);
            amin(val[i],a[i]);
            u += val[i];
        }
        if(u>=k)
        {
            answ = 0;
            for(int i=1;i<=n;++i)
            {
               ans[i] = val[i];
               --val[i];
               if(3*val[i]*val[i]+3*val[i]+1==a[i]-mid && u>k)
                    --ans[i],--u;
                answ += ans[i]*(a[i]-ans[i]*ans[i]);
            }
            lo = mid+1;
        }
        else
            hi = mid-1;
        ++it;
        assert(it<=100);
    }
    // cout<<lo<<" "<<"\n";
    cerr<<answ<<"\n";
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
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