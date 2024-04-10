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
    vector<int> a(n+1);
    map<int,int> mp;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        ++mp[a[i]];
    }
    for(auto j:mp)
    {
        if(j.S>(n+1)/2)
        {
            cout<<"-1\n";return 0;
        }
    }
    int ans = 0;
    mp.clear();
    int cur = 1;
    int cnt = 0;
    vector<pii> v;
    for(int i=1;i<=n-1;++i)
    {
        if(a[i]==a[i+1])
        {
            v.pb({cur,i});
            if(a[i]==a[cur])
                ++mp[a[i]];
            ++ans;
            cur = i+1;
        }
    }
    if(cur<=n)
        v.pb({cur,n});
    if(a[n]==a[cur])
        ++mp[a[n]];
    int mx = -1,val;
    for(auto j:mp)
    {
        if(j.S>mx)
            val = j.F,mx = j.S;
    }
    for(auto &j:v)
        mx -= (a[j.F]!=val && a[j.S]!=val);
    --mx;
    ans += max(0,mx);
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