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
    int ans = 0;
    vector<ll> a(n+1);
    map<int,int> mp;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ++mp[a[i]%m];
    }
    if(mp.count(0))
        mp.erase(0),++ans;
    if(m%2 == 0 && mp.count(m/2))
        mp.erase(m/2),++ans;
    while(!mp.empty())
    {
        auto u = *mp.begin();
        int x = (m-u.F)%m;
        mp.erase(mp.begin());
        if(!mp.count(x))
        {
            ans += u.S;
            continue;
        }
        ++ans;
        if(abs(u.S-mp[x])>1)
            ans += abs(u.S-mp[x])-1;
        mp.erase(x);
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