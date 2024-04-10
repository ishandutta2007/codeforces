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
    vector<ll> a(n+3);
    ll sum = 0;
    map<ll,ll> mp;
    for(int i=1;i<=n+2;++i)
    {
        cin>>a[i];
        sum += a[i];
        ++mp[a[i]];
    }
    for(int i=1;i<=n+2;++i)
    {
        // x is this
        ll u = sum - a[i];
        if(u % 2)
            continue;
        u /= 2;
        --mp[a[i]];
        if(mp[a[i]] == 0)
            mp.erase(a[i]);
        if(mp.count(u))
        {
            --mp[u];
            for(auto &j:mp)
            {
                for(int k=0;k<j.S;++k)
                    cout<<j.F<<" ";
            }
            cout<<"\n";return 0;
        }
        ++mp[a[i]];
    }
    cout<<"-1\n";
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