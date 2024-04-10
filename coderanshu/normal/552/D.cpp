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
    vector<int> x(n+1),y(n+1);
    for(int i=1;i<=n;++i)
        cin>>x[i]>>y[i];
    ll ans = 0;
    map<pair<int,int>,int> g;
    for(int i=1;i<=n;++i)
    {
        g.clear();
        for(int j=1;j<=n;++j)
        {
            if(j == i)
                continue;
            int yx = y[j] - y[i],xx = x[j] - x[i];
            if(yx < 0)
                yx *= -1,xx *= -1;
            if(yx == 0)
                xx = 1;
            if(xx == 0)
                yx = 1;
            int gcd = __gcd(abs(yx),abs(xx));
            yx /= gcd,xx /= gcd;
            ++g[{yx,xx}];
        }
        for(auto &j:g)
            ans += j.S * (n-j.S-1);
    }
    assert(ans % 6 == 0);
    ans /= 6;
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