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
    vector<int> v(n);
    map<int,vector<int>> mp;
    int ans = n;
    for(int i=0;i<n;++i)
    {
        cin>>v[i];
        mp[v[i]].pb(i+1);
    }
    for(auto &j:mp)
    {
        if(j.S.size()==n)
        {
            ans = 0;break;
        }
        ll u = 0;
        if(j.S[0]!=1)
            ++u;
        if(j.S.back()!=n)
            ++u;
        for(int i=1;i<sz(j.S);++i)
            if(j.S[i]!=j.S[i-1]+1)
                ++u;
        amin(ans,u);
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
    cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}