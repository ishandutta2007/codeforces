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
    ll ans = 0;
    vector<ll> x(n),y(n);
    for(int i=0;i<n;++i)
        cin>>x[i]>>y[i];
    map<pair<int,int>,set<double>> mp;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            ll yx = y[j] - y[i], xx = x[j] - x[i];
            if(yx == 0)
                xx = 1;
            if(xx == 0)
                yx = 1;
            if(yx < 0)
                yx *= -1,xx *= -1;
            ll g = __gcd(abs(yx),abs(xx));
            yx /= g, xx /= g;
            if(xx == 0)
                mp[{yx,xx}].insert(x[i]);
            else
            {
                mp[{yx,xx}].insert(y[i] - x[i] * yx * 1.0 / xx);
            }
        }
    }
    ll cnt = 0;
    for(auto &j:mp)
    {
        ans += sz(j.S) * (sz(j.S)-1)/2;
        cnt += sz(j.S);
    }
    ans -= cnt * (cnt-1)/2;
    cout<<-ans<<"\n";
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