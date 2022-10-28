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
#define double             long double

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
    double c,m,p,v;
    cin >> c >> m >> p >> v;
    const double eps = 1e-9;
    map<pair<double,double>,double> dp;
    function<double(double,double)> dfs = [&](double c,double m)
    {
        if(abs(c) < eps && abs(m) < eps)
            return (double)1.0;
        if(dp.count({c,m}))
            return dp[{c,m}];
        double ans = 0;
        ans += (1 - c - m); 
        if(abs(c) > eps)
        {
            if(c <= v)
            {
                if(abs(m) > eps)
                    ans += c * (1 + dfs(0,m+c/2));
                else
                    ans += c * (1 + dfs(0,0));
            }
            else
            {
                if(abs(m) > eps)
                    ans += c * (1 + dfs(c - v,m + v/2));
                else
                    ans += c * (1 + dfs(c - v,0));
            }
        }
        if(abs(m) > eps)
        {
            if(m <= v)
            {
                if(abs(c) > eps)
                    ans += m * (1 + dfs(c + m/2,0));
                else
                    ans += m * (1 + dfs(0,0));
            }
            else 
            {
                if(abs(c) > eps)
                    ans += m * (1 + dfs(c + v/2,m-v));
                else
                    ans += m * (1 + dfs(0,m-v));
            }
        }
        return dp[{c,m}] = ans;
    };
    cout << fixed << setprecision(10);
    cout << dfs(c,m) << "\n";
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