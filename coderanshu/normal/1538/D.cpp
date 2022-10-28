#include<bits/stdc++.h>
using namespace std ;

#define ll              int 
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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    ll a,b,k;
    cin>>a>>b>>k;
    if(k == 1)
    {
    	if(a == b)
    	{
    		cout<<"No\n";return 0;
    	}
    	if(a % b == 0 || b % a == 0)
    	{
    		cout<<"Yes\n";return 0;
    	}
    	cout<<"No\n";
    	return 0;
    }
    for(ll i=2;i*i<=a;++i)
    {
        if(a % i)
            continue;
    	while(a % i == 0)
    	{
    		--k;
    		a /= i;
    	}
    }
    for(ll i=2;i*i<=b;++i)
    {
        if(b%i)
            continue;
    	while(b % i == 0)
    	{
    		--k;
    		b /= i;
    	}
    }
    if(b != 1)
    	--k;
    if(a != 1)
    	--k;
    if(k <= 0)
    	cout<<"Yes\n";
    else
    	cout<<"No\n";
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