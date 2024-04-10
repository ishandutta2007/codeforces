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
    int n;
    cin>>n;
    map<pair<pll,ll>,ll> mp;
    ll ans = 0;
    vector<ll> x(n),y(n);
    for(int i=0;i<n;++i)
        cin>>x[i]>>y[i];
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int yx = y[j] - y[i],xx = x[j] - x[i];
            ll dis = yx * 1ll * yx + xx * 1ll * xx;
            if(yx == 0)
                xx = 1;
            else if(xx == 0)
                yx = 1;
            if(yx < 0)
                yx *= -1,xx *= -1;
            int g = __gcd(abs(yx),abs(xx));
            yx /= g, xx /= g;
            ++mp[{{yx,xx},dis}];
        }
    }
    for(auto &j:mp)
        ans += j.S * (j.S - 1)/2;
    ans /= 2;
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