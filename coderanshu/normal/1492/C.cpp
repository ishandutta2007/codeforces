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
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vector<int> pf(m+1),sf(m+1);
    int cur = 0;
    for(int i=0;i<m;++i)
    {
        while(cur < n && t[i] != s[cur])
        {
            ++cur;
        }
        pf[i+1] = cur;
        ++cur;
    }
    cur = n-1;
    for(int i=m-1;i>=0;--i)
    {
        while(cur >= 0 && t[i] != s[cur])
        {
            --cur;
        }
        sf[i+1] = cur;
        --cur;
    }
    int ans = 0;
    for(int i=1;i<=m-1;++i)
    {
        amax(ans,sf[i+1]-pf[i]);
    }
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