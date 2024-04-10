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

int _runtimeTerror_()
{
    int n,k;
    cin>>n>>k;
    ll lo = 1,hi = n+1,ans = 1;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i)
        cin>>a[i];

    auto f = [&](ll x)
    {
        vector<int> sum(n+1,0);
        int mn = 0;
        for(int i=1;i<=n;++i)
        {
            sum[i] = sum[i-1] + (a[i]>=x?1:-1);
            // cout<<sum[i]<<" ";
        }
        // cout<<"\n";
        int cur = 0;
        for(int i=k;i<=n;++i)
        {
            while(i-cur>=k)
                amin(mn,sum[cur]),++cur;
            if(mn < sum[i])
                return true;
        }
        return false;
    };  
    // cout<<f(3)<<"\n";
    while(lo<=hi)
    {
        ll mid = (lo+hi)/2;
        if(f(mid))
            lo = mid+1,ans = mid;
        else
            hi = mid-1;
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}