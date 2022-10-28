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
    vector<int> ans(n+1,-1);
    vector<ll> h(n+1),w(n+1);
    pll u = {INF,-1};
    for(int i=1;i<=n;++i)
    {
        cin>>h[i]>>w[i];
        if(h[i]>w[i])
            swap(h[i],w[i]);
    }
    vector<pair<ll,pll>> v;
    for(int i=1;i<=n;++i)
        v.pb({h[i],{w[i],i}});
    sort(all(v));
    int cur = 0;
    // for(auto j:v)
        // cout<<j<<"\n";
    for(int i=0;i<n;++i)
    {
        while(cur<n && v[cur].F<v[i].F)
        {
            amin(u,v[cur].S);
            ++cur;
        }
        if(cur<=i && u.F<v[i].S.F)
            ans[v[i].S.S] = u.S;
    }
    v.clear();
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" " ;
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