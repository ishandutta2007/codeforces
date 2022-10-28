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
    vector<ll> ans(n+10,0),u(n+1),s(n+1);
    ll sum = 0;
    vector<vector<ll>> g(n+1);
    for(int i=1;i<=n;++i)
        cin>>u[i];
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        g[u[i]].push_back(s[i]);
        sum += s[i];
    }
    for(int i=1;i<=n;++i)
    {
        sort(all(g[i]),greater<ll>());
        int sz = sz(g[i]);
        vector<ll> psum(sz+1,0);
        for(int j=1;j<=sz;++j)
            psum[j] = psum[j-1] + g[i][j-1];
        for(int j=2;j<=sz;++j)
        {
            if(sz%j == 0)
                continue;
            int rem = sz%j;
            ans[j] += psum[sz] - psum[sz-rem];
            ans[j+1] -= psum[sz] - psum[sz-rem];
        }
        ans[sz+1] += psum[sz];
    }
    for(int i=1;i<=n;++i)
    {
        ans[i] += ans[i-1];
        cout<<sum-ans[i]<<" ";
    }
    cout<<"\n";
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