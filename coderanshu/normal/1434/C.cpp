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

int _runtimeTerror_()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a > b*c)
    {
    	cout<<"-1\n";return 0;
    }
    if(c < d)
    {
    	cout<<a<<"\n";return 0;
    }
    ll lo = 1,hi = (c+d-1)/d;
    auto f = [&](ll x)
    {
    	return x*a - x*(x-1)/2*b*d;
    };
    ll ans = a;
    while(hi-lo>=3)
    {
    	ll m1 = lo + (hi-lo)/3, m2 = lo + 2*(hi-lo)/3;
    	amax(ans,f(m1));
    	amax(ans,f(m2));
    	if(f(m1)<f(m2))
    		lo = m1 + 1;
    	else if(f(m2)<f(m1))
    		hi = m2-1;
    	else
    		lo = m1+1,hi = m2-1;
    }
    for(;lo<=hi;++lo)
    	amax(ans,f(lo));
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}