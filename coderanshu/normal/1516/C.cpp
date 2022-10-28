// Har Har Mahadev
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

const int N = 200005;

int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<int> dp(N),new_dp(N);
    dp[0] = 1;
    vector<int> a(n+1);
    int sum = 0,g = 0;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum += a[i];
        g = __gcd(g,a[i]);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=200000;++j)
        {
            new_dp[j] |= dp[j];
            if(j >= a[i])
                new_dp[j] |= dp[j-a[i]];
        }
        dp = new_dp;
    }
    if((sum%2 == 1) || dp[sum/2] == 0)
    {
        cout<<"0\n";return 0;
    }
    cout<<"1\n";
    for(int i=1;i<=n;++i)
    {
        if((a[i]/g)%2 == 1)
        {
            cout<<i<<"\n";return 0;
        }
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
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}