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

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif


int _runtimeTerror_()
{
    int a,b;
    cin>>a>>b;
    int xc = 0,yc = 0;
    string s;
    cin>>s;
    for(auto &j:s)
        xc += j == 'R',xc -= j == 'L',yc += j == 'U',yc -= j == 'D';
    ll mv = 0;
    if(xc != 0)
        mv = a / xc;
    else if(yc != 0)
        mv = b/yc;
    debug(mv);
    auto complete = [&](ll tmp)
    {
        amax(tmp,0);
        ll x = tmp * xc,y = tmp * yc;
        if(x == a && y == b)
            return true;
        for(auto &j:s)
        {
            x += j == 'R',x -= j == 'L',y += j == 'U',y -= j == 'D';
            if(x == a && y == b)
                return true;
        }
        return false;
    };
    for(int i=mv-1000;i<=mv+1000;++i)
    {
        if(complete(i))
        {
            cout<<"Yes\n";return 0;
        }
    }
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
    // cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}