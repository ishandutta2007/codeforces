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

map<pair<int64_t,int64_t>,bool> dp;

bool go(int64_t a,int64_t b)
{
    if(a > b)
        swap(a,b);
    if(b%a == 0)
        return true;
    if(dp.count({a,b}))
        return dp[{a,b}];
    bool &ans = dp[{a,b}];
    if(!go(b%a,a))
        ans = true;
    else
    {
        if(a & 1)
            ans = ((b-b%a)/a)%2 == 0;
        else
            ans = (((b-b%a)/a%(a+1)) % 2 == 0);
    }
    return ans;
}

int _runtimeTerror_()
{
    int64_t a,b;
    cin>>a>>b;
    if(a == 0 || b == 0)
    {
        cout<<"Second\n";
        return 0;
    }
    dp.clear();
    bool ans = go(a,b);
    cout<<(ans?"First":"Second")<<"\n";
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