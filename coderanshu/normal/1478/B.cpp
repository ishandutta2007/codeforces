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
    int Q,d;
    cin>>Q>>d;
    bitset<101> dp = bitset<101>();
    dp[0] = 1;
    for(int i=1;i<=100;++i)
    {
        bool good = false;
        int x = i;
        while(x)
        {
            if(x%10 == d)
                good = true;
            x /= 10;
        }
        if(good)
            for(int j=1;j<=100;++j)
                dp |= dp << i;
    }
    while(Q--)
    {
        int n;
        cin>>n;
        if(n>100)
            cout<<"YES\n";
        else
            cout<<(dp[n]?"YES":"NO")<<"\n";
    }
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